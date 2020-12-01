#include <sstream>
#include <string>
#include "../../SAT/cnf_parser.hpp"
#include "gtest/gtest.h"

TEST(CNFParserTest, TestTest) {
  CNFParser parser;
  std::string cnf_s = "";
  std::istringstream ss(cnf_s);
  auto cnf = parser.Parse(ss);
  ASSERT_EQ(cnf.GetDim(), 0u);
}