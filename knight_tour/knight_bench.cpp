#include <cmath>
#include <iostream>

#include "benchmark/benchmark.h"
#include <vector>
#include <set>
#include <algorithm>
#include <list>

#include "knight.hpp"


using namespace knight_tour;

static void BM_simple(benchmark::State& state) {
  int max_letters = state.range(0);
  int max_num = state.range(0);
  board field(max_letters, max_num);
  for (auto _ : state) {
    solve_simple(field, {0, 0});
  }
}

BENCHMARK(BM_simple)->DenseRange(8, 8, 8);

BENCHMARK_MAIN();
