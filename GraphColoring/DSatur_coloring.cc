#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

#include "graph.hpp"

namespace coloring {
// Struct stores all data of Vertex needed to declare an order.
struct VertexInfo {
  size_t Sat;
  size_t Deg;
  Vertex::Idx VIdx;
};
}  // namespace coloring

namespace std {
template <>
// Not less but greater.
struct less<coloring::VertexInfo> {
  auto operator()(const coloring::VertexInfo &lhs,
                  const coloring::VertexInfo &rhs) const -> bool {
    return lhs.Sat > rhs.Sat || lhs.Deg > rhs.Deg || lhs.VIdx > rhs.VIdx;
  }
};
}  // namespace std

namespace coloring {

void DSaturColoring(Graph &G) {
  size_t N = G.getNumVertices();

  // Mark which colors are Used and which are not.
  std::vector<bool> Used(N + 1, false);

  // Fill degree into separate vector.
  std::vector<size_t> D;
  std::transform(G.begin(), G.end(), std::back_inserter(D),
                 [](Vertex const &V) { return V.getDegree(); });

  // Keeps saturation degree of each Vertex.
  std::vector<std::set<int>> VSat(N);

  // Fill priority queue to be processed with initial values.
  std::set<VertexInfo> Queue;
  for (size_t u = 0; u != N; ++u) Queue.emplace(VertexInfo{0, D[u], u});

  // Process while Queue not empty.
  while (!Queue.empty()) {
    // Get the Vertex with the highest satureation degree and remove it from
    // Queue.
    auto const Max = Queue.begin();
    Vertex::Idx UIdx = Max->VIdx;
    Queue.erase(Max);
    auto &U = G.getVertex(UIdx);

    // Mark all adjacent vertex colors as Used.
    for (auto &&V : U.getAdjVIterators())
      if (V->hasColor()) Used[V->getColor()] = true;

    // Find the lowest available color.
    Color i = 1;
    for (; i != N && Used[i]; ++i)
      ;

    // Restore usage of colors.
    for (auto &&V : U.getAdjVIterators())
      if (V->hasColor()) Used[V->getColor()] = false;

    U.assignColor(i);

    // Update saturation degree of uncolored vertices and update Queue.
    for (Vertex::Idx VIdx : U) {
      if (G.getVertex(VIdx).hasColor()) continue;

      auto &Sat = VSat[VIdx];
      Queue.erase(VertexInfo{Sat.size(), D[VIdx], VIdx});
      Sat.insert(i);
      D[VIdx]--;
      Queue.emplace(VertexInfo{Sat.size(), D[VIdx], VIdx});
    }
  }
}

}  // namespace coloring
