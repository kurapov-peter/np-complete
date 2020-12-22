#include <math.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <random>
#include <tuple>

#include "../includes/test_generator.h"

namespace Tests {

std::tuple<std::vector<np::KItem>, size_t, size_t, size_t> GenSimpleAnswer(size_t n,
                                                           size_t max_elem_weight,
                                                           size_t max_elem_profit) {
  std::vector<np::KItem> res;
  res.reserve(n);
  size_t total_weight = 0;
  size_t total_profit = 0;
  int min_elem_profit = max_elem_profit;
  np::KItem cur_item;

  for (size_t i = 0; i < n; i++) {
    cur_item.id = i;
    cur_item.weight = 1 + rand() % max_elem_weight;
    total_weight += cur_item.weight;
    cur_item.profit = 1 + rand() % max_elem_profit;
    total_profit += cur_item.profit;
    res.push_back(cur_item);
    if (min_elem_profit > cur_item.profit) min_elem_profit = cur_item.profit;
  }

  return std::make_tuple(res, min_elem_profit, total_weight, total_profit);
}

std::vector<np::KItem> GenSimpleTest(size_t n, size_t max_elem_weight,
                                     size_t max_elem_profit, std::string fname) {
  srand(static_cast<unsigned int>(time(0)));
  size_t answer_size = 2 + (std::rand() % static_cast<int>(n / 2));
  auto [res, min_profit, capacity, res_profit] = GenSimpleAnswer(answer_size, max_elem_weight, max_elem_profit);

  np::KItem item;
  for (size_t i = 0; i < n - answer_size; i++) {
    item.id = i + answer_size;
    if (i % 2 == 0) {
      item.weight = capacity + 1 + rand() % capacity;
      item.profit = rand() % res_profit;
    } else {
      item.weight = rand() % max_elem_weight;
      item.profit = rand() % min_profit;
    }
    res.push_back(item);
  }

  auto rng = std::default_random_engine{};
  std::shuffle(res.begin(), res.end(), rng);

  std::ofstream ifile;
  ifile.open(fname + "_ip" + std::to_string(n));
  ifile << capacity << "\n" << n << "\n";
  std::ofstream ofile;
  ofile.open(fname + "_op" + std::to_string(n));
  ofile << res_profit << " " << capacity << "\n";

  for (size_t i = 0; i < n; i++) {
    if (res[i].id < static_cast<int>(answer_size)) {
      ofile << i << "\n";
    }
    ifile << res[i].weight << " " << res[i].profit << "\n";
    res[i].id = i;
  }
  ifile.close();
  ofile.close();

  return res;
}

std::vector<np::KItem> GenRandomTest(size_t n, size_t capacity,
                                     std::string fname) {
  srand(static_cast<unsigned int>(time(0)));
  std::vector<np::KItem> res;
  res.reserve(n + 1);
  np::KItem item;
  for (size_t i = 0; i < n; i++) {
    item.id = i;
    item.weight = rand() % static_cast<int>(capacity * 1.3);
    item.profit = rand() % static_cast<int>(capacity * 2);
    res.push_back(item);
  }

  std::ofstream output;
  output.open(fname + "_ip" + std::to_string(n));
  output << capacity << "\n" << n << "\n";
  for (auto it = res.begin(); it != res.end(); it++) {
    output << it->weight << " " << it->profit << "\n";
  }
  output.close();

  return res;
}

}  // namespace Tests
