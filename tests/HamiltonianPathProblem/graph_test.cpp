#include "../../HamiltonianPathProblem/graph.h"

#include <gtest/gtest.h>

TEST(HamiltonianPathProblemGraph, GraphConstructorTest) {
  graph g(2);
  EXPECT_EQ(g.get_size(), 2);
}
TEST(HamiltonianPathProblemGraph, GraphAddEdgeTest) {
  graph g(2);
  EXPECT_FALSE(g.is_incident(1, 2));
  EXPECT_FALSE(g.is_incident(2, 1));
  g.add_edge(1, 2);
  EXPECT_TRUE(g.is_incident(1, 2));
  EXPECT_FALSE(g.is_incident(2, 1));
}

TEST(HamiltonianPathProblemGraph, GraphToStringTest) {
  graph g(5);
  g.add_edge(1, 2);
  g.add_edge(1, 3);
  g.add_edge(2, 1);
  g.add_edge(2, 4);
  g.add_edge(4, 5);
  std::stringstream expected_output;
  expected_output << "5" << std::endl;
  expected_output << "0 0 0 0 0 0 " << std::endl;
  expected_output << "0 0 1 1 0 0 " << std::endl;
  expected_output << "0 1 0 0 1 0 " << std::endl;
  expected_output << "0 0 0 0 0 0 " << std::endl;
  expected_output << "0 0 0 0 0 1 " << std::endl;
  expected_output << "0 0 0 0 0 0 " << std::endl;
  EXPECT_EQ(g.to_string(), expected_output.str());
}
