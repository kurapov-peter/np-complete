#include "../../subset/SSet.h"
#include "gtest/gtest.h"


TEST(Optimized, File10True) {
    SSet set;
    set.loadFromFile("../../tests/input_sets/set_true_10.txt");
    ASSERT_TRUE(set.checkZeroSumOptimized());
}
TEST(Optimized, File10False) {
    SSet set;
    set.loadFromFile("../../tests/input_sets/set_false_10.txt");
    ASSERT_FALSE(set.checkZeroSumOptimized());
}
TEST(Optimized, File20True) {
    SSet set;
    set.loadFromFile("../../tests/input_sets/set_true_20.txt");
    ASSERT_TRUE(set.checkZeroSumOptimized());
}
TEST(Optimized, File20False) {
    SSet set;
    set.loadFromFile("../../tests/input_sets/set_false_20.txt");
    ASSERT_FALSE(set.checkZeroSumOptimized());
}
TEST(Optimized, OneNegative10True) {
    SSet set;
    for (int i=1; i<10; i++) {
        set.addElement(i);
    }
    set.addElement(-20);
    ASSERT_TRUE(set.checkZeroSumOptimized());
}
TEST(Optimized, OneNegative10False) {
    SSet set;
    for (int i=1; i<10; i++) {
        set.addElement(2*i);
    }
    set.addElement(-55);
    ASSERT_FALSE(set.checkZeroSumOptimized());
}
TEST(Optimized, Mixed10True) {
    SSet set;
    for (int i=1; i<6; i++) {
        set.addElement(i);
    }
    for (int i=-10; i>-15; i--) {
        set.addElement(i);
    }
    ASSERT_TRUE(set.checkZeroSumOptimized());
}
TEST(Optimized, Mixed10False) {
    SSet set;
    for (int i=1; i<6; i++) {
        set.addElement(1);
    }
    for (int i=-20; i>-25; i--) {
        set.addElement(i);
    }
    ASSERT_FALSE(set.checkZeroSumOptimized());
}
TEST(Optimized, OneNegative20True) {
    SSet set;
    for (int i=1; i<20; i++) {
        set.addElement(i);
    }
    set.addElement(-50);
    ASSERT_TRUE(set.checkZeroSumOptimized());
}
TEST(Optimized, OneNegative20False) {
    SSet set;
    for (int i=1; i<20; i++) {
        set.addElement(2*i);
    }
    set.addElement(-550);
    ASSERT_FALSE(set.checkZeroSumOptimized());
}

TEST(Optimized, DISABLED_OneNegative25True) {
    SSet set;
    for (int i=1; i<25; i++) {
        set.addElement(2*i);
    }
    set.addElement(-121);
    ASSERT_TRUE(set.checkZeroSumOptimized());
}
TEST(Optimized, DISABLED_OneNegative25False) {
    SSet set;
    for (int i=1; i<25; i++) {
        set.addElement(2*i);
    }
    set.addElement(-8005);
    ASSERT_FALSE(set.checkZeroSumOptimized());
}
