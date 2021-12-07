#include "graph.hpp"

#include <algorithm>
#include <iostream>
#include <sstream>

namespace coloring {

size_t Graph::getMaxDegree() const {
  size_t max_degree = 0;
  for (const auto &V : vertices_)
    max_degree = std::max(max_degree, V.getDegree());
  return max_degree;
}

void Graph::clearColoring() {
  for (auto &V : vertices_) V.clearColor();
}

bool Graph::checkColoring() const {
  if (!std::all_of(vertices_.begin(), vertices_.end(),
                   [](const Vertex &V) { return V.hasColor(); })) {
    std::cerr << "Not all vertices has assigned colors" << std::endl;
    return false;
  }
  for (Vertex::Idx idx = 0; idx < vertices_.size(); ++idx)
    for (auto adj_idx : getVertex(idx))
      if (getVertex(idx).getColor() == getVertex(adj_idx).getColor()) {
        std::cerr << "Vertices " << idx << " and " << adj_idx
                  << " has same colors assigned";
        return false;
      }
  return true;
}

static std::string ColorToString(Color color, Color max_color) {
  float h = 0.0f, s = 0.0f, v = 0.0f;
  if (color) {
    h = (float)color / max_color;
    s = 1.0f;
  }
  std::stringstream ss;
  ss << h << ' ' << s << ' ' << v;
  return ss.str();
}

void Graph::dump(std::ostream &os) const {
  os << "graph {\n";
  for (Vertex::Idx idx = 0; idx < vertices_.size(); ++idx) {
    const auto &V = getVertex(idx);
    os << "\tv" << idx << "[color=\""
       << ColorToString(V.hasColor() ? V.getColor() : 0, getNumColors())
       << "\"];\n";
    for (auto adj_idx : V)
      if (adj_idx > idx) os << "\tv" << idx << " -- v" << adj_idx << ";\n";
  }
  os << "}\n";
}

void Graph::read(std::istream &is) {
  size_t num_vertices, num_edges;
  is >> num_vertices >> num_edges;
  Graph G{num_vertices};
  for (size_t i = 0; i < num_edges; ++i) {
    Vertex::Idx v1, v2;
    is >> v1 >> v2;
    G.addEdge(v1 - 1, v2 - 1);
  }
}

std::ostream &operator<<(std::ostream &os, const Graph &G) {
  G.dump(os);
  return os;
}

std::istream &operator>>(std::istream &is, Graph &G) {
  G.read(is);
  return is;
}

Graph GetCompleteGraph(size_t N) {
  Graph G{N};
  for (Vertex::Idx i = 0; i < N; ++i)
    for (Vertex::Idx j = i + 1; j < N; ++j) G.addEdge(i, j);
  return G;
}

Graph GetAcyclicGraph(size_t N) {
  Graph G{N};
  for (Vertex::Idx i = 1; i < N; ++i) G.addEdge((i - 1) / 2, i);
  return G;
}

Graph GetBipartiteGraph(size_t N1, size_t N2) {
  Graph G{N1 + N2};
  for (Vertex::Idx fst = 0; fst < N1; ++fst)
    for (Vertex::Idx snd = 0; snd < N2; ++snd) G.addEdge(fst, N1 + snd);
  return G;
}

}  // namespace graph
