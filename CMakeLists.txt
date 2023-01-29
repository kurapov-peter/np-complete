cmake_minimum_required(VERSION 3.10)

project(np-complete)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(googletest)
add_subdirectory(benchmark)

add_subdirectory(tests)
add_subdirectory(SAT)

add_subdirectory(subset)
add_subdirectory(knight_tour)
add_subdirectory(clique)
add_subdirectory(Knapsack)
add_subdirectory(HamiltonianPathProblem)
add_subdirectory(GraphColoring)
