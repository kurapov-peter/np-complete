set(SOURCE_EXE ./src/knapsack_bench.cpp)

set(SOURCE_LIB1 src/knapsack.cpp)
set(SOURCE_LIB2 src/test_generator.cpp)

add_library(knapsack_lib1 STATIC ${SOURCE_LIB1})
add_library(knapsack_lib2 STATIC ${SOURCE_LIB2})

set_target_properties(knapsack_lib2 PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS ON
)

add_executable(bench ${SOURCE_EXE})

set_target_properties(bench PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS ON
)

target_link_libraries(bench knapsack_lib1 knapsack_lib2 benchmark::benchmark)