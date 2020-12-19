#pragma once

#include <stdlib.h>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

namespace np {

struct KItem {
  int weight = 0;
  int profit = 0;
  int id;
};

struct BABNode {
  int level = -1;
  KItem elem;
  int bound;
  std::vector<int> itemList;
};

class Knapsack final {
 public:
  Knapsack(size_t capacity, const std::vector<KItem> &elements)
      : capacity_(capacity), elements_(elements) {
    bf_solution.resize(elements_.size());
  }

  Knapsack(std::tuple<size_t, const std::vector<KItem>> &input) {
    std::tie(capacity_, elements_) = input;
    bf_solution.resize(capacity_);
  }

 public:
  static std::tuple<size_t, size_t> GetAnswer(std::istream &is) {
    size_t total_weight;
    size_t total_profit;
    
    is >> total_weight;
    is >> total_profit;

    return std::make_tuple(total_profit, total_weight);;
  }

//   static std::tuple<size_t, std::vector<KItem>> GetInput(
//       std::iostream &is) {
//     size_t k_capacity;
//     size_t num_of_elems;
//     std::ifstream input;

//     input.open(file_name);
//     if (input.is_open()) {
//       input >> k_capacity;
//       input >> num_of_elems;
//     } else {
//       std::cerr << file_name << " was not opened" << std::endl;
//       exit(EXIT_FAILURE);
//     }

//     std::vector<KItem> elems;
//     elems.resize(num_of_elems);
//     for (size_t i = 0; i < num_of_elems; i++) {
//       input >> elems[i].weight;
//       input >> elems[i].profit;
//       elems[i].id = i;
//     }

//     return std::make_tuple(k_capacity, elems);
//   }

  static std::tuple<size_t, std::vector<KItem>> GetInput(std::istream &is) {
    size_t k_capacity;
    is >> k_capacity;

    size_t num_of_elems;
    is >> num_of_elems;

    std::vector<KItem> elems;
    elems.resize(num_of_elems);
    for (size_t i = 0; i < num_of_elems; i++) {
      is >> elems[i].weight;
      is >> elems[i].profit;
      elems[i].id = i;
    }

    return std::make_tuple(k_capacity, elems);
  }

  size_t BruteForce();
  size_t BranchAndBound();

  std::vector<size_t> getBFSolution() { return bf_solution; }

  std::vector<int> getBABSolution() { return bab_solution; }

  size_t getProfit() { return max_profit; }

 private:
  int Bound(const BABNode &node);

 private:
  size_t capacity_;
  std::vector<KItem> elements_;

  std::vector<size_t> bf_solution;
  std::vector<int> bab_solution;
  size_t max_weight = 0;
  size_t max_profit = 0;
};

}  // namespace np
