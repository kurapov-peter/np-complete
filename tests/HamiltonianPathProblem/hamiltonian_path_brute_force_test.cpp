#include <gtest/gtest.h>
#include "../../../HamiltonianPathProblem/hamiltonian_path_brute_force_solver.h"

TEST(TrivialTest, TrivialTest) {
  graph test_graph(3);
  test_graph.add_edge(1, 2);
  test_graph.add_edge(2, 3);
  hamiltonian_path_brute_force_solver solver(std::move(test_graph));
  solver.solve();
  EXPECT_TRUE(solver.is_solution_exist());
}
