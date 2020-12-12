#include "../../clique/clique.hpp"
#include "../../clique/graph.hpp"
#include "../../clique/graph_generator.hpp"
#include "gtest/gtest.h"

#include <algorithm>
#include <vector>

TEST(CliqueTest, clique) {
  graph::Graph graph;

  graph.addVertex(0);
  graph.addVertex(1);
  graph.addEdge(0, 1);
  EXPECT_TRUE(isClique(graph));
  EXPECT_EQ(graph::maxCliqueBruteForce(graph), 2);

  graph.addVertex(2);
  graph.addEdge(1, 2);
  EXPECT_FALSE(isClique(graph));
  EXPECT_EQ(graph::maxCliqueBruteForce(graph), 2);

  graph.addEdge(2, 0);
  EXPECT_TRUE(isClique(graph));
  EXPECT_EQ(graph::maxCliqueBruteForce(graph), 3);

  graph.addVertex(3);
  graph.addEdge(3, 0);
  EXPECT_EQ(graph::maxCliqueBruteForce(graph), 3);
}

TEST(CliqueTest, BruteForceSolver) {
  {
    auto graph = graph::graphWithClique(5, 2);
    EXPECT_EQ(graph::maxCliqueBruteForce(graph), 2);
  }

  {
    auto graph = graph::graphWithClique(5, 3);
    EXPECT_EQ(graph::maxCliqueBruteForce(graph), 3);
  }

  {
    auto graph = graph::graphWithClique(5, 4);
    EXPECT_EQ(graph::maxCliqueBruteForce(graph), 4);
  }

  {
    auto graph = graph::graphWithClique(5, 5);
    EXPECT_EQ(graph::maxCliqueBruteForce(graph), 5);
  }
}

TEST(CliqueTest, OptimalSolver) {
    {
    auto graph = graph::graphWithClique(5, 2);
    EXPECT_EQ(graph::maxClique(graph), 2);
  }

  {
    auto graph = graph::graphWithClique(5, 3);
    EXPECT_EQ(graph::maxClique(graph), 3);
  }

  {
    auto graph = graph::graphWithClique(5, 4);
    EXPECT_EQ(graph::maxClique(graph), 4);
  }

  {
    auto graph = graph::graphWithClique(5, 5);
    EXPECT_EQ(graph::maxClique(graph), 5);
  }

}
