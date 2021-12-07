#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <cassert>
#include <iosfwd>
#include <set>
#include <vector>

namespace coloring {

using Color = unsigned;

class Vertex {
 public:
  using Idx = std::size_t;
  using const_iterator = std::set<Idx>::const_iterator;
  Vertex() : color_{0} {}
  const_iterator begin() const { return adjacent_vertices_.cbegin(); }
  const_iterator end() const { return adjacent_vertices_.cend(); }
  void addAdjacentVertex(Idx vertex) { adjacent_vertices_.insert(vertex); }
  bool isAdjacentVertex(Idx vertex) const {
    return adjacent_vertices_.count(vertex);
  }
  size_t getDegree() const { return adjacent_vertices_.size(); }
  void assignColor(Color color) {
    assert(color);
    color_ = color;
  }
  void clearColor() { color_ = 0; }
  bool hasColor() const { return color_; }
  Color getColor() const {
    assert(hasColor());
    return color_;
  }

 private:
  std::set<Idx> adjacent_vertices_;
  Color color_;
};

class Graph {
 public:
  using const_iterator = std::vector<Vertex>::const_iterator;
  Graph(size_t N = 0) : vertices_{N}, max_color_{0} {}
  Vertex &getVertex(Vertex::Idx idx) { return vertices_[idx]; }
  const Vertex &getVertex(Vertex::Idx idx) const { return vertices_[idx]; }
  size_t getNumVertices() const { return vertices_.size(); }
  const_iterator begin() const { return vertices_.cbegin(); }
  const_iterator end() const { return vertices_.cend(); }
  void resize(size_t N) {
    if (N > vertices_.size()) vertices_.resize(N);
  }
  void addEdge(Vertex::Idx idx1, Vertex::Idx idx2) {
    resize(std::max(idx1, idx2));
    getVertex(idx1).addAdjacentVertex(idx2);
    getVertex(idx2).addAdjacentVertex(idx1);
  }
  Color getNumColors() const { return max_color_; }
  Color getNewColor() { return ++max_color_; }
  size_t getMaxDegree() const;
  void clearColoring();
  bool checkColoring() const;
  void dump(std::ostream &os) const;
  void read(std::istream &is);

 private:
  std::vector<Vertex> vertices_;
  Color max_color_;
};

std::ostream &operator<<(std::ostream &os, const Graph &G);
std::istream &operator>>(std::istream &is, Graph &G);

// Some graph generators
Graph GetCompleteGraph(size_t N);
Graph GetAcyclicGraph(size_t N);
Graph GetBipartiteGraph(size_t N1, size_t N2);
}  // namespace graph

#endif
