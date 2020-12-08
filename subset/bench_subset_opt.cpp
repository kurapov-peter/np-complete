#include "SSet.h"
#include "benchmark/benchmark.h"

#include <iostream>
#include <sstream>

static void BM_subsetOPTFromFile10T(benchmark::State& state) {
  SSet set;
  set.loadFromFile("../tests/input_sets/set_true_10.txt");
  for (auto _ : state) {
    set.checkZeroSumOptimized();
  }
}

static void BM_subsetOPTFromFile10F(benchmark::State& state) {
  SSet set;
  set.loadFromFile("../tests/input_sets/set_false_10.txt");
  for (auto _ : state) {
    set.checkZeroSumOptimized();
  }
}

static void BM_subsetOPTFromFile20T(benchmark::State& state) {
  SSet set;
  set.loadFromFile("../tests/input_sets/set_true_20.txt");
  for (auto _ : state) {
    set.checkZeroSumOptimized();
  }
}

static void BM_subsetOPTFromFile20F(benchmark::State& state) {
  SSet set;
  set.loadFromFile("../tests/input_sets/set_false_20.txt");
  for (auto _ : state) {
    set.checkZeroSumOptimized();
  }
}

BENCHMARK(BM_subsetOPTFromFile10T);
BENCHMARK(BM_subsetOPTFromFile10F);
BENCHMARK(BM_subsetOPTFromFile20T);
BENCHMARK(BM_subsetOPTFromFile20F);

BENCHMARK_MAIN();
