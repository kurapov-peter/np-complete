// Copyright 2020 Ragimov Islam, Pogotovsky Pavel

#include <vector>
#include <queue>
#include <algorithm>

#include "../includes/knapsack.h"

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
                    bf_solution[z] = max_set_buf[z];
                }

                sol_count = count;
            }
        }

        count = 0;
        total_profit = 0;
        total_weight = 0;
    }

    bf_solution.resize(sol_count);

    return max_profit;
}

int Knapsack::Bound(BABNode node) {
    if (node.elem.weight >= capacity_)
        return 0;

    int profit_bound = node.elem.profit;
    int j = node.level + 1;
    int total_weight = node.elem.weight;

    while (
        (j < elements_.size()) &&
        (total_weight + elements_[j].weight <= capacity_)
    ) {
        total_weight += elements_[j].weight;
        profit_bound += elements_[j].profit;
        j++;
    }

    if (j < elements_.size()) {
        profit_bound +=
            (capacity_ - total_weight) *
            elements_[j].profit/elements_[j].weight;
    }

    return profit_bound;
}

size_t Knapsack::BranchAndBound() {
    std::sort(elements_.begin(), elements_.end(), [](KItem a, KItem b) {
        double r1 = static_cast<double>(a.profit) / a.weight;
        double r2 = static_cast<double>(b.profit) / b.weight;
        return r1 > r2;
    });

    std::queue<BABNode> Q;
    BABNode u, v;
    int maxProfit = 0;
    int maxWeight = 0;

    Q.push(u);

    while (!Q.empty()) {
        u = Q.front();
        Q.pop();

        if (u.level == -1)
            v.level = 0;

        if (u.level == elements_.size() - 1)
            continue;

        v.level = u.level + 1;
        v.elem.weight = u.elem.weight + elements_[v.level].weight;
        v.elem.profit = u.elem.profit + elements_[v.level].profit;
        v.elem.id = elements_[v.level].id;

        v.itemList.clear();
        v.itemList = u.itemList;
        v.itemList.push_back(v.elem.id);

        if (v.elem.weight < capacity_ && v.elem.profit > maxProfit) {
            maxProfit = v.elem.profit;
            maxWeight = v.elem.weight;
            bab_solution = v.itemList;
        }

        v.bound = Bound(v);

        if (v.bound > maxProfit)
            Q.push(v);

        v.elem.weight = u.elem.weight;
        v.elem.profit = u.elem.profit;
        v.elem.id = u.elem.id;
        v.itemList = u.itemList;

        v.bound = Bound(v);

        if (v.bound > maxProfit)
            Q.push(v);
    }

    return maxProfit;
}

}  // namespace np
