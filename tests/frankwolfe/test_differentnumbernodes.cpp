#include <iostream>   // std::cout
#include <iomanip>    // std::fixed, std::setprecision to print doubles/floats

#include "cpr_graphmatching_path.h"
#include "cpr_matrices.h"
#include "cpr_main.h"

void testdifferent_fill_adjacency_matrices(MatrixInt &src_adj, MatrixInt &dst_adj)
{
  // house with 5 nodes and 7 edges
  //   0
  // 4  /1
  // 3/  2
  src_adj << 0, 1, 0, 0, 1,  // roof
             1, 0, 1, 1, 0,  // topright
             0, 1, 0, 1, 0,  // bottomright
             0, 1, 1, 0, 1,  // bottomleft
             1, 1, 0, 1, 0;  // topleft

  // house+tail with 6 nodes and 8 edges
  //   0
  // 5  /1
  // 4/  2 _ 3
  dst_adj << 0, 1, 0, 0, 0, 1,  // roof
             1, 0, 1, 0, 1, 1,  // topright
             0, 1, 0, 1, 1, 0,  // bottomright
             0, 0, 1, 0, 0, 0,  // tail
             0, 1, 1, 0, 0, 1,  // bottomleft
             1, 1, 0, 0, 1, 0;  // topleft
}

// fill src_esf[0,1,2,3,4] with pseudo-random numbers in [0, 1]
// fill dst_esf[0,1,2,4,5] with a small perturbation of src_esf
// dst_esf[3] = pseudo-random
void testdifferent_fill_esf_descr(ESFDescriptors &src_esf, ESFDescriptors &dst_esf)
{
  int random = 197546;

  // src[0,1,2,3,4]
  for (KeyT i_src = 0; i_src < 5; ++i_src)
  {
    for (std::size_t j = 0; j < 640; ++j)
    {
      random = (random * 7 + 19 + i_src + j) % 31;
      // src = pseudo-random in [0, 1]
      src_esf[i_src].push_back(static_cast<float>(random) / 30.0f);
    }
  }

  // dst[0,1,2,4,5]
  for (KeyT i_dst = 0; i_dst < 6; ++i_dst)
  {
    KeyT i_src = (i_dst <= 2 ? i_dst : i_dst - 1);  // src 0 1 2 3 4 -> dst 0 1 2 4 5
    for (std::size_t j = 0; j < 640; ++j)
    {
      random = (random * 7 + 19 + i_dst + j) % 31;
      // dst = src + pseudo-random in [-0.02, 0.02]
      dst_esf[i_dst].push_back(src_esf[i_src][j] + (static_cast<float>(random) / (30.0f * 25.0f) - 0.02f));
    }
  }

  // dst[3]
  for (std::size_t j = 0; j < 640; ++j)
  {
    random = (random * 7 + 19 + 3 + j) % 31;
  // dst[3] = pseudo_random in [0,1]
    dst_esf[3][j] = (static_cast<float>(random) / 30.0f);
  }
}

void testdifferent_fill_edge_descr(EdgeDescriptors &src_ed, EdgeDescriptors &dst_ed)
{
  src_ed[std::make_pair(0,1)] = std::make_tuple(3.14/4.0, 3.14/4.0, 0, 1.4);
  src_ed[std::make_pair(1,2)] = std::make_tuple(0.0, 3.14/2.0, 0, 1.0);
  src_ed[std::make_pair(2,3)] = std::make_tuple(3.14/2.0, 0, 0, 1.0);
  src_ed[std::make_pair(3,4)] = std::make_tuple(0, 3.14/2.0, 0, 1.0);
  src_ed[std::make_pair(4,0)] = std::make_tuple(3.0 * 3.14/4.0, -3.14/4.0, 0, 1.4);
  src_ed[std::make_pair(1,4)] = std::make_tuple(3.14/2.0, 0, 0, 1.0);
  src_ed[std::make_pair(1,3)] = std::make_tuple(3.0 * 3.14/4.0, -3.14/4.0, 0, 1.4);

  src_ed[std::make_pair(1,0)] = src_ed[std::make_pair(0,1)];  // right roof
  src_ed[std::make_pair(2,1)] = src_ed[std::make_pair(1,2)];  // right wall
  src_ed[std::make_pair(3,2)] = src_ed[std::make_pair(2,3)];  // floor
  src_ed[std::make_pair(4,3)] = src_ed[std::make_pair(3,4)];  // left wall
  src_ed[std::make_pair(0,4)] = src_ed[std::make_pair(4,0)];  // left roof
  src_ed[std::make_pair(4,1)] = src_ed[std::make_pair(1,4)];  // ceiling
  src_ed[std::make_pair(3,1)] = src_ed[std::make_pair(1,3)];  // diagonal

  dst_ed[std::make_pair(0,1)] = std::make_tuple(3.14/4.0, 3.14/4.0, 0, 1.4);
  dst_ed[std::make_pair(1,2)] = std::make_tuple(0.0, 3.14/2.0, 0, 1.0);
  dst_ed[std::make_pair(2,4)] = std::make_tuple(3.14/2.0, 0, 0, 1.0);
  dst_ed[std::make_pair(4,5)] = std::make_tuple(0, 3.14/2.0, 0, 1.0);
  dst_ed[std::make_pair(5,0)] = std::make_tuple(3.0 * 3.14/4.0, -3.14/4.0, 0, 1.4);
  dst_ed[std::make_pair(1,5)] = std::make_tuple(3.14/2.0, 0, 0, 1.0);
  dst_ed[std::make_pair(1,4)] = std::make_tuple(3.0 * 3.14/4.0, -3.14/4.0, 0, 1.4);

  dst_ed[std::make_pair(1,0)] = dst_ed[std::make_pair(0,1)];  // right roof
  dst_ed[std::make_pair(2,1)] = dst_ed[std::make_pair(1,2)];  // right wall
  dst_ed[std::make_pair(4,2)] = dst_ed[std::make_pair(2,4)];  // floor
  dst_ed[std::make_pair(5,4)] = dst_ed[std::make_pair(4,5)];  // left wall
  dst_ed[std::make_pair(0,5)] = dst_ed[std::make_pair(5,0)];  // left roof
  dst_ed[std::make_pair(5,1)] = dst_ed[std::make_pair(1,5)];  // ceiling
  dst_ed[std::make_pair(4,1)] = dst_ed[std::make_pair(1,4)];  // diagonal

  dst_ed[std::make_pair(2,3)] = std::make_tuple(3.14/2.0, 0, 0, 1.0);
  dst_ed[std::make_pair(3,2)] = dst_ed[std::make_pair(2,3)];  // tail
}

void test_5nodes_with_6nodes()
{
  int const ng = 5; // src graph has 5 nodes
  int const nh = 6; // dst graph has 6 nodes
  ESFDescriptors  src_esf;
  ESFDescriptors  dst_esf;
  testdifferent_fill_esf_descr(src_esf, dst_esf);

  EdgeDescriptors src_ed;
  EdgeDescriptors dst_ed;
  testdifferent_fill_edge_descr(src_ed, dst_ed);

  MatrixInt src_adj(ng,ng);
  MatrixInt dst_adj(nh,nh);
  testdifferent_fill_adjacency_matrices(src_adj, dst_adj);

  VertexSimilarityMatrix vsim_mat(src_esf, dst_esf);
  EdgeSimilarityMatrix esim_mat(src_ed, dst_ed);

  MatrixDouble other_vsim(ng,nh);
  other_vsim << 0.95, 0.07, 0.07, 0.20, 0.07, 0.07,
                0.07, 0.95, 0.07, 0.20, 0.07, 0.07,
                0.07, 0.07, 0.95, 0.20, 0.07, 0.07,
                0.07, 0.07, 0.07, 0.20, 0.95, 0.07,
                0.07, 0.07, 0.07, 0.20, 0.07, 0.95; // almost identity matrix

  std::cout << std::fixed << std::setprecision(4);
  std::cout << "Vertex similarity matrix:" << std::endl;
  std::cout << vsim_mat.m << std::endl << std::endl;
  std::cout.unsetf(std::ios_base::floatfield);
  std::cout << std::setprecision(1);
  std::cout << "Edge similarity matrix:" << std::endl;
  std::cout << esim_mat.m << std::endl << std::endl;
  std::cout << std::fixed << std::setprecision(2);

  //GraphMatchingPath gm(&vsim_mat.m, &esim_mat, &src_adj, &dst_adj);
  GraphMatchingPath gm(&other_vsim, &esim_mat, &src_adj, &dst_adj);

  Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic,Eigen::RowMajor> x(ng,nh);
  x << 0.2, 0.2, 0.2, 0.2, 0.2, 0.2,
       0.2, 0.2, 0.2, 0.2, 0.2, 0.2,
       0.2, 0.2, 0.2, 0.2, 0.2, 0.2,
       0.2, 0.2, 0.2, 0.2, 0.2, 0.2,
       0.2, 0.2, 0.2, 0.2, 0.2, 0.2;

  gm.frankWolfe(0.0, &x, &x);

  std::cout << x << std::endl;
}