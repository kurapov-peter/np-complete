#include "benchmark/benchmark.h"
#include "knight.hpp"

using namespace knight_tour;

static void BM_force(benchmark::State& state) {
  int max_letters = state.range(0);
  int max_num = state.range(0);
  board f(max_letters, max_num);
  std::list<field> answer;
  for (auto _ : state) {
    answer = solve_template<chooseForce>(f, {0, 0});
  }
  if (!validate_moves(answer, max_letters, max_num)) assert("error\n");
}
static void BM_Warnsdorff(benchmark::State& state) {
  int max_letters = state.range(0);
  int max_num = state.range(0);
  board f(max_letters, max_num);
  std::list<field> answer;
  for (auto _ : state) {
    answer = solve_template<chooseWarnsdorff>(f, {0, 0});
  }
  if (!validate_moves(answer, max_letters, max_num)) assert("error\n");
}

BENCHMARK(BM_force)->DenseRange(5, 7, 1);
BENCHMARK(BM_Warnsdorff)->DenseRange(5, 7, 1);

BENCHMARK_MAIN();
