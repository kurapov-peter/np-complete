#include "SSet.h"
#include "benchmark/benchmark.h"

#include <iostream>
#include <sstream>

static void BM_subsetBruteFromFile10T(benchmark::State& state) {
  SSet set;
  set.loadFromFile("../tests/input_sets/set_true_10.txt");
  for (auto _ : state) {
    set.checkZeroSumSlow();
  }
}
static void BM_subsetBruteFromFile10F(benchmark::State& state) {
  SSet set;
  set.loadFromFile("../tests/input_sets/set_false_10.txt");
  for (auto _ : state) {
    set.checkZeroSumSlow();
  }
}
static void BM_subsetBruteFromFile15T(benchmark::State& state) {
  SSet set;
  set.loadFromFile("../tests/input_sets/set_true_15.txt");
  for (auto _ : state) {
    set.checkZeroSumSlow();
  }
}
static void BM_subsetBruteFromFile15F(benchmark::State& state) {
  SSet set;
  set.loadFromFile("../tests/input_sets/set_false_15.txt");
  for (auto _ : state) {
    set.checkZeroSumSlow();
  }
}
static void BM_subsetBruteFromFile20T(benchmark::State& state) {
  SSet set;
  set.loadFromFile("../tests/input_sets/set_true_20.txt");
  for (auto _ : state) {
    set.checkZeroSumSlow();
  }
}
static void BM_subsetBruteFromFile20F(benchmark::State& state) {
  SSet set;
  set.loadFromFile("../tests/input_sets/set_false_20.txt");
  for (auto _ : state) {
    set.checkZeroSumSlow();
  }
}
static void BM_subsetBruteFromFile25T(benchmark::State& state) {
  SSet set;
  set.loadFromFile("../tests/input_sets/set_true_25.txt");
  for (auto _ : state) {
    set.checkZeroSumSlow();
  }
}
static void BM_subsetBruteFromFile25F(benchmark::State& state) {
  SSet set;
  set.loadFromFile("../tests/input_sets/set_false_25.txt");
  for (auto _ : state) {
    set.checkZeroSumSlow();
  }
}

BENCHMARK(BM_subsetBruteFromFile10T);
BENCHMARK(BM_subsetBruteFromFile10F);
BENCHMARK(BM_subsetBruteFromFile15T);
BENCHMARK(BM_subsetBruteFromFile15F);
BENCHMARK(BM_subsetBruteFromFile20T);
BENCHMARK(BM_subsetBruteFromFile20F);
BENCHMARK(BM_subsetBruteFromFile25T);
BENCHMARK(BM_subsetBruteFromFile25F);

BENCHMARK_MAIN();
