#include <gtest/gtest.h>

#include "combination.h"

using namespace Combination;

// Type identification
TEST(CombinationIdentification, SerieTrue) {
    std::vector<ClanCard> cards;
    cards.push_back(ClanCard(1, CardColors::BLUE));
    cards.push_back(ClanCard(2, CardColors::BLUE));
    cards.push_back(ClanCard(3, CardColors::BLUE));

    EXPECT_TRUE(isSerie(cards)) << "Serie combination not identified.";
}

TEST(CombinationIdentification, SerieFalse) {
    std::vector<ClanCard> cards;
    cards.push_back(ClanCard(1, CardColors::BLUE));
    cards.push_back(ClanCard(2, CardColors::BLUE));
    cards.push_back(ClanCard(2, CardColors::BLUE));

    EXPECT_FALSE(isSerie(cards)) << "Wrong combination identified as Serie.";
}

TEST(CombinationIdentification, Serie_EmptyVector) {
    std::vector<ClanCard> cards;
    EXPECT_FALSE(isSerie(cards)) << "Empty card vector identified as Serie";
}

TEST(CombinationIdentification, Serie_SingleCard) {
    std::vector<ClanCard> cards(1);
    EXPECT_FALSE(isSerie(cards)) << "Single card vector identified as Serie";
}

TEST(CombinationIdentification, ColorTrue) {
    std::vector<ClanCard> cards(3);
    EXPECT_TRUE(isColor(cards)) << "Color combination not identified.";
}

TEST(CombinationIdentification, ColorFalse) {
    std::vector<ClanCard> cards(2);
    cards.push_back(ClanCard(2, CardColors::BLUE));

    EXPECT_FALSE(isColor(cards)) << "Wrong combination identified as Color.";
}

TEST(CombinationIdentification, Color_EmptyVector) {
    std::vector<ClanCard> cards;
    EXPECT_FALSE(isColor(cards)) << "Empty card vector identified as Color";
}

TEST(CombinationIdentification, Color_SingleCard) {
    std::vector<ClanCard> cards(1);
    EXPECT_FALSE(isColor(cards)) << "Single card vector identified as Color";
}

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