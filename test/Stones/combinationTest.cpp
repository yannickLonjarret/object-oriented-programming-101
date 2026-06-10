#include <gtest/gtest.h>

#include "combination.h"

using namespace Combination;

TEST(CombinationTest, ComparisonOperator_DifferentTypes) {
    CardCombination strongCombination = CardCombination(Type::COLORED_SERIE, 10);
    CardCombination weakCombination = CardCombination(Type::SUM, 12);
    EXPECT_TRUE(weakCombination < strongCombination) << "Combination type comparison failure.";
    EXPECT_FALSE(strongCombination < weakCombination) << "Combination type comparison failure.";
    EXPECT_FALSE(strongCombination == weakCombination) << "Combination type comparison failure.";
}

TEST(CombinationTest, ComparisonOperator_SameTypeDifferentCardValues) {
    CardCombination weakCombination = CardCombination(Type::COLORED_SERIE, 11);
    CardCombination strongCombination = CardCombination(Type::COLORED_SERIE, 12);

    EXPECT_TRUE(weakCombination < strongCombination) << "Combination, same type comparison failure.";
    EXPECT_FALSE(strongCombination < weakCombination) << "Combination, same type comparison failure.";
    EXPECT_FALSE(strongCombination == weakCombination) << "Combination, same type comparison failure.";
}

TEST(CombinationTest, CombinationOperator_EqualCombination) {
    CardCombination firstCombination = CardCombination(Type::COLORED_SERIE, 12);
    CardCombination secondCombination = CardCombination(Type::COLORED_SERIE, 12);
    EXPECT_FALSE(firstCombination < secondCombination) << "Combination, equality comparison failure.";
    EXPECT_FALSE(secondCombination < firstCombination) << "Combination, equality comparison failure.";
    EXPECT_TRUE(firstCombination == secondCombination) << "Combination, equality comparison failure.";
}