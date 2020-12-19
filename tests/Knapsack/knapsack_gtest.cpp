#include <gtest/gtest.h>
#include <stdio.h>
#include <iostream>
#include "../../Knapsack/includes/knapsack.h"

TEST(Knapsack, GetInputTest) {
  std::ifstream input;
  input.open("../../Knapsack/data/ip_10.txt");
  auto [cap, elems] = np::Knapsack::GetInput(input);
  ASSERT_EQ(cap, 560);

  ASSERT_EQ(elems[0].weight, 100);
  ASSERT_EQ(elems[0].profit, 25);
  ASSERT_EQ(elems[1].weight, 125);
  ASSERT_EQ(elems[1].profit, 33);
  ASSERT_EQ(elems[2].weight, 125);
  ASSERT_EQ(elems[2].profit, 56);
  ASSERT_EQ(elems[3].weight, 351);
  ASSERT_EQ(elems[3].profit, 16);
  ASSERT_EQ(elems[4].weight, 282);
  ASSERT_EQ(elems[4].profit, 71);
  ASSERT_EQ(elems[5].weight, 113);
  ASSERT_EQ(elems[5].profit, 96);
  ASSERT_EQ(elems[6].weight, 189);
  ASSERT_EQ(elems[6].profit, 8);
  ASSERT_EQ(elems[7].weight, 67);
  ASSERT_EQ(elems[7].profit, 24);
  ASSERT_EQ(elems[8].weight, 123);
  ASSERT_EQ(elems[8].profit, 37);
  ASSERT_EQ(elems[9].weight, 87);
  ASSERT_EQ(elems[9].profit, 76);
  input.close();
}

TEST(Knapsack, GetAnswerTest) {
  std::ifstream input;
  input.open("../../Knapsack/data/op_10.txt");
  auto [profit, _] = np::Knapsack::GetAnswer(input);

  ASSERT_EQ(profit, 290);

  input.close();
}

TEST(Knapsack, BruteForceSize10Test) {
  std::ifstream input;
  input.open("../../Knapsack/data/ip_10.txt");
  std::ifstream output;
  output.open("../../Knapsack/data/op_10.txt");

  auto [cap, elems] = np::Knapsack::GetInput(input);
  np::Knapsack kp(cap, elems);
  auto [profit, _] = np::Knapsack::GetAnswer(output);

  ASSERT_EQ(profit, kp.BruteForce());

  input.close();
  output.close();
}

TEST(Knapsack, BruteForceSize15Test) {
  std::ifstream input;
  input.open("../../Knapsack/data/ip_15.txt");
  std::ifstream output;
  output.open("../../Knapsack/data/op_15.txt");

  auto [cap, elems] = np::Knapsack::GetInput(input);
  np::Knapsack kp(cap, elems);
  auto [profit, _] = np::Knapsack::GetAnswer(output);

  ASSERT_EQ(profit, kp.BruteForce());

  input.close();
  output.close();
}

TEST(Knapsack, BruteForceSize20Test) {
  std::ifstream input;
  input.open("../../Knapsack/data/ip_20.txt");
  std::ifstream output;
  output.open("../../Knapsack/data/op_20.txt");

  auto [cap, elems] = np::Knapsack::GetInput(input);
  np::Knapsack kp(cap, elems);
  auto [profit, _] = np::Knapsack::GetAnswer(output);

  ASSERT_EQ(profit, kp.BruteForce());

  input.close();
  output.close();
}

TEST(Knapsack, BranchAndBound10Test) {
  std::ifstream input;
  input.open("../../Knapsack/data/ip_10.txt");
  std::ifstream output;
  output.open("../../Knapsack/data/op_10.txt");

  auto [cap, elems] = np::Knapsack::GetInput(input);
  np::Knapsack kp(cap, elems);
  auto [profit, _] = np::Knapsack::GetAnswer(output);

  ASSERT_EQ(profit, kp.BranchAndBound());

  input.close();
  output.close();
}

TEST(Knapsack, BranchAndBound15Test) {
  std::ifstream input;
  input.open("../../Knapsack/data/ip_15.txt");
  std::ifstream output;
  output.open("../../Knapsack/data/op_15.txt");

  auto [cap, elems] = np::Knapsack::GetInput(input);
  np::Knapsack kp(cap, elems);
  auto [profit, _] = np::Knapsack::GetAnswer(output);

  ASSERT_EQ(profit, kp.BranchAndBound());

  input.close();
  output.close();
}

TEST(Knapsack, BranchAndBound20Test) {
  std::ifstream input;
  input.open("../../Knapsack/data/ip_20.txt");
  std::ifstream output;
  output.open("../../Knapsack/data/op_20.txt");

  auto [cap, elems] = np::Knapsack::GetInput(input);
  np::Knapsack kp(cap, elems);
  auto [profit, _] = np::Knapsack::GetAnswer(output);

  ASSERT_EQ(profit, kp.BranchAndBound());

  input.close();
  output.close();
}

TEST(Knapsack, BranchAndBound25Test) {
  std::ifstream input;
  input.open("../../Knapsack/data/ip_25.txt");
  std::ifstream output;
  output.open("../../Knapsack/data/op_25.txt");

  auto [cap, elems] = np::Knapsack::GetInput(input);
  np::Knapsack kp(cap, elems);
  auto [profit, _] = np::Knapsack::GetAnswer(output);

  ASSERT_EQ(profit, kp.BranchAndBound());

  input.close();
  output.close();
}

TEST(Knapsack, BranchAndBound30Test) {
  std::ifstream input;
  input.open("../../Knapsack/data/ip_30.txt");
  std::ifstream output;
  output.open("../../Knapsack/data/op_30.txt");
  
  auto [cap, elems] = np::Knapsack::GetInput(input);
  np::Knapsack kp(cap, elems);
  auto [profit, _] = np::Knapsack::GetAnswer(output);

  ASSERT_EQ(profit, kp.BranchAndBound());

  input.close();
  output.close();
}

TEST(Knapsack, BranchAndBound35Test) {
  std::ifstream input;
  input.open("../../Knapsack/data/ip_35.txt");
  std::ifstream output;
  output.open("../../Knapsack/data/op_35.txt");

  auto [cap, elems] = np::Knapsack::GetInput(input);
  np::Knapsack kp(cap, elems);
  auto [profit, _] = np::Knapsack::GetAnswer(output);

  ASSERT_EQ(profit, kp.BranchAndBound());

  input.close();
  output.close();
}

TEST(Knapsack, BranchAndBound40Test) {
  std::ifstream input;
  input.open("../../Knapsack/data/ip_40.txt");
  std::ifstream output;
  output.open("../../Knapsack/data/op_40.txt");

  auto [cap, elems] = np::Knapsack::GetInput(input);
  np::Knapsack kp(cap, elems);
  auto [profit, _] = np::Knapsack::GetAnswer(output);

  ASSERT_EQ(profit, kp.BranchAndBound());

  input.close();
  output.close();
}

TEST(Knapsack, BranchAndBound45Test) {
  std::ifstream input;
  input.open("../../Knapsack/data/ip_45.txt");
  std::ifstream output;
  output.open("../../Knapsack/data/op_45.txt");

  auto [cap, elems] = np::Knapsack::GetInput(input);
  np::Knapsack kp(cap, elems);
  auto [profit, _] = np::Knapsack::GetAnswer(output);

  ASSERT_EQ(profit, kp.BranchAndBound());

  input.close();
  output.close();
}

TEST(Knapsack, BranchAndBound50Test) {
  std::ifstream input;
  input.open("../../Knapsack/data/ip_50.txt");
  std::ifstream output;
  output.open("../../Knapsack/data/op_50.txt");

  auto [cap, elems] = np::Knapsack::GetInput(input);
  np::Knapsack kp(cap, elems);
  auto [profit, _] = np::Knapsack::GetAnswer(output);

  ASSERT_EQ(profit, kp.BranchAndBound());

  input.close();
  output.close();
}

TEST(Knapsack, BranchAndBound55Test) {
  std::ifstream input;
  input.open("../../Knapsack/data/ip_55.txt");
  std::ifstream output;
  output.open("../../Knapsack/data/op_55.txt");

  auto [cap, elems] = np::Knapsack::GetInput(input);
  np::Knapsack kp(cap, elems);
  auto [profit, _] = np::Knapsack::GetAnswer(output);

  ASSERT_EQ(profit, kp.BranchAndBound());

  input.close();
  output.close();
}

TEST(Knapsack, BranchAndBound60Test) {
  std::ifstream input;
  input.open("../../Knapsack/data/ip_60.txt");
  std::ifstream output;
  output.open("../../Knapsack/data/op_60.txt");

  auto [cap, elems] = np::Knapsack::GetInput(input);
  np::Knapsack kp(cap, elems);
  auto [profit, _] = np::Knapsack::GetAnswer(output);

  ASSERT_EQ(profit, kp.BranchAndBound());

  input.close();
  output.close();
}
