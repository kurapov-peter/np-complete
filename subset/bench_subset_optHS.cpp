#include "SSet.h"
#include "benchmark/benchmark.h"

#include <iostream>
#include <sstream>

static void BM_subsetOPTHSFromFile10T(benchmark::State& state) {
  SSet set;
  set.loadFromFile("../tests/input_sets/set_true_10.txt");
  for (auto _ : state) {
    set.checkZeroSumOptimizedHS();
  }
}

static void BM_subsetOPTHSFromFile10F(benchmark::State& state) {
  SSet set;
  set.loadFromFile("../tests/input_sets/set_false_10.txt");
  for (auto _ : state) {
    set.checkZeroSumOptimizedHS();
  }
}

static void BM_subsetOPTHSFromFile20T(benchmark::State& state) {
  SSet set;
  set.loadFromFile("../tests/input_sets/set_true_20.txt");
  for (auto _ : state) {
    set.checkZeroSumOptimizedHS();
  }
}

static void BM_subsetOPTHSFromFile20F(benchmark::State& state) {
  SSet set;
  set.loadFromFile("../tests/input_sets/set_false_20.txt");
  for (auto _ : state) {
    set.checkZeroSumOptimizedHS();
  }
}

BENCHMARK(BM_subsetOPTHSFromFile10T);
BENCHMARK(BM_subsetOPTHSFromFile10F);
BENCHMARK(BM_subsetOPTHSFromFile20T);
BENCHMARK(BM_subsetOPTHSFromFile20F);

BENCHMARK_MAIN();
