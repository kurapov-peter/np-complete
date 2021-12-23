#include "graph.hpp"

#include <algorithm>
#include <iomanip>
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
  constexpr uint32_t maxR = 0xf;
  constexpr uint32_t maxG = 0xff;
  constexpr uint32_t maxB = 0xfff;

  assert(max_color <= maxB);

  uint32_t r = 0, g = 0, b = 0;
  if (color) {
    r = color & maxR;
    g = (color & maxG) >> 4;
    b = (color & maxB) >> 8;

    r *= 0xf;
    g *= 0xf;
    b *= 0xf;
  }

  // The most used case. Convert r->rgb.
  if (g == 0 && b == 0) {
    uint32_t real = r;
    r = real & 7;
    g = (real & 0x3f) >> 3;
    b = real >> 6;

    r *= 0x1e;
    g *= 0x1e;
    b *= 0x1e;
  }

  std::stringstream ss;
  ss << "#";
  ss << std::hex << std::setfill('0') << std::setw(2) << b;
  ss << std::hex << std::setfill('0') << std::setw(2) << g;
  ss << std::hex << std::setfill('0') << std::setw(2) << r;
  return ss.str();
}

void Graph::dump(std::ostream &os) const {
  os << "graph {\n";
  for (Vertex::Idx idx = 0; idx < vertices_.size(); ++idx) {
    const auto &V = getVertex(idx);
    os << "\tv" << idx << "[fillcolor=\""
       << ColorToString(V.hasColor() ? V.getColor() : 0, getNumColors())
       << "\", style=filled"
       << "];\n";
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

}  // namespace coloring
