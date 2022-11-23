#include <iostream>
#include <sstream>

#include "SSet.h"
#include "benchmark/benchmark.h"

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
static void BM_subsetOPTHSFromFile15T(benchmark::State& state) {
  SSet set;
  set.loadFromFile("../tests/input_sets/set_true_15.txt");
  for (auto _ : state) {
    set.checkZeroSumOptimizedHS();
  }
}
static void BM_subsetOPTHSFromFile15F(benchmark::State& state) {
  SSet set;
  set.loadFromFile("../tests/input_sets/set_false_15.txt");
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
static void BM_subsetOPTHSFromFile25T(benchmark::State& state) {
  SSet set;
  set.loadFromFile("../tests/input_sets/set_true_25.txt");
  for (auto _ : state) {
    set.checkZeroSumOptimizedHS();
  }
}
static void BM_subsetOPTHSFromFile25F(benchmark::State& state) {
  SSet set;
  set.loadFromFile("../tests/input_sets/set_false_25.txt");
  for (auto _ : state) {
    set.checkZeroSumOptimizedHS();
  }
}
static void BM_subsetOPTHSFromFile30T(benchmark::State& state) {
  SSet set;
  set.loadFromFile("../tests/input_sets/set_true_30.txt");
  for (auto _ : state) {
    set.checkZeroSumOptimizedHS();
  }
}
static void BM_subsetOPTHSFromFile30F(benchmark::State& state) {
  SSet set;
  set.loadFromFile("../tests/input_sets/set_false_30.txt");
  for (auto _ : state) {
    set.checkZeroSumOptimizedHS();
  }
}
BENCHMARK(BM_subsetOPTHSFromFile10T);
BENCHMARK(BM_subsetOPTHSFromFile10F);
BENCHMARK(BM_subsetOPTHSFromFile15T);
BENCHMARK(BM_subsetOPTHSFromFile15F);
BENCHMARK(BM_subsetOPTHSFromFile20T);
BENCHMARK(BM_subsetOPTHSFromFile20F);
BENCHMARK(BM_subsetOPTHSFromFile25T);
BENCHMARK(BM_subsetOPTHSFromFile25F);
BENCHMARK(BM_subsetOPTHSFromFile30T);
BENCHMARK(BM_subsetOPTHSFromFile30F);

BENCHMARK_MAIN();
