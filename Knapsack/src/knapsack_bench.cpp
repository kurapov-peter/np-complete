// Copyright 2020 Ragimov Islam, Pogotovsky Pavel

#include <iostream>
#include "../includes/knapsack.h"
#include "benchmark/benchmark.h"


static void BruteForce_10(benchmark::State& state) {
    auto[cap, elems] = np::Knapsack::GetInput("../../Knapsack/data/ip_10.txt");
    np::Knapsack kp(cap, elems);

    for (auto _ : state) {
        kp.BruteForce();
    }
}
BENCHMARK(BruteForce_10);

static void BranchAndBound_10(benchmark::State& state) {
    auto[cap, elems] = np::Knapsack::GetInput("../../Knapsack/data/ip_10.txt");
    np::Knapsack kp(cap, elems);

    for (auto _ : state) {
        kp.BranchAndBound();
    }
}
BENCHMARK(BranchAndBound_10);

static void BruteForce_15(benchmark::State& state) {
    auto[cap, elems] = np::Knapsack::GetInput("../../Knapsack/data/ip_15.txt");
    np::Knapsack kp(cap, elems);

    for (auto _ : state) {
        kp.BruteForce();
    }
}
BENCHMARK(BruteForce_15);

static void BranchAndBound_15(benchmark::State& state) {
    auto[cap, elems] = np::Knapsack::GetInput("../../Knapsack/data/ip_15.txt");
    np::Knapsack kp(cap, elems);

    for (auto _ : state) {
        kp.BranchAndBound();
    }
}
BENCHMARK(BranchAndBound_15);

static void BruteForce_20(benchmark::State& state) {
    auto[cap, elems] = np::Knapsack::GetInput("../../Knapsack/data/ip_20.txt");
    np::Knapsack kp(cap, elems);

    for (auto _ : state) {
        kp.BruteForce();
    }
}
BENCHMARK(BruteForce_20);

static void BranchAndBound_20(benchmark::State& state) {
    auto[cap, elems] = np::Knapsack::GetInput("../../Knapsack/data/ip_20.txt");
    np::Knapsack kp(cap, elems);

    for (auto _ : state) {
        kp.BranchAndBound();
    }
}
BENCHMARK(BranchAndBound_20);

static void BruteForce_25(benchmark::State& state) {
    auto[cap, elems] = np::Knapsack::GetInput("../../Knapsack/data/ip_25.txt");
    np::Knapsack kp(cap, elems);

    for (auto _ : state) {
        kp.BruteForce();
    }
}
BENCHMARK(BruteForce_25);

static void BranchAndBound_25(benchmark::State& state) {
    auto[cap, elems] = np::Knapsack::GetInput("../../Knapsack/data/ip_25.txt");
    np::Knapsack kp(cap, elems);

    for (auto _ : state) {
        kp.BranchAndBound();
    }
}
BENCHMARK(BranchAndBound_25);

BENCHMARK_MAIN();
