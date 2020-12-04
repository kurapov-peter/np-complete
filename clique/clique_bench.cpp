
#include "benchmark/benchmark.h"
#include "clique.hpp"
#include "graph.hpp"

#include <iostream>
#include <sstream>

static void BM_cliqueBruteForce(benchmark::State& state) {
  graph::Graph graph;
  // TODO independent way of loading graph
  graph.load("../clique/inputs/benchmark.in");
  for (auto _ : state) {
    graph::maxCliqueBruteForce(graph);
  }
}

static void BM_clique(benchmark::State& state) {
  graph::Graph graph;
  // TODO independent way of loading graph
  graph.load("../clique/inputs/benchmark.in");
  for (auto _ : state) {
    graph::maxClique(graph);
  }
}

BENCHMARK(BM_cliqueBruteForce);
BENCHMARK(BM_clique);
BENCHMARK_MAIN();
