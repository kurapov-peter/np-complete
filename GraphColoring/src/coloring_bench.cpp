#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <unordered_map>

#include "graph.h"

#include "benchmark/benchmark.h"

static const std::unordered_map<std::size_t, std::string> trace_mapping = {
    {4, "../GraphColoring/traces/input_fc_v4.txt"},
    {5, "../GraphColoring/traces/input_fc_v5.txt"},
    {6, "../GraphColoring/traces/input_fc_v6.txt"},
    {7, "../GraphColoring/traces/input_fc_v7.txt"},
    {8, "../GraphColoring/traces/input_fc_v8.txt"},
    {9, "../GraphColoring/traces/input_fc_v9.txt"},
    {10, "../GraphColoring/traces/input_fc_v10.txt"}
};

static std::unordered_map<std::size_t, Graph> graph_mapping;

class GraphBenchmarkFixture : public benchmark::Fixture
{
public:
    void SetUp([[maybe_unused]]const ::benchmark::State& state)
    {
        for (const auto [num_colors, trace] : trace_mapping)
        {
            std::ifstream ifs(trace);
            ifs >> graph_mapping[num_colors];
        }
    }

    void TearDown([[maybe_unused]]const ::benchmark::State& state) {}
};



static int get_chromatic_number(std::size_t num_vertices, bool use_brute_force = false)
{
    const auto graph = graph_mapping.at(num_vertices);

    [[maybe_unused]] std::size_t chromatic_number;

    if (use_brute_force)
        chromatic_number = graph.brute_force_chromatic_number();
    else
        chromatic_number = graph.lawler_chromatic_number();

    return EXIT_SUCCESS;
}


BENCHMARK_DEFINE_F(GraphBenchmarkFixture, GraphColoring_BruteForceChromaticNumber)(benchmark::State& state) {
    for (auto _ : state) {
        get_chromatic_number(state.range(0), true);
    }
}

BENCHMARK_DEFINE_F(GraphBenchmarkFixture, GraphColoring_LawlerChromaticNumber)(benchmark::State& state) {
    for (auto _ : state) {
        get_chromatic_number(state.range(0), false);
    }
}


BENCHMARK_REGISTER_F(GraphBenchmarkFixture,
                     GraphColoring_BruteForceChromaticNumber)->DenseRange(4, 10, 1);
BENCHMARK_REGISTER_F(GraphBenchmarkFixture,
                     GraphColoring_LawlerChromaticNumber)->DenseRange(4, 10, 1);

BENCHMARK_MAIN();