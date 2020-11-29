// Copyright 2020 Ragimov Islam, Pogotovsky Pavel

#pragma once

#include <iostream>
#include <tuple>
#include <cmath>
#include <vector>

namespace np {

struct KItem {
    int weight = 0;
    int profit = 0;
};

class Knapsack final {
 public:
    Knapsack(size_t capacity, std::vector<KItem> elements):
        capacity_(capacity),
        elements_(elements) {
        solution.resize(elements_.size());
    }

    Knapsack(std::tuple<size_t, std::vector<KItem>> input) {
        std::tie(capacity_, elements_) = input;
        solution.resize(capacity_);
    }

 public:
    static std::tuple<size_t, std::vector<KItem>> CinTest() {
        size_t k_capacity;
        std::cin >> k_capacity;

        // std::cout << k_capacity << std::endl;

        size_t num_of_elems;
        std::cin >> num_of_elems;

        // std::cout << num_of_elems << std::endl;

        std::vector<KItem> elems;
        elems.resize(num_of_elems);
        for (size_t i = 0; i < num_of_elems; i++) {
            std::cin >> elems[i].weight;
            std::cin >> elems[i].profit;
            // std::cout << elems[i].weight << " ";
            // std::cout << elems[i].profit << std::endl;
        }

        return std::make_tuple(k_capacity, elems);
    }

    size_t BruteForce();

    std::vector<size_t> getSolution() {
        return solution;
    }

    size_t getProfit() {
        return max_profit;
    }

 private:
    size_t capacity_;
    std::vector<KItem> elements_;

    std::vector<size_t> solution;
    size_t max_weight = 0;
    size_t max_profit = 0;
};

} // namespace np
