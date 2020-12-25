
/*
 * Adjacency list graph
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <string>
#include <unordered_map>
#include <vector>

namespace graph {

using Vertex = int;

class Graph {
 public:
  int addVertex(Vertex v);
  int addEdge(Vertex v, Vertex u);

  int removeVertex(Vertex v);
  int removeEdge(Vertex v, Vertex u);

  bool isAdjacent(Vertex v, Vertex u) const;
  std::list<Vertex> adjacentList(Vertex v) const;

  size_t size() const { return size_; }
  std::vector<Vertex> vertices() const;

  bool load(std::istream &in);
  bool load(std::string fileName);

  bool validate() const;
  void dumpDot() const;

 private:
  std::unordered_map<Vertex, std::list<Vertex> > adjacency_;
  size_t size_ = 0;
};

}  // namespace graph

#endif
