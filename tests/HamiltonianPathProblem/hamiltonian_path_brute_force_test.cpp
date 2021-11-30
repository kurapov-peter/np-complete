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

TEST(ConsistentGraphWithSolutionTest, Consistent5Test) {
  generate_consistent_graph_test(5, true);
}
TEST(ConsistentGraphWithSolutionTest, Consistent6Test) {
  generate_consistent_graph_test(6, true);
}
TEST(ConsistentGraphWithSolutionTest, Consistent7Test) {
  generate_consistent_graph_test(7, true);
}
TEST(ConsistentGraphWithSolutionTest, Consistent8Test) {
  generate_consistent_graph_test(8, true);
}
TEST(ConsistentGraphWithSolutionTest, Consistent9Test) {
  generate_consistent_graph_test(9, true);
}
TEST(ConsistentGraphWithSolutionTest, Consistent10Test) {
  generate_consistent_graph_test(10, true);
}
TEST(ConsistentGraphWithSolutionTest, Consistent11Test) {
  generate_consistent_graph_test(11, true);
}
TEST(ConsistentGraphWithSolutionTest, Consistent12Test) {
  generate_consistent_graph_test(12, true);
}
TEST(ConsistentGraphWithSolutionTest, Consistent13Test) {
  generate_consistent_graph_test(13, true);
}
TEST(ConsistentGraphWithSolutionTest, Consistent14Test) {
  generate_consistent_graph_test(14, true);
}
TEST(ConsistentGraphWithSolutionTest, Consistent15Test) {
  generate_consistent_graph_test(15, true);
}
TEST(ConsistentGraphWithSolutionTest, Consistent16Test) {
  generate_consistent_graph_test(16, true);
}
TEST(ConsistentGraphWithSolutionTest, Consistent17Test) {
  generate_consistent_graph_test(17, true);
}
TEST(ConsistentGraphWithSolutionTest, Consistent18Test) {
  generate_consistent_graph_test(18, true);
}
TEST(ConsistentGraphWithSolutionTest, Consistent19Test) {
  generate_consistent_graph_test(19, true);
}
TEST(ConsistentGraphWithSolutionTest, Consistent20Test) {
  generate_consistent_graph_test(20, true);
}
TEST(ConsistentGraphWithSolutionTest, Consistent21Test) {
  generate_consistent_graph_test(21, true);
}
TEST(ConsistentGraphWithSolutionTest, Consistent22Test) {
  generate_consistent_graph_test(22, true);
}
TEST(ConsistentGraphWithSolutionTest, Consistent23Test) {
  generate_consistent_graph_test(23, true);
}
TEST(ConsistentGraphWithSolutionTest, Consistent24Test) {
  generate_consistent_graph_test(24, true);
}
TEST(ConsistentGraphWithSolutionTest, Consistent25Test) {
  generate_consistent_graph_test(25, true);
}


TEST(ConsistentGraphWithoutSolutionTest, Consistent5Test) {
  generate_consistent_graph_test(5, false);
}
TEST(ConsistentGraphWithoutSolutionTest, Consistent6Test) {
  generate_consistent_graph_test(6, false);
}
TEST(ConsistentGraphWithoutSolutionTest, Consistent7Test) {
  generate_consistent_graph_test(7, false);
}
TEST(ConsistentGraphWithoutSolutionTest, Consistent8Test) {
  generate_consistent_graph_test(8, false);
}
TEST(ConsistentGraphWithoutSolutionTest, Consistent9Test) {
  generate_consistent_graph_test(9, false);
}
TEST(ConsistentGraphWithoutSolutionTest, Consistent10Test) {
  generate_consistent_graph_test(10, false);
}
TEST(ConsistentGraphWithoutSolutionTest, Consistent11Test) {
  generate_consistent_graph_test(11, false);
}
TEST(ConsistentGraphWithoutSolutionTest, Consistent12Test) {
  generate_consistent_graph_test(12, false);
}
TEST(ConsistentGraphWithoutSolutionTest, Consistent13Test) {
  generate_consistent_graph_test(13, false);
}
TEST(ConsistentGraphWithoutSolutionTest, Consistent14Test) {
  generate_consistent_graph_test(14, false);
}
TEST(ConsistentGraphWithoutSolutionTest, Consistent15Test) {
  generate_consistent_graph_test(15, false);
}
TEST(ConsistentGraphWithoutSolutionTest, Consistent16Test) {
  generate_consistent_graph_test(16, false);
}
TEST(ConsistentGraphWithoutSolutionTest, Consistent17Test) {
  generate_consistent_graph_test(17, false);
}
TEST(ConsistentGraphWithoutSolutionTest, Consistent18Test) {
  generate_consistent_graph_test(18, false);
}
TEST(ConsistentGraphWithoutSolutionTest, Consistent19Test) {
  generate_consistent_graph_test(19, false);
}
TEST(ConsistentGraphWithoutSolutionTest, Consistent20Test) {
  generate_consistent_graph_test(20, false);
}
TEST(ConsistentGraphWithoutSolutionTest, Consistent21Test) {
  generate_consistent_graph_test(21, false);
}
TEST(ConsistentGraphWithoutSolutionTest, Consistent22Test) {
  generate_consistent_graph_test(22, false);
}
TEST(ConsistentGraphWithoutSolutionTest, Consistent23Test) {
  generate_consistent_graph_test(23, false);
}
TEST(ConsistentGraphWithoutSolutionTest, Consistent24Test) {
  generate_consistent_graph_test(24, false);
}
TEST(ConsistentGraphWithoutSolutionTest, Consistent25Test) {
  generate_consistent_graph_test(25, false);
}


TEST(FullyConnectedGraphTest, FullyConnected2Test) {
  generate_fully_connected_graph_test(2);
}
TEST(FullyConnectedGraphTest, FullyConnected3Test) {
  generate_fully_connected_graph_test(3);
}
TEST(FullyConnectedGraphTest, FullyConnected4Test) {
  generate_fully_connected_graph_test(4);
}
TEST(FullyConnectedGraphTest, FullyConnected5Test) {
  generate_fully_connected_graph_test(5);
}
TEST(FullyConnectedGraphTest, FullyConnected6Test) {
  generate_fully_connected_graph_test(6);
}
TEST(FullyConnectedGraphTest, FullyConnected7Test) {
  generate_fully_connected_graph_test(7);
}
TEST(FullyConnectedGraphTest, FullyConnected8Test) {
  generate_fully_connected_graph_test(8);
}
TEST(FullyConnectedGraphTest, FullyConnected9Test) {
  generate_fully_connected_graph_test(9);
}
TEST(FullyConnectedGraphTest, FullyConnected10Test) {
  generate_fully_connected_graph_test(10);
}
TEST(FullyConnectedGraphTest, FullyConnected11Test) {
  generate_fully_connected_graph_test(11);
}
TEST(FullyConnectedGraphTest, FullyConnected12Test) {
  generate_fully_connected_graph_test(12);
}
TEST(FullyConnectedGraphTest, FullyConnected13Test) {
  generate_fully_connected_graph_test(13);
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