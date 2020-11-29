// Copyright 2020 Ragimov Islam, Pogotovsky Pavel

#include "./knapsack.h"

int main() {
    auto[cap, elems] = np::Knapsack::CinTest();
    np::Knapsack kp(cap, elems);
    kp.BruteForce();
}
