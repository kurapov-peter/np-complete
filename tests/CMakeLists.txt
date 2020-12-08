set(test_list run_all.cpp
    sat/parser_tests.cpp    
)

add_executable(tests ${test_list})
target_link_libraries(tests gtest)


set(knapsack_test Knapsack/knapsack_gtest.cpp
    Knapsack/run_knapsack.cpp
)

set(SOURCE_LIB ../Knapsack/src/knapsack.cpp)

add_library(knapsack_lib STATIC ${SOURCE_LIB})

add_executable(run_knapsack_test ${knapsack_test})

set_target_properties(run_knapsack_test PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS ON
)

target_link_libraries(run_knapsack_test gtest knapsack_lib)

enable_testing()

add_test(CNFParserTest "./tests")