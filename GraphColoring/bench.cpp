#include "benchmark/benchmark.h"
#include "graph.hpp"
#include "graph_coloring.hpp"

static void BM_coloringGreedyCompleteGraph(benchmark::State& state) {
  auto G = coloring::GetCompleteGraph(state.range(0));
  for (auto _ : state) {
    G.clearColoring();
    coloring::GreedyColoring(G);
  }
}

static void BM_coloringGreedyAcyclicGraph(benchmark::State& state) {
  auto G = coloring::GetAcyclicGraph(state.range(0));
  for (auto _ : state) {
    G.clearColoring();
    coloring::GreedyColoring(G);
  }
}

static void BM_coloringGreedyBipartiteGraph(benchmark::State& state) {
  auto G = coloring::GetBipartiteGraph(state.range(0), state.range(0));
  for (auto _ : state) {
    G.clearColoring();
    coloring::GreedyColoring(G);
  }
}

static void BM_coloringBruteForceCompleteGraph(benchmark::State& state) {
  auto G = coloring::GetCompleteGraph(state.range(0));
  for (auto _ : state) {
    G.clearColoring();
    coloring::BruteForceColoring(G);
  }
}

static void BM_coloringBruteForceAcyclicGraph(benchmark::State& state) {
  auto G = coloring::GetAcyclicGraph(state.range(0));
  for (auto _ : state) {
    G.clearColoring();
    coloring::BruteForceColoring(G);
  }
}

static void BM_coloringBruteForceBipartiteGraph(benchmark::State& state) {
  auto G = coloring::GetBipartiteGraph(state.range(0), state.range(0));
  for (auto _ : state) {
    G.clearColoring();
    coloring::BruteForceColoring(G);
  }
}

BENCHMARK(BM_coloringGreedyCompleteGraph)->DenseRange(1, 8);
BENCHMARK(BM_coloringGreedyAcyclicGraph)->DenseRange(1, 8);
BENCHMARK(BM_coloringGreedyBipartiteGraph)->DenseRange(1, 8);

BENCHMARK(BM_coloringBruteForceCompleteGraph)->DenseRange(1, 8);
BENCHMARK(BM_coloringBruteForceAcyclicGraph)->DenseRange(1, 8);
BENCHMARK(BM_coloringBruteForceBipartiteGraph)->DenseRange(1, 8);

BENCHMARK_MAIN();
