#include <gtest/gtest.h>

#include <fstream>
#include <vector>

#include "../../GraphColoring/graph.hpp"
#include "../../GraphColoring/graph_coloring.hpp"

#define DUMP_GRAPH(A)      \
  std::ofstream myDot;     \
  myDot.open("graph.dot"); \
  myDot << A;              \
  myDot.close();

class ColoringTest : public ::testing::Test {
 protected:
  void SetUp() override {
    for (size_t N : {1, 10, 100}) {
      graphs_greedy_.push_back(coloring::GetBipartiteGraph(N, N));
      graphs_greedy_.push_back(coloring::GetAcyclicGraph(N));
      graphs_greedy_.push_back(coloring::GetCompleteGraph(N));

      graphs_dsatur_.push_back(coloring::GetBipartiteGraph(N, N));
      graphs_dsatur_.push_back(coloring::GetAcyclicGraph(N));
      graphs_dsatur_.push_back(coloring::GetCompleteGraph(N));
    }

    for (size_t N : {1, 5, 10}) {
      graphs_bruteforce_.push_back(coloring::GetBipartiteGraph(N, N));
      graphs_bruteforce_.push_back(coloring::GetAcyclicGraph(N));
    }
    for (size_t N : {1, 3, 7}) {
      graphs_bruteforce_.push_back(coloring::GetCompleteGraph(N));
    }
  }
  std::vector<coloring::Graph> graphs_greedy_;
  std::vector<coloring::Graph> graphs_bruteforce_;
  std::vector<coloring::Graph> graphs_dsatur_;
};

TEST_F(ColoringTest, GreedyColoring) {
  for (auto &G : graphs_greedy_) {
    coloring::GreedyColoring(G);
    EXPECT_TRUE(G.checkColoring());
  }
}

TEST_F(ColoringTest, DSaturColoring) {
  for (auto &G: graphs_dsatur_) {
    coloring::DSaturColoring(G);
    EXPECT_TRUE(G.checkColoring());
  }
}

TEST_F(ColoringTest, BruteForceColoring) {
  for (auto &G : graphs_bruteforce_) {
    coloring::BruteForceColoring(G);
    EXPECT_TRUE(G.checkColoring());
  }
}
