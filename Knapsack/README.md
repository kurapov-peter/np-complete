# Knapsack

`BruteForce` and `BranchAndBound` implemetation of knapsack problem.

## Build

mkdir build && cd build
cmake .. && make -jnproc

## Fuctional testing

cd build/tests/
./knapsack_test

## Perfomace testing

cd build/knapsack/
./bench


## Results of perfomance testing Intel(R) Core(TM) i7-6500U CPU @ 2.50GHz

------------------------------------------------------------
Benchmark                  Time             CPU   Iterations
------------------------------------------------------------
BruteForce_10         114332 ns       114315 ns         6043
BranchAndBound_10      30388 ns        30385 ns        22912
BruteForce_15        5229265 ns      5229634 ns          127
BranchAndBound_15     110226 ns       110215 ns         6248
BruteForce_20      203160575 ns    203166153 ns            3
BranchAndBound_20     360968 ns       360972 ns         1966
BruteForce_25     7618288950 ns   7618660180 ns            1
BranchAndBound_25    2135664 ns      2135315 ns          325
