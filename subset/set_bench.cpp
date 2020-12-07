#include "benchmark/benchmark.h"
#include "SSet.h"

#include <iostream>
#include <sstream>

static void BM_subsetBrute(benchmark::State& state) {
    SSet set;
    for (int n=1; n<100; n++)
    {
        set.addElement(n);
    }
    set.addElement(-101);
    for (auto _ : state)
    {
        set.checkZeroSumSlow();
    }
}


BENCHMARK(BM_subsetBrute);
BENCHMARK_MAIN();
