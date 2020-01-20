#include <iostream>   // std::cout
//#include <iomanip>    // std::fixed, std::setprecision to print doubles/floats

#include "cpr_graphmatching_path.h"
#include "cpr_matrices.h"
#include "cpr_main.h"

void test_two_twonodes_graphs()
{
  MatrixInt adj(2,2);    // graph = 2 nodes with one edge
  adj << 0, 1,            // second graph = first graph
         1, 0;

  MatrixDouble vsim_mat(2,2);  // similarity matrix = 1111 - identity ==> solution to the graph matching problem must be identity
  vsim_mat << 0.95, 0.10,
              0.12, 0.90;

  EdgeDescriptors ed;
  ed[std::make_pair(1,0)] = std::make_tuple(0, 3.14/2.0, 0, 1); // just one edge
  ed[std::make_pair(0,1)] = ed[std::make_pair(1,0)];

  EdgeSimilarityMatrix esim_mat(ed, ed);  // both graphs have the same edge

  MatrixDouble x(2,2);
  x << 0.5, 0.5,   // starting solution
       0.5, 0.5;

  GraphMatchingPath gm(&vsim_mat, &esim_mat, &adj, &adj);

  std::cout << std::endl << "Vertex distance matrix:" << std::endl;
  std::cout << vsim_mat << std::endl;

  std::cout << "Edge distance matrix:" << std::endl;
  std::cout << esim_mat.m << std::endl << std::endl;

  std::cout << "Starting solution:" << std::endl;
  std::cout << x << std::endl << std::endl;

  gm.frankWolfe(0.0, &x, &x);

  std::cout << "Final solution:" << std::endl;
  std::cout << x << std::endl << std::endl;
}