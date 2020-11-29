
set(SOURCE_CLIQUE   graph.cpp
                    clique.cpp)

add_library(clique ${SOURCE_CLIQUE})

set(bench_name clique_bench)
add_executable(${bench_name} clique_bench.cpp)

#target_link_libraries(${bench_name} clique)
target_link_libraries(${bench_name} clique benchmark::benchmark)
