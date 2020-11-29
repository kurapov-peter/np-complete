// Copyright 2020 Ragimov Islam, Pogotovsky Pavel

#include <vector>

#include "./knapsack.h"

namespace np {

size_t Knapsack::BruteForce() {
    size_t num_of_cases = std::pow(2, elements_.size());
    size_t count = 0, sol_count = 0;
    size_t total_weight = 0, total_profit = 0;
    std::vector<int> max_set_buf;
    max_set_buf.resize(elements_.size());

    for (size_t k = 0; k < num_of_cases; k++) {
        for (size_t j = 0; j < elements_.size(); j++) {
            if ((1 << j) & k) {
                total_profit = total_profit + elements_[j].profit;
                total_weight = total_weight + elements_[j].weight;
                max_set_buf[count++] = j + 1;
            }
        }

        if (total_weight < capacity_) {
            if (total_profit >= max_profit) {
                max_weight = total_weight;
                max_profit = total_profit;

                for (size_t z = 0; z < count; z++) {
                    solution[z] = max_set_buf[z];
                }

                sol_count = count;
            }
        }

        count = 0;
        total_profit = 0;
        total_weight = 0;
    }

    solution.resize(sol_count);

    std::cout << "max_profit: " << max_profit << std::endl;
    std::cout << "max_weight: " << max_weight << std::endl;

    for (size_t i = 0; i < solution.size(); i++) {
        std::cout << solution[i] << " ";
    }

    return max_profit;
}

} // namespace np
