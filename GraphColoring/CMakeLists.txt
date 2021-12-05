set(LIBRARY_NAME graph-coloring)
add_library(${LIBRARY_NAME} STATIC "graph.cpp" "greedy_coloring.cpp")
target_compile_features(${LIBRARY_NAME} PUBLIC cxx_std_17)

set(BENCH_NAME coloring-bench)
add_executable(${BENCH_NAME} "bench.cpp")
target_compile_features(${BENCH_NAME} PUBLIC cxx_std_17)
target_link_libraries(${BENCH_NAME} ${LIBRARY_NAME} benchmark::benchmark)

unset(LIBRARY_NAME)
unset(BENCH_NAME)

