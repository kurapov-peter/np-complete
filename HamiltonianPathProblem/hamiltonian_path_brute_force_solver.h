#ifndef HAMILTONIANPATHPROBLEM_HAMILTONIAN_PATH_BRUTE_FORCE_SOLVER_H
#define HAMILTONIANPATHPROBLEM_HAMILTONIAN_PATH_BRUTE_FORCE_SOLVER_H


#include <sstream>

#include "graph.h"

#define FRIEND_TEST(test_case_name, test_name)\
friend class test_case_name##_##test_name##_Test

class hamiltonian_path_brute_force_solver {
public:
    explicit hamiltonian_path_brute_force_solver(graph&& graph_to_solve);
    void solve();
    bool is_solution_exist() const { return is_solution_found; }
    std::string get_solution() const;

private:
    graph graph_;
    std::vector<graph::vertex> solution;
    bool is_solution_found = false;

    void fill_next_vertex(graph::vertex current_vertex);
    void solve_from_vertex(graph::vertex starting_vertex);

    FRIEND_TEST(HamiltonianPathBruteForceSolver, FillNextVertexTest);
    FRIEND_TEST(HamiltonianPathBruteForceSolver, SolveFromVertexTest);
};


#endif //HAMILTONIANPATHPROBLEM_HAMILTONIAN_PATH_BRUTE_FORCE_SOLVER_H
