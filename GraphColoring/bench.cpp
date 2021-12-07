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

BENCHMARK(BM_coloringGreedyCompleteGraph)->RangeMultiplier(2)->Range(1, 1024);
BENCHMARK(BM_coloringGreedyAcyclicGraph)->RangeMultiplier(2)->Range(1, 1024);
BENCHMARK(BM_coloringGreedyBipartiteGraph)->RangeMultiplier(2)->Range(1, 1024);

BENCHMARK_MAIN();
