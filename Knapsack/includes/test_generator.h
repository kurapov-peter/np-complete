#pragma once

#include <string>
#include <vector>
#include "common.h"

namespace Tests {

std::vector<np::KItem> GenSimpleTest(size_t n, size_t capacity,
                                     size_t res_profit, std::string fname);
std::vector<np::KItem> GenRandomTest(size_t n, size_t capacity,
                                     std::string fname);

}  // namespace Tests
