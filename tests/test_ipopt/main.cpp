#include <iostream>
#include <map>
#include <Eigen/Core>

#include <IpIpoptApplication.hpp>

#include "nonlinprogram.hpp"

class TwoGraphs
{
public:
  std::size_t nbnodes_src;
  std::size_t nbnodes_dst;
  Eigen::MatrixXd vertex_similarity;
  std::map<std::pair<std::size_t, std::size_t>, unsigned int> sourceEdgeIndex;
  std::map<std::pair<std::size_t, std::size_t>, unsigned int> destEdgeIndex;
  Eigen::MatrixXd edge_similarity;

public:
  TwoGraphs();
};

TwoGraphs::TwoGraphs()
  : nbnodes_src(6), nbnodes_dst(6),
  vertex_similarity(6,6),
  edge_similarity(2*7,2*7)
{
  vertex_similarity <<
    1.0, 0.5, 0.5, 0.5, 0.5, 0.5,
    0.5, 1.0, 0.6, 0.6, 0.9, 0.5,
    0.5, 0.6, 1.0, 0.9, 0.6, 0.5,
    0.5, 0.5, 0.9, 0.5, 0.5, 0.5,
    0.5, 0.6, 0.9, 1.0, 0.6, 0.5,
    0.5, 0.5, 0.6, 0.6, 1.0, 0.5;

  sourceEdgeIndex[std::make_pair(0,1)] = 0;
  sourceEdgeIndex[std::make_pair(1,2)] = 2;
  sourceEdgeIndex[std::make_pair(2,4)] = 4;
  sourceEdgeIndex[std::make_pair(4,5)] = 6;
  sourceEdgeIndex[std::make_pair(5,0)] = 8;
  sourceEdgeIndex[std::make_pair(5,1)] = 10;
  sourceEdgeIndex[std::make_pair(2,3)] = 12;

  sourceEdgeIndex[std::make_pair(1,0)] = 1;
  sourceEdgeIndex[std::make_pair(2,1)] = 3;
  sourceEdgeIndex[std::make_pair(4,2)] = 5;
  sourceEdgeIndex[std::make_pair(5,4)] = 7;
  sourceEdgeIndex[std::make_pair(0,5)] = 9;
  sourceEdgeIndex[std::make_pair(1,5)] = 11;
  sourceEdgeIndex[std::make_pair(3,2)] = 13;

  destEdgeIndex[std::make_pair(0,1)] = 0;
  destEdgeIndex[std::make_pair(1,2)] = 2;
  destEdgeIndex[std::make_pair(2,3)] = 4;
  destEdgeIndex[std::make_pair(3,4)] = 6;
  destEdgeIndex[std::make_pair(4,0)] = 8;
  destEdgeIndex[std::make_pair(4,5)] = 10;
  destEdgeIndex[std::make_pair(4,1)] = 12;

  destEdgeIndex[std::make_pair(1,0)] = 1;
  destEdgeIndex[std::make_pair(2,1)] = 3;
  destEdgeIndex[std::make_pair(3,2)] = 5;
  destEdgeIndex[std::make_pair(4,3)] = 7;
  destEdgeIndex[std::make_pair(0,4)] = 9;
  destEdgeIndex[std::make_pair(5,4)] = 11;
  destEdgeIndex[std::make_pair(1,4)] = 13;

  edge_similarity <<
    1.0,1.0,0.1,0.1,0.2,0.2,0.3,0.3,0.9,0.9,1.0,1.0,0.1,0.1,
    1.0,1.0,0.1,0.1,0.2,0.2,0.3,0.3,0.9,0.9,1.0,1.0,0.1,0.1,
    0.1,0.1,1.0,1.0,0.0,0.0,1.0,1.0,0.2,0.2,0.9,0.9,0.1,0.1,
    0.1,0.1,1.0,1.0,0.0,0.0,1.0,1.0,0.2,0.2,0.9,0.9,0.1,0.1,
    0.1,0.1,0.1,0.1,1.0,1.0,0.1,0.1,0.1,0.1,1.0,1.0,1.0,1.0,
    0.1,0.1,0.1,0.1,1.0,1.0,0.1,0.1,0.1,0.1,1.0,1.0,1.0,1.0,
    0.2,0.2,1.0,1.0,0.2,0.2,1.0,1.0,0.2,0.2,1.0,1.0,0.2,0.2,
    0.2,0.2,1.0,1.0,0.2,0.2,1.0,1.0,0.2,0.2,1.0,1.0,0.2,0.2,
    0.7,0.7,1.0,1.0,0.3,0.3,0.2,0.2,1.0,1.0,1.0,1.0,0.1,0.1,
    0.7,0.7,1.0,1.0,0.3,0.3,0.2,0.2,1.0,1.0,1.0,1.0,0.1,0.1,
    0.1,0.1,0.1,0.1,1.0,1.0,0.1,0.1,0.1,0.1,0.4,0.4,0.1,0.1,
    0.1,0.1,0.1,0.1,1.0,1.0,0.1,0.1,0.1,0.1,0.4,0.4,0.1,0.1,
    0.6,0.6,0.6,0.6,0.8,0.8,0.6,0.6,0.6,0.6,1.0,1.0,0.7,0.7,
    0.6,0.6,0.6,0.6,0.8,0.8,0.6,0.6,0.6,0.6,1.0,1.0,0.7,0.7;
}

int main(void)
{
  TwoGraphs two_graphs;
  Ipopt::SmartPtr<Ipopt::TNLP> problem = new GraphMatching(&two_graphs.vertex_similarity, &two_graphs.edge_similarity, &two_graphs.sourceEdgeIndex, &two_graphs.destEdgeIndex);
  Ipopt::SmartPtr<Ipopt::IpoptApplication> app = IpoptApplicationFactory();
  app->Options()->SetNumericValue("tol", 1e-7);
  app->Options()->SetStringValue("mu_strategy", "adaptive");
  app->Options()->SetStringValue("output_file", "ipopt.out");
  app->Options()->SetIntegerValue("print_level", 0);    // verbosity

  Ipopt::ApplicationReturnStatus status;
  status = app->Initialize();
  if( status != Ipopt::Solve_Succeeded )
  {
     std::cout << std::endl << std::endl << "*** Error during initialization!" << std::endl;
     return (int) status;
  }
  // Ask Ipopt to solve the problem
  status = app->OptimizeTNLP(problem);
  if( status == Ipopt::Solve_Succeeded )
  {
     std::cout << std::endl << std::endl << "*** The problem solved!" << std::endl;
  }
  else
  {
     std::cout << std::endl << std::endl << "*** The problem FAILED!" << std::endl;
  }
  // As the Ipopt::SmartPtrs go out of scope, the reference count
  // will be decremented and the objects will automatically
  // be deleted.
  return (int) status;
}
