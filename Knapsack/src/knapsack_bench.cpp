#include <iostream>

#include "../../tests/Knapsack/includes/test_generator.h"
#include "../includes/knapsack.h"
#include "benchmark/benchmark.h"

std::vector<np::KItem> elems10 = Tests::GenRandomTest(10, 150, "");
std::vector<np::KItem> elems12 = Tests::GenRandomTest(12, 150, "");
std::vector<np::KItem> elems14 = Tests::GenRandomTest(14, 150, "");
std::vector<np::KItem> elems16 = Tests::GenRandomTest(16, 150, "");
std::vector<np::KItem> elems18 = Tests::GenRandomTest(18, 150, "");
std::vector<np::KItem> elems20 = Tests::GenRandomTest(20, 150, "");
std::vector<np::KItem> elems22 = Tests::GenRandomTest(22, 150, "");
std::vector<np::KItem> elems24 = Tests::GenRandomTest(24, 150, "");

static void BruteForce_10(benchmark::State& state) {
  size_t cap = 150;
  np::Knapsack kp(cap, elems10);
  for (auto _ : state) {
    kp.BruteForce();
  }
}
BENCHMARK(BruteForce_10);

static void BranchAndBound_10(benchmark::State& state) {
  size_t cap = 150;
  np::Knapsack kp(cap, elems10);
  for (auto _ : state) {
    kp.BranchAndBound();
  }
}
BENCHMARK(BranchAndBound_10);

static void BruteForce_12(benchmark::State& state) {
  size_t cap = 150;
  np::Knapsack kp(cap, elems12);
  for (auto _ : state) {
    kp.BruteForce();
  }
}
BENCHMARK(BruteForce_12);

static void BranchAndBound_12(benchmark::State& state) {
  size_t cap = 150;
  np::Knapsack kp(cap, elems12);
  for (auto _ : state) {
    kp.BranchAndBound();
  }
}
BENCHMARK(BranchAndBound_12);

static void BruteForce_14(benchmark::State& state) {
  size_t cap = 150;
  np::Knapsack kp(cap, elems14);
  for (auto _ : state) {
    kp.BruteForce();
  }
}
BENCHMARK(BruteForce_14);

static void BranchAndBound_14(benchmark::State& state) {
  size_t cap = 150;
  np::Knapsack kp(cap, elems14);
  for (auto _ : state) {
    kp.BranchAndBound();
  }
}
BENCHMARK(BranchAndBound_14);

static void BruteForce_16(benchmark::State& state) {
  size_t cap = 150;
  np::Knapsack kp(cap, elems16);
  for (auto _ : state) {
    kp.BruteForce();
  }
}
BENCHMARK(BruteForce_16);

static void BranchAndBound_16(benchmark::State& state) {
  size_t cap = 150;
  np::Knapsack kp(cap, elems16);
  for (auto _ : state) {
    kp.BranchAndBound();
  }
}
BENCHMARK(BranchAndBound_16);

static void BruteForce_18(benchmark::State& state) {
  size_t cap = 150;
  np::Knapsack kp(cap, elems18);
  for (auto _ : state) {
    kp.BruteForce();
  }
}
BENCHMARK(BruteForce_18);

static void BranchAndBound_18(benchmark::State& state) {
  size_t cap = 150;
  np::Knapsack kp(cap, elems18);
  for (auto _ : state) {
    kp.BranchAndBound();
  }
}
BENCHMARK(BranchAndBound_18);

static void BruteForce_20(benchmark::State& state) {
  size_t cap = 150;
  np::Knapsack kp(cap, elems20);
  for (auto _ : state) {
    kp.BruteForce();
  }
}
BENCHMARK(BruteForce_20);

static void BranchAndBound_20(benchmark::State& state) {
  size_t cap = 150;
  np::Knapsack kp(cap, elems20);
  for (auto _ : state) {
    kp.BranchAndBound();
  }
}
BENCHMARK(BranchAndBound_20);

static void BruteForce_22(benchmark::State& state) {
  size_t cap = 150;
  np::Knapsack kp(cap, elems22);
  for (auto _ : state) {
    kp.BruteForce();
  }
}
BENCHMARK(BruteForce_22);

static void BranchAndBound_22(benchmark::State& state) {
  size_t cap = 150;
  np::Knapsack kp(cap, elems22);
  for (auto _ : state) {
    kp.BranchAndBound();
  }
}
BENCHMARK(BranchAndBound_22);

static void BruteForce_24(benchmark::State& state) {
  size_t cap = 150;
  np::Knapsack kp(cap, elems24);
  for (auto _ : state) {
    kp.BruteForce();
  }
}
BENCHMARK(BruteForce_24);

static void BranchAndBound_24(benchmark::State& state) {
  size_t cap = 150;
  np::Knapsack kp(cap, elems24);
  for (auto _ : state) {
    kp.BranchAndBound();
  }
}
BENCHMARK(BranchAndBound_24);

BENCHMARK_MAIN();
