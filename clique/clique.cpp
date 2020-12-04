
#include "clique.hpp"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>

namespace {

std::set<std::vector<int> > findAllCombinations(std::vector<int> numbers,
                                                size_t k) {
  std::set<std::vector<int> > combinations;
  std::sort(numbers.begin(), numbers.end());

  if (k == numbers.size()) {
    combinations.insert(numbers);
    return combinations;
  }

  std::vector<bool> mask(numbers.size());
  std::fill(mask.begin(), mask.begin() + k, true);
  do {
    std::vector<int> combination;
    for (int i = 0; i < numbers.size() - 1; ++i) {
      if (mask[i]) combination.push_back(numbers[i + 1]);
    }

    std::sort(combination.begin(), combination.end());
    combinations.insert(combination);

  } while (std::next_permutation(numbers.begin(), numbers.end()));

  return combinations;
}

}  // namespace

namespace graph {

bool isClique(const Graph &graph) {
  auto vertices = graph.vertices();
  for (size_t i = 0; i < vertices.size(); ++i) {
    for (size_t j = i + 1; j < vertices.size(); ++j)
      if (!graph.isAdjacent(vertices[i], vertices[j])) return false;
  }
  return true;
}

size_t maxCliqueBruteForce(const Graph &graph) {
  if (isClique(graph)) return graph.size();

  auto vertices = graph.vertices();

  for (size_t k = graph.size(); k >= 1; --k) {
    auto combinations = findAllCombinations(vertices, k);
    for (auto &combination : combinations) {
      Graph clique;
      for (auto v : combination) clique.addVertex(v);

      for (auto v : combination) {
        auto adjList = graph.adjacentList(v);
        for (auto adjV : adjList) clique.addEdge(v, adjV);
      }

      if (isClique(clique)) return k;
    }
  }
  return 0;
}
}  // namespace graph

namespace {
// TODO return type of graph API
template <typename T>
std::set<T> vectorToSet(const std::vector<T> &vector) {
  std::set<T> set(vector.begin(), vector.end());
  return set;
}

template <typename T>
std::set<T> listToSet(const std::list<T> &list) {
  std::set<T> set(list.begin(), list.end());
  return set;
}

std::set<graph::Vertex> set_union(const std::set<graph::Vertex> &lhs,
                                  const std::set<graph::Vertex> &rhs) {
  std::set<graph::Vertex> sunion;
  std::set_union(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(),
                 std::inserter(sunion, sunion.begin()));
  return sunion;
}

std::set<graph::Vertex> set_intersection(const std::set<graph::Vertex> &lhs,
                                         const std::set<graph::Vertex> &rhs) {
  std::set<graph::Vertex> sintersection;
  std::set_intersection(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(),
                        std::inserter(sintersection, sintersection.begin()));

  return sintersection;
}

std::set<graph::Vertex> set_difference(const std::set<graph::Vertex> &lhs,
                                       const std::set<graph::Vertex> &rhs) {
  std::set<graph::Vertex> sdifference;
  std::set_difference(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(),
                      std::inserter(sdifference, sdifference.begin()));

  return sdifference;
}

size_t bronKerbosh(const graph::Graph &graph, std::set<graph::Vertex> compsub,
                   std::set<graph::Vertex> candidates,
                   std::set<graph::Vertex> ineligble) {
  if (candidates.empty() && ineligble.empty()) return compsub.size();

  auto vIt = candidates.begin();
  size_t maxCliqueSize = 0;
  while (!candidates.empty() && vIt != candidates.end()) {
    std::set<graph::Vertex> single = {(*vIt)};
    auto neighbors = listToSet(graph.adjacentList(*vIt));

    auto size = bronKerbosh(graph, set_union(compsub, single),
                            set_intersection(candidates, neighbors),
                            set_intersection(ineligble, neighbors));

    candidates = set_difference(candidates, single);
    ineligble = set_union(ineligble, single);
    if (!candidates.empty()) vIt = candidates.begin();

    maxCliqueSize = (maxCliqueSize < size) ? size : maxCliqueSize;
  }
  return maxCliqueSize;
}

}  // namespace

namespace graph {

size_t maxClique(const Graph &graph) {
  std::set<Vertex> candidates = vectorToSet(graph.vertices());
  std::set<Vertex> compsub = {};
  std::set<Vertex> ineligble = {};

  return bronKerbosh(graph, compsub, candidates, ineligble);
}

}  // namespace graph
