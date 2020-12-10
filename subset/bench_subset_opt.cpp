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
static void BM_subsetOPTFromFile15T(benchmark::State& state) {
  SSet set;
  set.loadFromFile("../tests/input_sets/set_true_15.txt");
  for (auto _ : state) {
    set.checkZeroSumOptimized();
  }
}
static void BM_subsetOPTFromFile15F(benchmark::State& state) {
  SSet set;
  set.loadFromFile("../tests/input_sets/set_false_15.txt");
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
static void BM_subsetOPTFromFile25T(benchmark::State& state) {
  SSet set;
  set.loadFromFile("../tests/input_sets/set_true_25.txt");
  for (auto _ : state) {
    set.checkZeroSumOptimized();
  }
}
static void BM_subsetOPTFromFile25F(benchmark::State& state) {
  SSet set;
  set.loadFromFile("../tests/input_sets/set_false_25.txt");
  for (auto _ : state) {
    set.checkZeroSumOptimized();
  }
}
static void BM_subsetOPTFromFile30T(benchmark::State& state) {
  SSet set;
  set.loadFromFile("../tests/input_sets/set_true_30.txt");
  for (auto _ : state) {
    set.checkZeroSumOptimized();
  }
}
static void BM_subsetOPTFromFile30F(benchmark::State& state) {
  SSet set;
  set.loadFromFile("../tests/input_sets/set_false_30.txt");
  for (auto _ : state) {
    set.checkZeroSumOptimized();
  }
}

BENCHMARK(BM_subsetOPTFromFile10T);
BENCHMARK(BM_subsetOPTFromFile10F);
BENCHMARK(BM_subsetOPTFromFile15T);
BENCHMARK(BM_subsetOPTFromFile15F);
BENCHMARK(BM_subsetOPTFromFile20T);
BENCHMARK(BM_subsetOPTFromFile20F);
BENCHMARK(BM_subsetOPTFromFile25T);
BENCHMARK(BM_subsetOPTFromFile25F);
BENCHMARK(BM_subsetOPTFromFile30T);
BENCHMARK(BM_subsetOPTFromFile30F);

BENCHMARK_MAIN();

