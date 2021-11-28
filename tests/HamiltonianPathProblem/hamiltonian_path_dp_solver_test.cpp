#include "../../HamiltonianPathProblem/hamiltonian_path_dp_solver.h"

#include <gtest/gtest.h>

#include <cstdlib>
#include <sstream>

graph generate_graph(size_t vertex_number) {
  graph g(vertex_number + 1);
  for (size_t vertex = 0; vertex < vertex_number; vertex++) {
    g.add_edge(vertex + 1, vertex_number + 1);
    g.add_edge(vertex_number + 1, vertex + 1);
  }
  return g;
}

void generate_consistent_graph_test(size_t vertex_number,
                                    bool is_solution_exist) {
  graph g = generate_graph(vertex_number);
  std::stringstream answer;
  answer << 1;
  if (!is_solution_exist) vertex_number--;
  for (size_t vertex_index = 1; vertex_index < vertex_number; vertex_index++) {
    g.add_edge(vertex_index, vertex_index + 1);
    answer << ' ' << vertex_index + 1;
  }
  answer << ' ';
  hamiltonian_path_dp_solver solver(std::move(g));
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
  hamiltonian_path_dp_solver solver(std::move(g));
  solver.solve();
  EXPECT_FALSE(solver.is_solution_exist());
}

TEST(HamiltonianPathBruteForceSolver, SmallGraphTest) {
  graph g = generate_graph(2);
  g.add_edge(1, 2);
  hamiltonian_path_dp_solver solver(std::move(g));
  solver.solve();
  EXPECT_TRUE(solver.is_solution_exist());
}

TEST(HamiltonianPathBruteForceSolver, SingleVertexGraphTest) {
  graph g = generate_graph(1);
  hamiltonian_path_dp_solver solver(std::move(g));
  solver.solve();
  EXPECT_TRUE(solver.is_solution_exist());
}

TEST(HamiltonianPathBruteForceSolver, SingleVertexOneLoopGraphTest) {
  graph g = generate_graph(1);
  g.add_edge(1, 1);
  hamiltonian_path_dp_solver solver(std::move(g));
  solver.solve();
  EXPECT_TRUE(solver.is_solution_exist());
}

TEST(HamiltonianPathBruteForceSolver, SolutionExistsTest) {
  graph g = generate_graph(3);
  g.add_edge(1, 2);
  g.add_edge(2, 3);
  hamiltonian_path_dp_solver solver(std::move(g));
  solver.solve();
  EXPECT_TRUE(solver.is_solution_exist());
}

TEST(HamiltonianPathBruteForceSolver, SolutionDoesNotExistTest) {
  graph g = generate_graph(3);
  g.add_edge(1, 2);
  hamiltonian_path_dp_solver solver(std::move(g));
  solver.solve();
  EXPECT_FALSE(solver.is_solution_exist());
}

TEST(ConsistentGraphWithSolutionTest, Consistent10Test) {
  generate_consistent_graph_test(10, true);
}

TEST(ConsistentGraphWithoutSolutionTest, Consistent10Test) {
  generate_consistent_graph_test(10, false);
}

TEST(FullyConnectedGraphTest, FullyConnected10Test) {
  generate_fully_connected_graph_test(10);
}
