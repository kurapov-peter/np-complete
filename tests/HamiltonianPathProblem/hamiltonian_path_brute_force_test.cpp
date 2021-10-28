#include <gtest/gtest.h>
#include "../../../HamiltonianPathProblem/hamiltonian_path_brute_force_solver.h"
#include <sstream>
#include <cstdlib>

TEST(HamiltonianPathBruteForceSolver, SolutionExistsTest) {
    graph g(3);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    hamiltonian_path_brute_force_solver solver(std::move(g));
    solver.solve();
    EXPECT_TRUE(solver.is_solution_exist());
}

TEST(HamiltonianPathBruteForceSolver, SolutionDoesNotExistTest) {
    graph g(3);
    g.add_edge(1, 2);
    hamiltonian_path_brute_force_solver solver(std::move(g));
    solver.solve();
    EXPECT_FALSE(solver.is_solution_exist());
}

TEST(HamiltonianPathBruteForceSolver, FillNextVertexTest) {
    graph g(3);
    g.add_edge(1, 2);
    hamiltonian_path_brute_force_solver solver(std::move(g));
    solver.solution[1] = 1;
    solver.fill_next_vertex(2);
    EXPECT_EQ(solver.solution[2], 2);
    solver.fill_next_vertex(3);
    EXPECT_EQ(solver.solution[3], 0);
}

TEST(HamiltonianPathBruteForceSolver, SolveFromVertexTest) {
    graph g(3);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    hamiltonian_path_brute_force_solver solver(std::move(g));
    solver.solution[1] = 1;
    solver.solve_from_vertex(2);
    EXPECT_EQ(solver.solution[2], 2);
    EXPECT_EQ(solver.solution[3], 3);
}

TEST(HamiltonianPathBruteForceSolver, SolverFullTest1) {
    graph g(10000);
    std::stringstream answer;
    answer << 1;
    for (int i = 1; i < 10000; i++) {
        g.add_edge(i, i+1);
        answer << " -> " << i+1;
    }
    hamiltonian_path_brute_force_solver solver(std::move(g));
    solver.solve();
    EXPECT_TRUE(solver.is_solution_exist());
    EXPECT_EQ(solver.get_solution(), answer.str());
}

TEST(HamiltonianPathBruteForceSolver, SolverFullTest2) {
    graph g(1000);
    for (int i = 1; i < 999; i++) {
        g.add_edge(i, i+1);
    }
    hamiltonian_path_brute_force_solver solver(std::move(g));
    solver.solve();
    EXPECT_FALSE(solver.is_solution_exist());
}

TEST(HamiltonianPathBruteForceSolver, SolverRandomTest) {
    graph g(1000);
    for (int i = 1; i < 999; i++) {
        g.add_edge(std::rand() % 1001, std::rand() % 1001);
    }
    hamiltonian_path_brute_force_solver solver(std::move(g));
    solver.solve();
    EXPECT_FALSE(solver.is_solution_exist());
}