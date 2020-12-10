#include "../../subset/SSet.h"
#include "gtest/gtest.h"

void runTestOptimizedHS(std::string file, bool result) {
  SSet set;
  ASSERT_TRUE(set.loadFromFile(file));
  if (result)
    ASSERT_TRUE(set.checkZeroSumOptimizedHS());
  else
    ASSERT_FALSE(set.checkZeroSumOptimizedHS());
}

TEST(OptimizedHS, OPTFile10True) {
  runTestOptimizedHS("../tests/input_sets/set_true_10.txt", true);
}
TEST(OptimizedHS, OPTFile10False) {
  runTestOptimizedHS("../tests/input_sets/set_false_10.txt", false);
}
TEST(OptimizedHS, OPTFile15True) {
  runTestOptimizedHS("../tests/input_sets/set_true_15.txt", true);
}
TEST(OptimizedHS, OPTFile15False) {
  runTestOptimizedHS("../tests/input_sets/set_false_15.txt", false);
}
TEST(OptimizedHS, OPTFile20True) {
  runTestOptimizedHS("../tests/input_sets/set_true_20.txt", true);
}
TEST(OptimizedHS, OPTFile20False) {
  runTestOptimizedHS("../tests/input_sets/set_false_20.txt", false);
}
TEST(OptimizedHS, OPTFile25True) {
  runTestOptimizedHS("../tests/input_sets/set_true_25.txt", true);
}
TEST(OptimizedHS, OPTFile25False) {
  runTestOptimizedHS("../tests/input_sets/set_false_25.txt", false);
}
TEST(OptimizedHS, OPTFile30True) {
  runTestOptimizedHS("../tests/input_sets/set_true_30.txt", true);
}
TEST(OptimizedHS, OPTFile30False) {
  runTestOptimizedHS("../tests/input_sets/set_false_30.txt", false);
}
TEST(Optimized, OPTOneNegative10True) {
  SSet set;
  for (int i = 1; i < 10; i++) {
    set.addElement(i);
  }
  set.addElement(-20);
  ASSERT_TRUE(set.checkZeroSumOptimized());
}
TEST(Optimized, OPTOneNegative10False) {
  SSet set;
  for (int i = 1; i < 10; i++) {
    set.addElement(2 * i);
  }
  set.addElement(-55);
  ASSERT_FALSE(set.checkZeroSumOptimized());
}
TEST(Optimized, OPTMixed10True) {
  SSet set;
  for (int i = 1; i < 6; i++) {
    set.addElement(i);
  }
  for (int i = -10; i > -15; i--) {
    set.addElement(i);
  }
  ASSERT_TRUE(set.checkZeroSumOptimized());
}
TEST(Optimized, OPTMixed10False) {
  SSet set;
  for (int i = 1; i < 6; i++) {
    set.addElement(1);
  }
  for (int i = -20; i > -25; i--) {
    set.addElement(i);
  }
  ASSERT_FALSE(set.checkZeroSumOptimized());
}
TEST(Optimized, OPTOneNegative20True) {
  SSet set;
  for (int i = 1; i < 20; i++) {
    set.addElement(i);
  }
  set.addElement(-50);
  ASSERT_TRUE(set.checkZeroSumOptimized());
}
TEST(Optimized, OPTOneNegative20False) {
  SSet set;
  for (int i = 1; i < 20; i++) {
    set.addElement(2 * i);
  }
  set.addElement(-550);
  ASSERT_FALSE(set.checkZeroSumOptimized());
}

TEST(Optimized, DISABLED_OPTOneNegative25True) {
  SSet set;
  for (int i = 1; i < 25; i++) {
    set.addElement(2 * i);
  }
  set.addElement(-121);
  ASSERT_TRUE(set.checkZeroSumOptimized());
}
TEST(Optimized, DISABLED_OPTOneNegative25False) {
  SSet set;
  for (int i = 1; i < 25; i++) {
    set.addElement(2 * i);
  }
  set.addElement(-8005);
  ASSERT_FALSE(set.checkZeroSumOptimized());
}
