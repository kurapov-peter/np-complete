#include <gtest/gtest.h>
#include <stdio.h>

#include <iostream>

#include "../../../Knapsack/includes/knapsack.h"
#include "../includes/test_generator.h"

TEST(Knapsack, SIZE_10) {
  size_t max_weight = 100;
  size_t n = 10;
  size_t max_profit = 40;
  auto [elems, profit, cap] =
      Tests::GenSimpleTest(n, max_weight, max_profit, "");
  np::Knapsack kp(cap, elems);
  ASSERT_EQ(profit, kp.BruteForce());
  ASSERT_EQ(profit, kp.BranchAndBound());
}

TEST(Knapsack, SIZE_15) {
  size_t max_weight = 200;
  size_t n = 15;
  size_t max_profit = 68;
  auto [elems, profit, cap] =
      Tests::GenSimpleTest(n, max_weight, max_profit, "");
  np::Knapsack kp(cap, elems);
  ASSERT_EQ(profit, kp.BruteForce());
  ASSERT_EQ(profit, kp.BranchAndBound());
}

TEST(Knapsack, SIZE_20) {
  size_t max_weight = 150;
  size_t n = 20;
  size_t max_profit = 17;
  auto [elems, profit, cap] =
      Tests::GenSimpleTest(n, max_weight, max_profit, "");
  np::Knapsack kp(cap, elems);
  ASSERT_EQ(profit, kp.BruteForce());
  ASSERT_EQ(profit, kp.BranchAndBound());
}

TEST(Knapsack, SIZE_25) {
  size_t max_weight = 356;
  size_t n = 25;
  size_t max_profit = 62;
  auto [elems, profit, cap] =
      Tests::GenSimpleTest(n, max_weight, max_profit, "");
  np::Knapsack kp(cap, elems);
  ASSERT_EQ(profit, kp.BruteForce());
  ASSERT_EQ(profit, kp.BranchAndBound());
}