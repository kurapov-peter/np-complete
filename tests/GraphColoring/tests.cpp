#include <gtest/gtest.h>
#include <vector>
#include "../../GraphColoring/graph.hpp"
#include "../../GraphColoring/graph_coloring.hpp"

class ColoringTest : public ::testing::Test {
protected:
  void SetUp() override {
    for (size_t N: {1, 10, 100}) {
      graphs_.push_back(coloring::GetCompleteGraph(N));
      graphs_.push_back(coloring::GetAcyclicGraph(N));
      graphs_.push_back(coloring::GetBipartiteGraph(N, N));
    }
  }
  std::vector<coloring::Graph> graphs_;
};

TEST_F(ColoringTest, GreedyColoring) {
  for (auto &G: graphs_) {
    coloring::GreedyColoring(G);
    EXPECT_TRUE(G.checkColoring());
  }
}
