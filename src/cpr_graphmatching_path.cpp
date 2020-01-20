//#include <cassert>        // assert(eg == esim.sourceEdgeIndex.at(edge_g_itr->first));
//#include <stdexcept>    // std::out_of_range

// #include <CGAL/QP_models.h>     // quadratic programming
// #include <CGAL/QP_functions.h>
// #include <CGAL/MP_Float.h>
// typedef CGAL::MP_Float ET;

#include <cstdlib>  // malloc, free
#include <cstring>  // memcpy, memset

#include "cpr_graphmatching.h"
#include "cpr_graphmatching_path.h"

GraphMatchingPath::GraphMatchingPath(MatrixDouble const *vsim, EdgeSimilarityMatrix const *esim, MatrixInt const *g_adj, MatrixInt const *h_adj)
  : GraphMatching(vsim, esim, g_adj, h_adj),
  ng(g_adj->rows()), nh(h_adj->rows()), x_len(ng * nh), nb_constraints(ng + nh)
{
  //assert(ng = nh);    // is that necessary?

  x = (double *) malloc(x_len * sizeof(*x));
  y = (double *) malloc(x_len * sizeof(*y));
  xD = (double *) malloc(x_len * sizeof(*xD));

  cons_coeff_rowindex.push_back(1);   // duplicate coeff at pos 0 and pos 1 because apparently these three vectors should be 1-indexed??
  cons_coeff_colindex.push_back(1);
  cons_coeff_value.push_back(1.0);
  // stochasticity constraints: forall ig, sum_(ih) x(ig,ih) = 1
  for (std::size_t ig = 0; ig < ng; ++ig)
    for (std::size_t ih = 0; ih < nh; ++ih)
    {
      cons_coeff_rowindex.push_back(ig+1);    // 1-indexed int
      cons_coeff_colindex.push_back(ig * nh + ih + 1);
      cons_coeff_value.push_back(1.0);
    }
  // stochasticity constraints: forall ih, sum_(ig) x(ig,ih) = 1
  for (std::size_t ih = 0; ih < nh; ++ih)
    for (std::size_t ig = 0; ig < ng; ++ig)
    {
      cons_coeff_rowindex.push_back(ng+1+ih);    // continue from last row index
      cons_coeff_colindex.push_back(ig * nh + ih + 1);
      cons_coeff_value.push_back(1.0);
    }
  initSimplex(cons_coeff_rowindex, cons_coeff_colindex, cons_coeff_value);
}

GraphMatchingPath::~GraphMatchingPath()
{
  free(x);
  free(y);
  free(xD);
}

void GraphMatchingPath::run()
{
  // Initialisation
  double lambda;
  double lambda_new;
  MatrixDouble p(ng, nh);
  MatrixDouble p_new(ng, nh);

  lambda = 0;
  frankWolfe(lambda, &p, &p);

  double dlambda = 0.1;  // TODO find correct value
  double epsilon = 0.1;  // TODO find correct value

  // Cycle over lambda
  while (lambda < 1.0)
  {
    lambda_new = lambda + dlambda;
    if (abs(f(lambda_new, &p) - f(lambda, &p)) < epsilon)
    {
      lambda = lambda_new;
    }
    else
    {
      frankWolfe(lambda, &p_new, &p);   // maybe remove p argument and do memcpy(p_new, p) before call to frankWolfe()
      lambda = lambda_new;
    }
  }
  // Output
  // when lambda == 1, all coeffs in p must be 0.0 or 1.0
  // copy p into this->matching and convert double to int
}

double GraphMatchingPath::f_smooth(MatrixDouble const *p) const
{
  double result = 0;       // result = - sum_{edge e in G} esim(e, matched(e)) / (nG * nH)
  unsigned int eg = 0;  // index of edge in G
  for (auto edge_g_itr = esim->sourceEdgeIndex.cbegin(); edge_g_itr != esim->sourceEdgeIndex.cend(); ++edge_g_itr)
  {
    assert(eg == esim->sourceEdgeIndex.at(edge_g_itr->first));
    unsigned int mapped_vertex_1, mapped_vertex_2;
    for (
      mapped_vertex_1 = 0;
      mapped_vertex_1 < p->cols() && (*p)(edge_g_itr->first.first, mapped_vertex_1) == 0;
      ++mapped_vertex_1)
      ;
    for (
      mapped_vertex_2 = 0;
      mapped_vertex_2 < p->cols() && (*p)(edge_g_itr->first.second, mapped_vertex_2) == 0;
      ++mapped_vertex_2)
      ;
    auto edgeToIndex_h_itr = esim->destEdgeIndex.find(std::make_pair(mapped_vertex_1, mapped_vertex_2));
    if (edgeToIndex_h_itr != esim->destEdgeIndex.end())  // if edge in G mapped to edge in H
      result -= esim->m(eg, edgeToIndex_h_itr->second);
    else          // if edge in G not mapped to an edge in H
      result -= 1.0; // this is the worst possible penalty, since esim->m is normalized
  }
  result /= x_len;   // result = result / (ng * nh)
  return result;
}

double GraphMatchingPath::f(double lambda, MatrixDouble const *p) const
{
  (void) lambda;
  (void) p;
  return 0;   // TODO probably an accessor to an attribute that was updated by frankWolfe()
}

void print_x(char const *name, double *x, std::size_t width, std::size_t height)
{
  std::cout << "Printing solution " << name << std::endl;
  for (std::size_t row = 0; row < height; ++row)
  {
    for (std::size_t col = 0; col < width; ++col)
      std::cout << x[row * width + col] << ' ';
    std::cout << std::endl;
  }
}

void GraphMatchingPath::frankWolfe(double lambda, MatrixDouble *x_return, MatrixDouble const *x_start)
{
  // assert x basic feasible
  memcpy(x, x_start->data(), x_len * sizeof(*x));
  memcpy(y, x, x_len * sizeof(*x)); // y = x

  double mu = 1.0;    // initialise with arbitrary nonzero
  double yDy = 1.0;   // initialise with arbitrary nonzero
  while (yDy != 0 && mu != 0) // TODO find correct stop criterion    //(zz != 0)
  {
    //print_x("x", x, nh, ng);   // debug
    //print_x("y", y, nh, ng);   // debug
    double xDy = simplex();  // y = argmax x^T D y, A y = 1, 0 <= y <= 1
    double xDx = mult_xD(x);
    yDy = bilinear(y, y);
    // be careful with sign of mu and maximize/minimize in lp??
    mu = -(xDx - xDy) / (yDy - xDy - xDy + xDx); // at this point xDy is known.
    //double mu = 0; // TODO solve for mu    // mu = (ww - wz) / (zz - wz - wz + ww);
    // pcl::console::print_info("    xDx: %f == %f\n", xDx, bilinear(x,x));
    // pcl::console::print_info("    xDy: %f == %f\n", xDy, bilinear(x,y));
    // pcl::console::print_info("    yDx:          == %f\n", bilinear(y,x));
    // pcl::console::print_info("    yDy: %f == %f\n", yDy, bilinear(y,y));
    // pcl::console::print_info("    mu:  %f\n", mu);
    if (mu >= 1.0)
      memcpy(x, y, x_len * sizeof(*y)); // x = y
    else if (mu < 0)
    {
      assert(yDy == 0);
      //pcl::console::print_highlight("NEGATIVE MU!!!!!\n");
      //pcl::console::print_info("    mu: %f\n", mu);
    }
    else
      setXTo1minusMuXPlusMuY(mu); // x = (1 - mu) * x + mu * y;
  }
  memcpy(x_return->data(), y, x_len * sizeof(double)); // TODO remove memcpy and make x_return->data() point to z
}     // in their paper, frank-wolfe returns y instead of x, which seems consistent with their stop criterion.

void GraphMatchingPath::setXTo1minusMuXPlusMuY(double mu)  // x = (1 - mu) * x + mu * y;
{
  for (std::size_t i = 0; i < x_len; ++i)
    x[i] = (1.0 - mu) * x[i] + mu * y[i];
}

#include <glpk.h>

void GraphMatchingPath::initSimplex(std::vector<int> const &iv, std::vector<int> const &jv, std::vector<double> const &av)
{
  // declare linear problem object
  lp = glp_create_prob();
  glp_set_prob_name(lp, "linear approximation");

  // declare objective: maximize
  glp_set_obj_dir(lp, GLP_MAX);

  // declare number of constraints and variables
  glp_add_rows(lp, nb_constraints);
  glp_add_cols(lp, x_len);

  // variables are nonnegative (and at most 1) and 1-indexed in glp
  for (std::size_t col = 1; col <= x_len; ++col)
    glp_set_col_bnds(lp, col, GLP_DB, 0.0, 1.0);  // 0 <= x[.] <= 1

  // load constraints
  pcl::console::print_info("glp_load_matrix with %u nonzero constraint coeffs.\n", iv.size()-1);
  glp_load_matrix(lp, iv.size()-1, iv.data(), jv.data(), av.data());
  for (std::size_t row = 0; row < nb_constraints; ++row)
    glp_set_row_bnds(lp, row + 1, GLP_DB, 0.0, 1.0);    // row is 1-indexed
}

void print_simplex(glp_prob *lp, int ng, int nh)
{
  // print constraints
  pcl::console::print_info("constraints:\n");
  int ind[7];       // must be at least max(ng,nh)+1
  double coef[31];  // must be at least ng*nh+1
  ind[0] = 43; coef[0] = 43.0;  // cell [0] is never used because everything in the glp library is 1-indexed :-(
  for (int row = 1; row <= ng+nh; ++row)
  {
    int nb_nonzero = glp_get_mat_row(lp, row, ind, coef);
    int rowtype = glp_get_row_type(lp, row);
    double rhs = glp_get_row_ub(lp, row);
    assert(ind[0] == 43);
    assert(coef[0] == 43.0);
    if ((row-1) < ng && nb_nonzero != nh)
      pcl::console::print_info("Wrong number of nonzero coeffs for constraint %d!! (has %d, should have %d = nh)\n", row, nb_nonzero, nh);
    else if ((row-1) >= ng && nb_nonzero != ng)
      pcl::console::print_info("Wrong number of nonzero coeffs for constraint %d!! (has %d, should have %d = ng)\n", row, nb_nonzero, ng);
    pcl::console::print_info("%.2f * x%02d", coef[1], ind[1]-1);
    for (int col = 2; col <= 5; ++col)
      pcl::console::print_info(" + %.2f * x%02d", coef[col], ind[col]-1);
    assert(rowtype == GLP_DB);
    pcl::console::print_info(" <= %.2f\n", rhs);
  }
  pcl::console::print_info("objective:\n");
  assert(glp_get_obj_dir(lp) == GLP_MAX);
  for (int j = 1; j <= ng*nh; ++j)
    coef[j] = glp_get_obj_coef(lp, j);
  pcl::console::print_info    ("Maximize  %.2f x%02d", coef[1], 0);
  int j = 2;
  for (int k = nh; k <= ng*nh; k += nh)
  {
    for (; j <= k; ++j)
      pcl::console::print_info(" + %.2f x%02d", coef[j], j-1);
    pcl::console::print_info("\n       ");
  }
  pcl::console::print_info("\n");
}

// update z to minimise W~ * Z
double GraphMatchingPath::simplex(void)
{
  static std::size_t nb_calls = 0;
  pcl::console::print_info("simplex call %u\n", nb_calls);
  // if (nb_calls > 5)
  //   exit(3);    // for debug
  ++nb_calls;

  // reset objective function
  // load objective function
  compute_lp_obj_coeffs(lp);

  // print_simplex(lp, ng, nh);

  // solve problem
  glp_simplex(lp, NULL);

  // update vector y with variables from the solution!!
  setYToSolutionOfLP(lp);

  // retrieve optimal objective value
  return (glp_get_obj_val(lp));
}


void GraphMatchingPath::compute_lp_obj_coeffs(glp_prob *lp)
{
  // start from 0
  memset(xD, 0, x_len * sizeof(*xD));
  // add edge related rewards
  for (auto edge_g : esim->sourceEdgeIndex)
  {
    for (auto edge_h : esim->destEdgeIndex)
    {
      std::size_t kx = edge_g.first.first * nh + edge_h.first.first;
      std::size_t ky = edge_g.first.second * nh + edge_h.first.second;
      xD[ky] += x[kx] * esim->m(edge_g.second, edge_h.second);
      //glp_set_obj_coef(lp, ky+1, x[kx] * esim->m(edge_g.second, edge_h.second))
    }
  }
  // add vertex related rewards
  for (KeyT ig = 0; ig < ng; ++ig)
    for (KeyT ih = 0; ih < nh; ++ih)
      xD[ig * nh + ih] += x[ig * nh + ih] * (*vsim)(ig, ih);
      //glp_set_obj_coef(lp, ig * nh + ih + 1, x[ig * nh + ih] * (*vsim)(ig, ih));
  // send results to glpk
  for (std::size_t ky = 0; ky < x_len; ++ky)
    glp_set_obj_coef(lp, static_cast<int>(ky) + 1, xD[ky]);   // int 1-indexed

  //std::cout << "Objective coeffs:" << std::endl;
  //for (KeyT ig = 0; ig < ng; ++ig)
  //{
  //  for (KeyT ih = 0; ih < nh; ++ih)
  //    std::cout << xD[ig * nh + ih] << ' ';
  //  std::cout << std::endl;
  //}
}

double GraphMatchingPath::mult_xD(double *z)  // should be glp_prob const *lp
{
  double result = 0;
  for (std::size_t k = 0; k < x_len; ++k)
    result += xD[k] * z[k];
  return result;
}

// compute x D y
double GraphMatchingPath::bilinear(double *x, double *y)
{
  double result = 0;
  for (auto edge_g : esim->sourceEdgeIndex)
  {
    for (auto edge_h : esim->destEdgeIndex)
    {
      std::size_t kx = edge_g.first.first * nh + edge_h.first.first;
      std::size_t ky = edge_g.first.second * nh + edge_h.first.second;
      result += x[kx] * y[ky] * esim->m(edge_g.second, edge_h.second);
    }
  }
  for (KeyT ig = 0; ig < ng; ++ig)
    for (KeyT ih = 0; ih < nh; ++ih)
      result += x[ig * nh + ih] * y[ig * nh + ih] * (*vsim)(ig, ih);

  return result; // = sum_(jg,jh) (sum_(ig,ih) x[ig,ih] D[(ig,ih)(jg,jh)]) y[jg,jh]
}

// set y to solution of solved lp
void GraphMatchingPath::setYToSolutionOfLP(glp_prob *lp)  // should be glp_prob const *lp but library wants it non-const for no reason
{
  for (std::size_t j = 0; j < x_len; ++j)
    y[j] = glp_get_col_prim(lp, static_cast<int>(j + 1));  // library wants int, 1-indexed
}