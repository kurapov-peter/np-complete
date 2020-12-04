#include "../../clique/clique.hpp"
#include "../../clique/graph.hpp"
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
  // TODO independent way of loading graph
  {
    graph::Graph graph;
    graph.load("../clique/inputs/test_clique.2.in");
    EXPECT_EQ(graph::maxCliqueBruteForce(graph), 2);
  }

  {
    graph::Graph graph;
    graph.load("../clique/inputs/test_clique.3.in");
    EXPECT_EQ(graph::maxCliqueBruteForce(graph), 3);
  }

  {
    graph::Graph graph;
    graph.load("../clique/inputs/test_clique.4.in");
    EXPECT_EQ(graph::maxCliqueBruteForce(graph), 4);
  }

  {
    graph::Graph graph;
    graph.load("../clique/inputs/test_clique.5.in");
    EXPECT_EQ(graph::maxCliqueBruteForce(graph), 5);
  }
}

TEST(CliqueTest, OptimalSolver) {
  // TODO independent way of loading graph
  {
    graph::Graph graph;
    graph.load("../clique/inputs/test_clique.2.in");
    EXPECT_EQ(graph::maxClique(graph), 2);
  }

  {
    graph::Graph graph;
    graph.load("../clique/inputs/test_clique.3.in");
    EXPECT_EQ(graph::maxClique(graph), 3);
  }

  {
    graph::Graph graph;
    graph.load("../clique/inputs/test_clique.4.in");
    EXPECT_EQ(graph::maxClique(graph), 4);
  }

  {
    graph::Graph graph;
    graph.load("../clique/inputs/test_clique.5.in");
    EXPECT_EQ(graph::maxClique(graph), 5);
  }
}
