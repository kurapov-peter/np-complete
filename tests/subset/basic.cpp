#include "../../subset/SSet.h"
#include "gtest/gtest.h"


TEST(Basic, TwoElemsTrue) {
    SSet set;
    set.addElement(1);
    set.addElement(-1);
    ASSERT_EQ(set.checkZeroSumSlow(), 1);
}
TEST(Basic, TwoElemsFalseLoad) {
    SSet set;
    set.loadFile("set_input1.txt");
    ASSERT_EQ(set.checkZeroSumSlow(), 1);
}
TEST(Basic, TwoElemsFalse) {
    SSet set;
    set.addElement(1);
    set.addElement(-5);
    ASSERT_EQ(set.checkZeroSumSlow(), 0);
}
TEST(Basic, OneNegative10True) {
    SSet set;
    for (int i=1; i<10; i++) {
        set.addElement(i);
    }
    set.addElement(-20);
    ASSERT_EQ(set.checkZeroSumSlow(), 1);
}
TEST(Basic, OneNegative10False) {
    SSet set;
    for (int i=1; i<10; i++) {
        set.addElement(2*i);
    }
    set.addElement(-55);
    ASSERT_EQ(set.checkZeroSumSlow(), 0);
}
TEST(Basic, Mixed10True) {
    SSet set;
    for (int i=1; i<6; i++) {
        set.addElement(i);
    }
    for (int i=-10; i>-15; i--) {
        set.addElement(i);
    }
    ASSERT_EQ(set.checkZeroSumSlow(), 1);
}
TEST(Basic, Mixed10False) {
    SSet set;
    for (int i=1; i<6; i++) {
        set.addElement(1);
    }
    for (int i=-20; i>-25; i--) {
        set.addElement(i);
    }
    ASSERT_EQ(set.checkZeroSumSlow(), 0);
}
TEST(Basic, OneNegative50True) {
    SSet set;
    for (int i=1; i<50; i++) {
        set.addElement(2*i);
    }
    set.addElement(-150);
    ASSERT_EQ(set.checkZeroSumSlow(), 1);
}
TEST(Basic, OneNegative50False) {
    SSet set;
    for (int i=1; i<1000; i++) {
        set.addElement(2*i);
    }
    set.addElement(-55);
    ASSERT_EQ(set.checkZeroSumSlow(), 0);
}

TEST(Basic, OneNegative100True) {
    SSet set;
    for (int i=1; i<100; i++) {
        set.addElement(2*i);
    }
    set.addElement(-300);
    ASSERT_EQ(set.checkZeroSumSlow(), 1);
}
TEST(Basic, DISABLED_OneNegative100False) {
    SSet set;
    for (int i=1; i<100; i++) {
        set.addElement(2*i);
    }
    set.addElement(-5005);
    ASSERT_EQ(set.checkZeroSumSlow(), 0);
}
