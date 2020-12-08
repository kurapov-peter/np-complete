// Copyright 2020 Ragimov Islam, Pogotovsky Pavel

#include "../includes/knapsack.h"

int main() {
    auto[cap, elems] = np::Knapsack::CinTest();
    np::Knapsack kp(cap, elems);
        
    std::cout << kp.BruteForce() << std::endl;
    std::cout << kp.BranchAndBound() << std::endl;
}
