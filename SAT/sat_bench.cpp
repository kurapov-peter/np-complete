#include <iostream>
#include "benchmark/benchmark.h"

static bool solve_sat(unsigned n) {
  // smth happens here
  return true;
}

static void BM_sat(benchmark::State& state) {
  for (auto _ : state) {
    solve_sat(state.range(0));
  }
}

BENCHMARK(BM_sat)->DenseRange(16, 32, 16);

BENCHMARK_MAIN();