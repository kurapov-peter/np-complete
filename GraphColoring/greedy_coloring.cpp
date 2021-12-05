#include <algorithm>
#include <cassert>

#include "graph.hpp"

namespace graph {

static Color getVertexColor(Graph &G, const Vertex &V) {
  assert(!V.hasColor());
  std::set<Color> neighbour_colors;
  for (auto adj_idx : V)
    if (const auto &adj_V = G.getVertex(adj_idx); adj_V.hasColor())
      neighbour_colors.insert(adj_V.getColor());
  for (Color i = 1; i <= G.getNumColors(); ++i)
    if (!neighbour_colors.count(i)) return i;
  return G.getNewColor();
}

static std::vector<Vertex::Idx> getDegeneracyOrdering(const Graph &G) {
  Vertex::Idx N = G.getNumVertices();
  std::vector<size_t> d(N);
  std::vector<std::set<Vertex::Idx>> D(G.getMaxDegree() + 1);
  for (Vertex::Idx idx = 0; idx < N; ++idx) {
    auto degree = G.getVertex(idx).getDegree();
    d[idx] = degree;
    D[degree].insert(idx);
  }
  std::vector<Vertex::Idx> res(N);
  std::set<Vertex::Idx> processed_vertices;
  for (Vertex::Idx i = 0; i < N; ++i)
    for (auto &vertices : D) {
      if (vertices.empty()) continue;
      auto v = *vertices.begin();
      vertices.erase(vertices.begin());
      res[N - i - 1] = v;
      processed_vertices.insert(v);
      for (auto adj_idx : G.getVertex(v)) {
        if (processed_vertices.count(adj_idx)) continue;
        auto degree = d[adj_idx];
        assert(degree);
        D[degree].erase(adj_idx);
        D[degree - 1].insert(adj_idx);
        --d[adj_idx];
      }
      break;
    }
  return res;
}

void GreedyColoring(Graph &G) {
  auto vertex_ordering = getDegeneracyOrdering(G);
  for (auto idx : vertex_ordering) {
    auto &V = G.getVertex(idx);
    auto color = getVertexColor(G, V);
    V.assignColor(color);
  }
}

}  // namespace graph
