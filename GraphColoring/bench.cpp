#include "benchmark/benchmark.h"
#include "graph.hpp"
#include "graph_coloring.hpp"

static void BM_coloringRLFCompleteGraph(benchmark::State& state) {
  auto G = coloring::GetCompleteGraph(state.range(0));
  for (auto _ : state) {
    G.clearColoring();
    coloring::RLFColoring(G);
  }
}

static void BM_coloringRLFAcyclicGraph(benchmark::State& state) {
  auto G = coloring::GetAcyclicGraph(state.range(0));
  for (auto _ : state) {
    G.clearColoring();
    coloring::RLFColoring(G);
  }
}

static void BM_coloringRLFBipartiteGraph(benchmark::State& state) {
  auto G = coloring::GetBipartiteGraph(state.range(0), state.range(0));
  for (auto _ : state) {
    G.clearColoring();
    coloring::RLFColoring(G);
  }
}

static void BM_coloringDSaturCompleteGraph(benchmark::State& state) {
  auto G = coloring::GetCompleteGraph(state.range(0));
  for (auto _ : state) {
    G.clearColoring();
    coloring::DSaturColoring(G);
  }
}

static void BM_coloringDSaturAcyclicGraph(benchmark::State& state) {
  auto G = coloring::GetAcyclicGraph(state.range(0));
  for (auto _ : state) {
    G.clearColoring();
    coloring::DSaturColoring(G);
  }
}

static void BM_coloringDSaturBipartiteGraph(benchmark::State& state) {
  auto G = coloring::GetBipartiteGraph(state.range(0), state.range(0));
  for (auto _ : state) {
    G.clearColoring();
    coloring::DSaturColoring(G);
  }
}

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

BENCHMARK(BM_coloringRLFCompleteGraph)->DenseRange(1, 8);
BENCHMARK(BM_coloringRLFAcyclicGraph)->DenseRange(1, 8);
BENCHMARK(BM_coloringRLFBipartiteGraph)->DenseRange(1, 8);

BENCHMARK(BM_coloringDSaturCompleteGraph)->DenseRange(1, 8);
BENCHMARK(BM_coloringDSaturAcyclicGraph)->DenseRange(1, 8);
BENCHMARK(BM_coloringDSaturBipartiteGraph)->DenseRange(1, 8);

BENCHMARK(BM_coloringGreedyCompleteGraph)->DenseRange(1, 8);
BENCHMARK(BM_coloringGreedyAcyclicGraph)->DenseRange(1, 8);
BENCHMARK(BM_coloringGreedyBipartiteGraph)->DenseRange(1, 8);

BENCHMARK(BM_coloringBruteForceCompleteGraph)->DenseRange(1, 8);
BENCHMARK(BM_coloringBruteForceAcyclicGraph)->DenseRange(1, 8);
BENCHMARK(BM_coloringBruteForceBipartiteGraph)->DenseRange(1, 8);

BENCHMARK_MAIN();
