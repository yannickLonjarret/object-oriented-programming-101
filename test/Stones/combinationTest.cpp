#include <gtest/gtest.h>

#include "combination.h"

// Demonstrate some basic assertions.
TEST(CombinationTest, TT) {
    Combination::CardCombination c = Combination::CardCombination(Combination::Type::SUM, 9);
    EXPECT_EQ(Combination::Type::SUM, c.getCombinationType());
}