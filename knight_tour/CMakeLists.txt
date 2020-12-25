set(bench_name knight_bench)
add_executable(${bench_name} knight_bench.cpp knight.cpp)
target_link_libraries(${bench_name} benchmark::benchmark)

unset(bench_name)
