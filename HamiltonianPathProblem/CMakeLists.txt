set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
add_compile_options(-g -Wall -Wextra -Werror)

set(bench_name_bf hamiltonian_path_bf_bench)
set(bench_name_dp hamiltonian_path_dp_bench)
add_executable(${bench_name_dp} dp_solution.cpp graph.cpp hamiltonian_path_dp_solver.cpp)
add_executable(${bench_name_bf} bf_solution.cpp graph.cpp hamiltonian_path_brute_force_solver.cpp)

unset(bench_name_bf)
unset(bench_name_dp)