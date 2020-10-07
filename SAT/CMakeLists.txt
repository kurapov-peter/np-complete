set(bench_name sat_bench)
add_executable(${bench_name} sat_bench.cpp)
target_link_libraries(${bench_name} benchmark::benchmark)