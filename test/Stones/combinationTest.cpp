#include <gtest/gtest.h>

#include "combination.h"

using namespace Combination;

TEST(CombinationTest, ComparisonOperator) {
    CardCombination c1 = CardCombination(Type::COLORED_SERIE, 10);
    CardCombination c2 = CardCombination(Type::SUM, 12);
    EXPECT_TRUE(c2 < c1);
    EXPECT_FALSE(c1 < c2);
    EXPECT_FALSE(c1 == c2);

    c2 = CardCombination(Type::COLORED_SERIE, 11);
    EXPECT_FALSE(c2 < c1);
    EXPECT_TRUE(c1 < c2);
    EXPECT_FALSE(c1 == c2);

    c2 = CardCombination(Type::COLORED_SERIE, 10);
    EXPECT_FALSE(c2 < c1);
    EXPECT_FALSE(c1 < c2);
    EXPECT_TRUE(c1 == c2);
}