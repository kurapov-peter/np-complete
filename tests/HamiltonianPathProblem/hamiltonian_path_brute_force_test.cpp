#include <gtest/gtest.h>

#include <cstdlib>
#include <sstream>

#include "../../HamiltonianPathProblem/hamiltonian_path_brute_force_solver.h"

void generate_consistent_graph_test(size_t vertex_number,
                                    bool is_solution_exist) {
  graph g(vertex_number);
  std::stringstream answer;
  answer << 1;
  if (!is_solution_exist) vertex_number--;
  for (size_t vertex_index = 1; vertex_index < vertex_number; vertex_index++) {
    g.add_edge(vertex_index, vertex_index + 1);
    answer << " -> " << vertex_index + 1;
  }
  hamiltonian_path_brute_force_solver solver(std::move(g));
  solver.solve();
  if (is_solution_exist) {
    EXPECT_TRUE(solver.is_solution_exist());
    EXPECT_EQ(solver.get_solution(), answer.str());
    return;
  }

  EXPECT_FALSE(solver.is_solution_exist());
}

void generate_fully_connected_graph_test(size_t vertex_number) {
  graph g(vertex_number);
  for (size_t outcoming = 1; outcoming < vertex_number; outcoming++) {
    for (size_t incoming = 1; incoming < vertex_number; incoming++) {
      g.add_edge(outcoming, incoming);
    }
  }
  hamiltonian_path_brute_force_solver solver(std::move(g));
  solver.solve();
  EXPECT_FALSE(solver.is_solution_exist());
}

TEST(HamiltonianPathBruteForceSolver, SmallGraphTest) {
  graph g(2);
  g.add_edge(1, 2);
  hamiltonian_path_brute_force_solver solver(std::move(g));
  solver.solve();
  EXPECT_TRUE(solver.is_solution_exist());
}

TEST(HamiltonianPathBruteForceSolver, SingleVertexGraphTest) {
  graph g(1);
  hamiltonian_path_brute_force_solver solver(std::move(g));
  solver.solve();
  EXPECT_TRUE(solver.is_solution_exist());
}

TEST(HamiltonianPathBruteForceSolver, SingleVertexOneLoopGraphTest) {
  graph g(1);
  g.add_edge(1, 1);
  hamiltonian_path_brute_force_solver solver(std::move(g));
  solver.solve();
  EXPECT_TRUE(solver.is_solution_exist());
}

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

TEST(ConsistentGraphWithSolutionTest, Consistent100Test) {
  generate_consistent_graph_test(100, true);
}

TEST(ConsistentGraphWithoutSolutionTest, Consistent10Test) {
  generate_consistent_graph_test(20, false);
}

TEST(FullyConnectedGraphTest, FullyConnected10Test) {
  generate_fully_connected_graph_test(11);
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