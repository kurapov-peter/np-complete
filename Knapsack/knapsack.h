// Copyright 2020 Ragimov Islam, Pogotovsky Pavel

#pragma once

#include <tuple>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

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
    Knapsack(size_t capacity, std::vector<KItem> elements):
        capacity_(capacity),
        elements_(elements) {
        bf_solution.resize(elements_.size());
    }

    Knapsack(std::tuple<size_t, std::vector<KItem>> input) {
        std::tie(capacity_, elements_) = input;
        bf_solution.resize(capacity_);
    }

 public:
    static std::tuple<size_t, std::vector<KItem>> CinTest() {
        size_t k_capacity;
        std::cin >> k_capacity;

        size_t num_of_elems;
        std::cin >> num_of_elems;

        std::vector<KItem> elems;
        elems.resize(num_of_elems);
        for (size_t i = 0; i < num_of_elems; i++) {
            std::cin >> elems[i].weight;
            std::cin >> elems[i].profit;
            elems[i].id = i;
        }

        return std::make_tuple(k_capacity, elems);
    }

    size_t BruteForce();
    size_t BranchAndBound();

    std::vector<size_t> getBFSolution() {
        return bf_solution;
    }

    std::vector<int> getBABSolution() {
        return bab_solution;
    }

    size_t getProfit() {
        return max_profit;
    }

 private:
    int Bound(BABNode node);

 private:
    size_t capacity_;
    std::vector<KItem> elements_;

    std::vector<size_t> bf_solution;
    std::vector<int> bab_solution;
    size_t max_weight = 0;
    size_t max_profit = 0;
};

}  // namespace np
