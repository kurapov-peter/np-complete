# set(bench_name knapsack)
# add_executable(${bench_name} sat_bench.cpp)
# target_link_libraries(${bench_name} benchmark::benchmark)

set(SOURCE_EXE ./src/knapsack_bench.cpp)

set(SOURCE_LIB ./src/knapsack.cpp)

add_library(knapsack STATIC ${SOURCE_LIB})

add_executable(bench ${SOURCE_EXE})

set_target_properties(bench PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS ON
)

target_link_libraries(bench knapsack benchmark::benchmark)