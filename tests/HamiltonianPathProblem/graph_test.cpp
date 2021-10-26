#include <gtest/gtest.h>
#include "../../../HamiltonianPathProblem/graph.h"

TEST(TrivialTest, TrivialTest) {
  graph test_graph(2);
  EXPECT_EQ(test_graph.get_size(), 2);
}
