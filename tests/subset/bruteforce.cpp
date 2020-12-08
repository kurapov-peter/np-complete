#include "../../subset/SSet.h"
#include "gtest/gtest.h"


TEST(BruteForce, TwoElemsTrue) {
    SSet set;
    set.addElement(1);
    set.addElement(-1);
    ASSERT_TRUE(set.checkZeroSumSlow());
}
TEST(BruteForce, File10True) {
    SSet set;
    ASSERT_TRUE(set.loadFromFile("../tests/input_sets/set_true_10.txt"));
    ASSERT_TRUE(set.checkZeroSumSlow());
}
TEST(BruteForce, File10False) {
    SSet set;
    ASSERT_TRUE(set.loadFromFile("../tests/input_sets/set_false_10.txt"));
    ASSERT_FALSE(set.checkZeroSumSlow());
}
TEST(BruteForce, File20True) {
    SSet set;
    ASSERT_TRUE(set.loadFromFile("../tests/input_sets/set_true_20.txt"));
    ASSERT_TRUE(set.checkZeroSumSlow());
}
TEST(BruteForce, File20False) {
    SSet set;
    ASSERT_TRUE(set.loadFromFile("../tests/input_sets/set_false_20.txt"));
    ASSERT_FALSE(set.checkZeroSumSlow());
}
TEST(BruteForce, TwoElemsFalse) {
    SSet set;
    set.addElement(1);
    set.addElement(-5);
    ASSERT_FALSE(set.checkZeroSumSlow());
}
TEST(BruteForce, OneNegative10True) {
    SSet set;
    for (int i=1; i<10; i++) {
        set.addElement(i);
    }
    set.addElement(-20);
    ASSERT_TRUE(set.checkZeroSumSlow());
}
TEST(BruteForce, OneNegative10False) {
    SSet set;
    for (int i=1; i<10; i++) {
        set.addElement(2*i);
    }
    set.addElement(-55);
    ASSERT_FALSE(set.checkZeroSumSlow());
}
TEST(BruteForce, Mixed10True) {
    SSet set;
    for (int i=1; i<6; i++) {
        set.addElement(i);
    }
    for (int i=-10; i>-15; i--) {
        set.addElement(i);
    }
    ASSERT_TRUE(set.checkZeroSumSlow());
}
TEST(BruteForce, Mixed10False) {
    SSet set;
    for (int i=1; i<6; i++) {
        set.addElement(1);
    }
    for (int i=-20; i>-25; i--) {
        set.addElement(i);
    }
    ASSERT_FALSE(set.checkZeroSumSlow());
}
TEST(BruteForce, OneNegative20True) {
    SSet set;
    for (int i=1; i<20; i++) {
        set.addElement(i);
    }
    set.addElement(-50);
    ASSERT_TRUE(set.checkZeroSumSlow());
}
TEST(BruteForce, OneNegative20False) {
    SSet set;
    for (int i=1; i<20; i++) {
        set.addElement(2*i);
    }
    set.addElement(-550);
    ASSERT_FALSE(set.checkZeroSumSlow());
}

TEST(BruteForce, DISABLED_OneNegative25True) {
    SSet set;
    for (int i=1; i<25; i++) {
        set.addElement(2*i);
    }
    set.addElement(-121);
    ASSERT_TRUE(set.checkZeroSumSlow());
}
TEST(BruteForce, DISABLED_OneNegative25False) {
    SSet set;
    for (int i=1; i<25; i++) {
        set.addElement(2*i);
    }
    set.addElement(-8005);
    ASSERT_FALSE(set.checkZeroSumSlow());
}
