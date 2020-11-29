#include "../../clique/graph.hpp"
#include "../../clique/clique.hpp"
#include "gtest/gtest.h"

#include <algorithm>
#include <vector>

TEST(CliqueTest, GraphTest) {
  graph::Graph graph;

  std::vector<graph::Vertex> vertices = {0, 1, 2, 3};
  for (auto v : vertices) graph.addVertex(v);
  EXPECT_TRUE(graph.validate());

  graph.addEdge(0, 1);
  graph.addEdge(1, 2);
  graph.addEdge(2, 0);
  graph.addEdge(3, 0);
  EXPECT_TRUE(graph.validate());

  EXPECT_TRUE(graph.isAdjacent(0, 1));
  EXPECT_TRUE(graph.isAdjacent(1, 2));
  EXPECT_TRUE(graph.isAdjacent(2, 0));
  EXPECT_TRUE(graph.isAdjacent(3, 0));

  EXPECT_FALSE(graph.isAdjacent(3, 1));
  EXPECT_FALSE(graph.isAdjacent(3, 2));

  auto verts = graph.vertices();
  std::sort(verts.begin(), verts.end());
  EXPECT_TRUE(verts == vertices);

  auto adjList = graph.adjacentList(0);
  std::list<graph::Vertex> expected = {1, 2, 3};
  adjList.sort();
  EXPECT_TRUE(adjList == expected);

  graph.removeVertex(3);
  EXPECT_TRUE(graph.validate());
  EXPECT_FALSE(graph.isAdjacent(0, 3));
  EXPECT_FALSE(graph.isAdjacent(3, 0));

  graph.removeEdge(0, 1);
  EXPECT_TRUE(graph.validate());
  EXPECT_FALSE(graph.isAdjacent(0, 1));
  EXPECT_FALSE(graph.isAdjacent(1, 0));
}

TEST(CliqueTest, clique) {
  graph::Graph graph;

  graph.addVertex(0);
  graph.addVertex(1);
  graph.addEdge(0, 1);
  EXPECT_TRUE(isClique(graph));
  EXPECT_EQ(graph::maxCliqueNaive(graph), 2);

  graph.addVertex(2);
  graph.addEdge(1, 2);
  EXPECT_FALSE(isClique(graph));
  EXPECT_EQ(graph::maxCliqueNaive(graph), 2);

  graph.addEdge(2, 0);
  EXPECT_TRUE(isClique(graph));
  EXPECT_EQ(graph::maxCliqueNaive(graph), 3);

  graph.addVertex(3);
  graph.addEdge(3, 0);
  EXPECT_EQ(graph::maxCliqueNaive(graph), 3);
}

TEST(CliqueTest, cliqueTest) {
  // TODO independent way of loading graph
  {
    graph::Graph graph;
    graph.load("../clique/inputs/test_clique.2.in");
    EXPECT_EQ(graph::maxCliqueNaive(graph), 2);
  }

  {
    graph::Graph graph;
    graph.load("../clique/inputs/test_clique.3.in");
    EXPECT_EQ(graph::maxCliqueNaive(graph), 3);
  }

  {
    graph::Graph graph;
    graph.load("../clique/inputs/test_clique.4.in");
    EXPECT_EQ(graph::maxCliqueNaive(graph), 4);
  }

  {
    graph::Graph graph;
    graph.load("../clique/inputs/test_clique.5.in");
    EXPECT_EQ(graph::maxCliqueNaive(graph), 5);
  }
}
