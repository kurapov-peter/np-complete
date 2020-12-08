// Copyright 2020 Ragimov Islam, Pogotovsky Pavel

#include <gtest/gtest.h>
#include "../../Knapsack/includes/knapsack.h"
#include <iostream>
#include <stdio.h>

TEST(Knapsack, GetInputTest) {
     auto[cap, elems] = np::Knapsack::GetInput("../../Knapsack/data/ip_10.txt");
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
}

TEST(Knapsack, GetAnswerTest) {
     size_t profit = np::Knapsack::GetAnswer("../../Knapsack/data/op_10.txt");
     ASSERT_EQ(profit, 290);
}

TEST(Knapsack, BruteForceSize10Test) {
     auto[cap, elems] = np::Knapsack::GetInput("../../Knapsack/data/ip_10.txt");
     np::Knapsack kp(cap, elems);
     size_t profit = np::Knapsack::GetAnswer("../../Knapsack/data/op_10.txt");

     ASSERT_EQ(profit, kp.BruteForce());
}

TEST(Knapsack, BruteForceSize15Test) {
     auto[cap, elems] = np::Knapsack::GetInput("../../Knapsack/data/ip_15.txt");
     np::Knapsack kp(cap, elems);
     size_t profit = np::Knapsack::GetAnswer("../../Knapsack/data/op_15.txt");

     ASSERT_EQ(profit, kp.BruteForce());
}

TEST(Knapsack, BruteForceSize20Test) {
     auto[cap, elems] = np::Knapsack::GetInput("../../Knapsack/data/ip_20.txt");
     np::Knapsack kp(cap, elems);
     size_t profit = np::Knapsack::GetAnswer("../../Knapsack/data/op_20.txt");

     ASSERT_EQ(profit, kp.BruteForce());
}

TEST(Knapsack, BranchAndBound10Test) {
     auto[cap, elems] = np::Knapsack::GetInput("../../Knapsack/data/ip_10.txt");
     np::Knapsack kp(cap, elems);
     size_t profit = np::Knapsack::GetAnswer("../../Knapsack/data/op_10.txt");

     ASSERT_EQ(profit, kp.BranchAndBound());
}

TEST(Knapsack, BranchAndBound15Test) {
     auto[cap, elems] = np::Knapsack::GetInput("../../Knapsack/data/ip_15.txt");
     np::Knapsack kp(cap, elems);
     size_t profit = np::Knapsack::GetAnswer("../../Knapsack/data/op_15.txt");

     ASSERT_EQ(profit, kp.BranchAndBound());
}

TEST(Knapsack, BranchAndBound20Test) {
     auto[cap, elems] = np::Knapsack::GetInput("../../Knapsack/data/ip_20.txt");
     np::Knapsack kp(cap, elems);
     size_t profit = np::Knapsack::GetAnswer("../../Knapsack/data/op_20.txt");

     ASSERT_EQ(profit, kp.BranchAndBound());
}

TEST(Knapsack, BranchAndBound25Test) {
     auto[cap, elems] = np::Knapsack::GetInput("../../Knapsack/data/ip_25.txt");
     np::Knapsack kp(cap, elems);
     size_t profit = np::Knapsack::GetAnswer("../../Knapsack/data/op_25.txt");

     ASSERT_EQ(profit, kp.BranchAndBound());
}

TEST(Knapsack, BranchAndBound30Test) {
     auto[cap, elems] = np::Knapsack::GetInput("../../Knapsack/data/ip_30.txt");
     np::Knapsack kp(cap, elems);
     size_t profit = np::Knapsack::GetAnswer("../../Knapsack/data/op_30.txt");

     ASSERT_EQ(profit, kp.BranchAndBound());
}

TEST(Knapsack, BranchAndBound35Test) {
     auto[cap, elems] = np::Knapsack::GetInput("../../Knapsack/data/ip_35.txt");
     np::Knapsack kp(cap, elems);
     size_t profit = np::Knapsack::GetAnswer("../../Knapsack/data/op_35.txt");

     ASSERT_EQ(profit, kp.BranchAndBound());
}


TEST(Knapsack, BranchAndBound40Test) {
     auto[cap, elems] = np::Knapsack::GetInput("../../Knapsack/data/ip_40.txt");
     np::Knapsack kp(cap, elems);
     size_t profit = np::Knapsack::GetAnswer("../../Knapsack/data/op_40.txt");

     ASSERT_EQ(profit, kp.BranchAndBound());
}

TEST(Knapsack, BranchAndBound45Test) {
     auto[cap, elems] = np::Knapsack::GetInput("../../Knapsack/data/ip_45.txt");
     np::Knapsack kp(cap, elems);
     size_t profit = np::Knapsack::GetAnswer("../../Knapsack/data/op_45.txt");

     ASSERT_EQ(profit, kp.BranchAndBound());
}

TEST(Knapsack, BranchAndBound50Test) {
     auto[cap, elems] = np::Knapsack::GetInput("../../Knapsack/data/ip_50.txt");
     np::Knapsack kp(cap, elems);
     size_t profit = np::Knapsack::GetAnswer("../../Knapsack/data/op_50.txt");

     ASSERT_EQ(profit, kp.BranchAndBound());
}

TEST(Knapsack, BranchAndBound55Test) {
     auto[cap, elems] = np::Knapsack::GetInput("../../Knapsack/data/ip_55.txt");
     np::Knapsack kp(cap, elems);
     size_t profit = np::Knapsack::GetAnswer("../../Knapsack/data/op_55.txt");

     ASSERT_EQ(profit, kp.BranchAndBound());
}

TEST(Knapsack, BranchAndBound60Test) {
     auto[cap, elems] = np::Knapsack::GetInput("../../Knapsack/data/ip_60.txt");
     np::Knapsack kp(cap, elems);
     size_t profit = np::Knapsack::GetAnswer("../../Knapsack/data/op_60.txt");

     ASSERT_EQ(profit, kp.BranchAndBound());
}
