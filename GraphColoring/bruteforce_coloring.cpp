#include <algorithm>
#include <cassert>
#include <iostream>

#include "graph.hpp"

namespace coloring {
bool isSuccessColoring(Graph &G) {
  for (Vertex::Idx idx = 0; idx < G.getNumVertices(); ++idx) {
    for (auto adj_idx : G.getVertex(idx)) {
      if (G.getVertex(idx).getColor() == G.getVertex(adj_idx).getColor()) {
        return false;
      }
    }
  }
  return true;
}

bool checkEach(Vertex::Idx vert, Color maxColors, Graph &G) {
  bool isSuccess = false;
  constexpr Color BASE_COLOR = 1;

  for (uint32_t K = 1; K <= maxColors; ++K) {
    G.getVertex(vert).assignColor(K);

    if (isSuccessColoring(G)) {
      return true;
    } else {
      for (Vertex::Idx idx = vert + 1; idx < G.getNumVertices(); ++idx) {
        isSuccess = checkEach(idx, maxColors, G);
        if (isSuccess) {
          return true;
        }
      }
      G.getVertex(vert).assignColor(BASE_COLOR);
    }
  }

  return isSuccess;
}

void BruteForceColoring(Graph &G) {
  // WARNING: O(1^N * ... * N^N).
  Vertex::Idx N = G.getNumVertices();

  // Current number of colors.
  uint32_t K = 1;

  bool isSuccess = false;
  // Special case for one color.
  for (auto n = 0; n < N; ++n) {
    G.getVertex(n).assignColor(K);
  }
  isSuccess = isSuccessColoring(G);
  if (!isSuccess) {
    for (K = 2; K < N + 1; ++K) {
      bool isSuccess = checkEach(0, K, G);
      if (isSuccess) {
        break;
      }
    }
  }

  G.setMaxColor(K);
}
}  // namespace coloring
