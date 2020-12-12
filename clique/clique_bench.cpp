
#include "benchmark/benchmark.h"
#include "clique.hpp"
#include "graph.hpp"
#include "graph_generator.hpp"

#include <iostream>
#include <sstream>

static void BM_cliqueBruteForce(benchmark::State& state) {
  auto graph = graph::graphWithClique(10, 5);
  for (auto _ : state) {
    graph::maxCliqueBruteForce(graph);
  }
}

static void BM_clique(benchmark::State& state) {
  auto graph = graph::graphWithClique(10, 5);
  for (auto _ : state) {
    graph::maxClique(graph);
  }
}

BENCHMARK(BM_cliqueBruteForce);
BENCHMARK(BM_clique);
BENCHMARK_MAIN();
