
#ifndef __DEF_CPR_MATRICES_H__
# define __DEF_CPR_MATRICES_H__

#include <Eigen/Core>
#include "cpr_main.h"

class VertexSimilarityMatrix
{
public:
  MatrixDouble m;

public:
  VertexSimilarityMatrix(ESFDescriptors const &source, ESFDescriptors const &dest);
};

class EdgeSimilarityMatrix
{
public:
  // correspondance <vertex, vertex> -> edge index in matrix
  std::map<std::pair<KeyT, KeyT>, unsigned int> sourceEdgeIndex;
  std::map<std::pair<KeyT, KeyT>, unsigned int> destEdgeIndex;

  // matrix
  MatrixDouble m;

public:
  EdgeSimilarityMatrix(EdgeDescriptors const &source, EdgeDescriptors const &dest);
};

void buildAdjacencyMatrix(SupervoxelAdjacency const &supervoxel_adjacency,
  MatrixInt &adjacency_matrix);

void printMatrixToFile(char const *filename, MatrixInt const &m);
void printMatrixToFile(char const *filename, MatrixDouble const &m);

#endif /* __DEF_CPR_MATRICES_H__ */
