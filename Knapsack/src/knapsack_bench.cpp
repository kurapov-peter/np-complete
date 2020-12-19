#include <iostream>
#include "../includes/knapsack.h"
#include "benchmark/benchmark.h"

static void BruteForce_10(benchmark::State& state) {
  std::ifstream input;
  input.open("../../Knapsack/data/ip_10.txt");

  auto [cap, elems] = np::Knapsack::GetInput(input);
  np::Knapsack kp(cap, elems);

  for (auto _ : state) {
    kp.BruteForce();
  }

  input.close();
}
BENCHMARK(BruteForce_10);

static void BranchAndBound_10(benchmark::State& state) {
  std::ifstream input;
  input.open("../../Knapsack/data/ip_10.txt");

  auto [cap, elems] = np::Knapsack::GetInput(input);
  np::Knapsack kp(cap, elems);

  for (auto _ : state) {
    kp.BranchAndBound();
  }

  input.close();
}
BENCHMARK(BranchAndBound_10);

static void BruteForce_15(benchmark::State& state) {
  std::ifstream input;
  input.open("../../Knapsack/data/ip_15.txt");
  
  auto [cap, elems] = np::Knapsack::GetInput(input);
  np::Knapsack kp(cap, elems);

  for (auto _ : state) {
    kp.BruteForce();
  }

  input.close();
}
BENCHMARK(BruteForce_15);

static void BranchAndBound_15(benchmark::State& state) {
  std::ifstream input;
  input.open("../../Knapsack/data/ip_15.txt");

  auto [cap, elems] = np::Knapsack::GetInput(input);
  np::Knapsack kp(cap, elems);

  for (auto _ : state) {
    kp.BranchAndBound();
  }

  input.close();
}
BENCHMARK(BranchAndBound_15);

static void BruteForce_20(benchmark::State& state) {
  std::ifstream input;
  input.open("../../Knapsack/data/ip_20.txt");

  auto [cap, elems] = np::Knapsack::GetInput(input);
  np::Knapsack kp(cap, elems);

  for (auto _ : state) {
    kp.BruteForce();
  }

  input.close();
}
BENCHMARK(BruteForce_20);

static void BranchAndBound_20(benchmark::State& state) {
  std::ifstream input;
  input.open("../../Knapsack/data/ip_20.txt");

  auto [cap, elems] = np::Knapsack::GetInput(input);
  np::Knapsack kp(cap, elems);

  for (auto _ : state) {
    kp.BranchAndBound();
  }

  input.close();
}
BENCHMARK(BranchAndBound_20);

static void BruteForce_25(benchmark::State& state) {
  std::ifstream input;
  input.open("../../Knapsack/data/ip_25.txt");
  
  auto [cap, elems] = np::Knapsack::GetInput(input);
  np::Knapsack kp(cap, elems);

  for (auto _ : state) {
    kp.BruteForce();
  }

  input.close();
}
BENCHMARK(BruteForce_25);

static void BranchAndBound_25(benchmark::State& state) {
  std::ifstream input;
  input.open("../../Knapsack/data/ip_25.txt");
  
  auto [cap, elems] = np::Knapsack::GetInput(input);
  np::Knapsack kp(cap, elems);

  for (auto _ : state) {
    kp.BranchAndBound();
  }

  input.close();
}
BENCHMARK(BranchAndBound_25);

BENCHMARK_MAIN();
