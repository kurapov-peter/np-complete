
#include "benchmark/benchmark.h"
#include "graph.hpp"
#include "clique.hpp"

#include <iostream>
#include <sstream>

static void BM_cliqueNaive(benchmark::State& state) {
    graph::Graph graph;
    //TODO independent way of loading graph
    graph.load("../clique/inputs/benchmark.in");
    for (auto _ : state) {
        graph::maxCliqueNaive(graph);
    }
}

BENCHMARK(BM_cliqueNaive);
BENCHMARK_MAIN();
