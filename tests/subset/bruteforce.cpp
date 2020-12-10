#include "../../subset/SSet.h"
#include "gtest/gtest.h"

void runTestSlow(std::string file, bool result) {
  SSet set;
  ASSERT_TRUE(set.loadFromFile(file));
  if (result)
    ASSERT_TRUE(set.checkZeroSumSlow());
  else
    ASSERT_FALSE(set.checkZeroSumSlow());
}

TEST(BruteForce, File10True) {
  runTestSlow("../tests/input_sets/set_true_10.txt", true);
}
TEST(BruteForce, File10False) {
  runTestSlow("../tests/input_sets/set_false_10.txt", false);
}
TEST(BruteForce, File15True) {
  runTestSlow("../tests/input_sets/set_true_15.txt", true);
}
TEST(BruteForce, File15False) {
  runTestSlow("../tests/input_sets/set_false_15.txt", false);
}
TEST(BruteForce, File20True) {
  runTestSlow("../tests/input_sets/set_true_20.txt", true);
}
TEST(BruteForce, File20False) {
  runTestSlow("../tests/input_sets/set_false_20.txt", false);
}
TEST(BruteForce, DISABLED_File25True) {
  runTestSlow("../tests/input_sets/set_true_25.txt", true);
}
TEST(BruteForce, DISABLED_File25False) {
  runTestSlow("../tests/input_sets/set_false_25.txt", false);
}
TEST(BruteForce, DISABLED_File30True) {
  runTestSlow("../tests/input_sets/set_true_30.txt", true);
}
TEST(BruteForce, DISABLED_File30False) {
  runTestSlow("../tests/input_sets/set_false_30.txt", false);
}
TEST(BruteForce, TwoElemsTrue) {
  SSet set;
  set.addElement(1);
  set.addElement(-1);
  ASSERT_TRUE(set.checkZeroSumSlow());
}
TEST(BruteForce, TwoElemsFalse) {
  SSet set;
  set.addElement(1);
  set.addElement(-5);
  ASSERT_FALSE(set.checkZeroSumSlow());
}
TEST(BruteForce, OneNegative10True) {
  SSet set;
  for (int i = 1; i < 10; i++) {
    set.addElement(i);
  }
  set.addElement(-20);
  ASSERT_TRUE(set.checkZeroSumSlow());
}
TEST(BruteForce, OneNegative10False) {
  SSet set;
  for (int i = 1; i < 10; i++) {
    set.addElement(2 * i);
  }
  set.addElement(-55);
  ASSERT_FALSE(set.checkZeroSumSlow());
}
TEST(BruteForce, Mixed10True) {
  SSet set;
  for (int i = 1; i < 6; i++) {
    set.addElement(i);
  }
  for (int i = -10; i > -15; i--) {
    set.addElement(i);
  }
  ASSERT_TRUE(set.checkZeroSumSlow());
}
TEST(BruteForce, Mixed10False) {
  SSet set;
  for (int i = 1; i < 6; i++) {
    set.addElement(1);
  }
  for (int i = -20; i > -25; i--) {
    set.addElement(i);
  }
  ASSERT_FALSE(set.checkZeroSumSlow());
}
TEST(BruteForce, OneNegative20True) {
  SSet set;
  for (int i = 1; i < 20; i++) {
    set.addElement(i);
  }
  set.addElement(-50);
  ASSERT_TRUE(set.checkZeroSumSlow());
}
TEST(BruteForce, OneNegative20False) {
  SSet set;
  for (int i = 1; i < 20; i++) {
    set.addElement(2 * i);
  }
  set.addElement(-550);
  ASSERT_FALSE(set.checkZeroSumSlow());
}

TEST(BruteForce, DISABLED_OneNegative25True) {
  SSet set;
  for (int i = 1; i < 25; i++) {
    set.addElement(2 * i);
  }
  set.addElement(-121);
  ASSERT_TRUE(set.checkZeroSumSlow());
}
TEST(BruteForce, DISABLED_OneNegative25False) {
  SSet set;
  for (int i = 1; i < 25; i++) {
    set.addElement(2 * i);
  }
  set.addElement(-8005);
  ASSERT_FALSE(set.checkZeroSumSlow());
}
