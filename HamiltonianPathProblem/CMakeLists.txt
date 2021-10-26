set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
add_compile_options(-g -Wall -Wextra -Werror)

set(bench_name hamiltonian_path_bench)
add_executable(${bench_name} main.cpp graph.cpp hamiltonian_path_brute_force_solver.cpp)

unset(bench_name)