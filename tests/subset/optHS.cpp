#include "../../subset/SSet.h"
#include "gtest/gtest.h"

TEST(OptimizedHS, OPTFile10True) {
  SSet set;
  ASSERT_TRUE(set.loadFromFile("../tests/input_sets/set_true_10.txt"));
  ASSERT_TRUE(set.checkZeroSumOptimizedHS());
}
TEST(OptimizedHS, OPTFile10False) {
  SSet set;
  ASSERT_TRUE(set.loadFromFile("../tests/input_sets/set_false_10.txt"));
  ASSERT_FALSE(set.checkZeroSumOptimizedHS());
}
TEST(OptimizedHS, OPTFile20True) {
  SSet set;
  ASSERT_TRUE(set.loadFromFile("../tests/input_sets/set_true_20.txt"));
  ASSERT_TRUE(set.checkZeroSumOptimizedHS());
}
TEST(OptimizedHS, OPTFile20False) {
  SSet set;
  ASSERT_TRUE(set.loadFromFile("../tests/input_sets/set_false_20.txt"));
  ASSERT_FALSE(set.checkZeroSumOptimizedHS());
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
