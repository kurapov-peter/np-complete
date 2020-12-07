#include "../../subset/SSet.h"
#include "gtest/gtest.h"


TEST(Basic, check) {
    SSet set;
    set.addElement(1);
    set.addElement(-1);
    ASSERT_EQ(set.checkZeroSumSlow(), 1);
}

TEST(Basics, check) {
    SSet set;
    set.addElement(2);
    set.addElement(-1);
    ASSERT_EQ(set.checkZeroSumSlow(), 0);
}
