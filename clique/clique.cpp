
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

size_t maxCliqueNaive(const Graph &graph) {
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
