#include "graph.hpp"

#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>

namespace graph {

int Graph::addVertex(Vertex v) {
#ifdef NDEBUG
  assert(validate());
#endif
  if (adjacency_.find(v) != adjacency_.end()) return -1;

  adjacency_[v] = std::list<Vertex>();
  size_++;

#ifdef NDEBUG
  assert(validate());
#endif

  return 0;
}

int Graph::addEdge(Vertex v, Vertex u) {
#ifdef NDEBUG
  assert(validate());
#endif

  auto vIter = adjacency_.find(v);
  auto uIter = adjacency_.find(u);
  if (vIter == adjacency_.end() || uIter == adjacency_.end()) return -1;

  auto &vlist = vIter->second;
  auto &ulist = uIter->second;

  auto findIterU = std::find(vlist.begin(), vlist.end(), u);
  if (findIterU == vlist.end()) vlist.push_back(u);

  auto findIterV = std::find(ulist.begin(), ulist.end(), v);
  if (findIterV == ulist.end()) ulist.push_back(v);

#ifdef NDEBUG
  assert(validate());
#endif
}

int Graph::removeVertex(Vertex v) {
#ifdef NDEBUG
  assert(validate());
#endif
  auto vIter = adjacency_.find(v);
  if (vIter != adjacency_.end())
    adjacency_.erase(vIter);
  else
    return -1;

  for (auto &iter : adjacency_) {
    auto &list = iter.second;
    auto findIter = std::find(list.begin(), list.end(), v);
    if (findIter != list.end()) list.erase(findIter);
  }
  size_--;

#ifdef NDEBUG
  assert(validate());
#endif
  return 0;
}

int Graph::removeEdge(Vertex v, Vertex u) {
#ifdef NDEBUG
  assert(validate());
#endif
  auto vIter = adjacency_.find(v);
  auto uIter = adjacency_.find(u);
  if (uIter == adjacency_.end() || vIter == adjacency_.end()) return -1;

  auto &vlist = vIter->second;
  auto &ulist = uIter->second;

  auto findIterU = std::find(vlist.begin(), vlist.end(), u);
  if (findIterU != vlist.end())
    vlist.erase(findIterU);
  else
    return -1;

  auto findIterV = std::find(ulist.begin(), ulist.end(), v);
  if (findIterV != ulist.end()) ulist.erase(findIterV);
#ifdef NDEBUG
  assert(validate());
#endif
  return 0;
}

bool Graph::isAdjacent(Vertex v, Vertex u) const {
  auto vIter = adjacency_.find(v);
  if (vIter == adjacency_.end()) return false;
  auto &list = vIter->second;
  for (auto vertex : list)
    if (vertex == u) return true;
  return false;
}

std::vector<Vertex> Graph::vertices() const {
  std::vector<Vertex> verts;
  verts.reserve(size_);
  for (const auto &vlist : adjacency_) verts.push_back(vlist.first);
  return verts;
}

bool Graph::load(std::istream &in) {
  std::string inStr;

  while (inStr.empty()) std::getline(in, inStr);

  std::stringstream input(inStr);

  while (!input.eof()) {
    Vertex v;
    input >> v;
    addVertex(v);
  }

  std::string edgeStr;
  while (getline(in, edgeStr)) {
    std::stringstream edge(edgeStr);
    Vertex v, u;
    edge >> v >> u;
    addEdge(v, u);
  }

  return true;
}

bool Graph::load(std::string fileName) {
  std::fstream input(fileName);
  if (!input.is_open()) return false;
  return load(input);
}

std::list<Vertex> Graph::adjacentList(Vertex v) const {
  std::list<Vertex> vlist;
  auto iter = adjacency_.find(v);
  if (iter == adjacency_.end()) return vlist;
  vlist = iter->second;
  return vlist;
}

bool Graph::validate() const {
  if (adjacency_.size() != size_) return false;

  for (const auto &vlist : adjacency_) {
    auto &tvertex = vlist.first;
    const auto &list = vlist.second;
    for (const auto vertex : list) {
      auto compareIter = adjacency_.find(vertex);
      if (compareIter == adjacency_.end()) return false;
      auto &compareList = compareIter->second;

      auto findIter =
          std::find(compareList.begin(), compareList.end(), tvertex);
      if (findIter == compareList.end()) return false;
    }
  }
  return true;
}

void Graph::dumpDot() const {
  std::cerr << "strict graph xgraph\n{" << std::endl;

  for (const auto &vlist : adjacency_) {
    std::cerr << vlist.first << "\n";
    for (const auto &vertex : vlist.second)
      std::cerr << vlist.first << "--" << vertex << "\n";
  }
  std::cerr << "}" << std::endl;
}

}  // namespace graph
