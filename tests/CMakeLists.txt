set(test_list run_all.cpp
    sat/parser_tests.cpp
    knight_tour/knight_tests.cpp
    ../knight_tour/knight.cpp
    clique/graph_test.cpp
    clique/clique_test.cpp
    subset/bruteforce.cpp
    subset/optimized.cpp
    subset/optHS.cpp
)

add_executable(tests ${test_list})
target_link_libraries(tests gtest clique sset)

set(knapsack_test Knapsack/src/knapsack_gtest.cpp
    Knapsack/src/run_knapsack.cpp
)

set(SOURCE_LIB1 ../Knapsack/src/knapsack.cpp) 
set(SOURCE_LIB2 ../Knapsack/src/test_generator.cpp)

add_library(source_lib1 STATIC ${SOURCE_LIB1})
add_library(source_lib2 STATIC ${SOURCE_LIB2})

set_target_properties(source_lib2 PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS ON
)

add_executable(run_knapsack_test ${knapsack_test})

set_target_properties(run_knapsack_test PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS ON
)

target_link_libraries(run_knapsack_test gtest source_lib1 source_lib2)

add_executable(run_graph_test ../HamiltonianPathProblem/graph.cpp HamiltonianPathProblem/graph_test.cpp)
target_link_libraries(run_graph_test gtest gmock gmock_main)

add_executable(run_hamiltonian_path_brute_force_test ../HamiltonianPathProblem/graph.cpp ../HamiltonianPathProblem/hamiltonian_path_brute_force_solver.cpp HamiltonianPathProblem/hamiltonian_path_brute_force_test.cpp)
target_link_libraries(run_hamiltonian_path_brute_force_test  gtest gmock gmock_main)

enable_testing()

add_test(CNFParserTest "./tests")
add_test(KnightTest "./tests")
add_test(CliqueTest "./tests")
# FIXME
add_test(BruteForce "./tests")
add_test(Optimized "./tests")
