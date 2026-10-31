#include <gtest/gtest.h>

#include "side.h"

TEST(StoneSide, PlayCard_Success) {
    Stone::Side s;
    Cards::ClanCard c;
    EXPECT_TRUE(s.tryPlayCard(c));
}

TEST(StoneSide, PlayCard_Failure) {
    Stone::Side s(0);
    Cards::ClanCard c;
    EXPECT_FALSE(s.tryPlayCard(c));
}

TEST(StoneSide, PlayCard_FailureAfterFill) {
    Stone::Side s(1);
    Cards::ClanCard c;
    EXPECT_TRUE(s.tryPlayCard(c));
    c = Cards::ClanCard();
    EXPECT_FALSE(s.tryPlayCard(c));
}

TEST(StoneSide, isComplete_False) {
    Stone::Side s;
    EXPECT_FALSE(s.isComplete());
}

TEST(StoneSide, isComplete_True) {
    Stone::Side s(1);
    Cards::ClanCard c;

    s.tryPlayCard(c);
    EXPECT_TRUE(s.isComplete());
}

TEST(StoneSide, isComplete_StatusTransition) {
    Stone::Side s(1);
    Cards::ClanCard c;

    EXPECT_FALSE(s.isComplete());
    s.tryPlayCard(c);
    EXPECT_TRUE(s.isComplete());
}

TEST(StoneSide, getPlayedCards_Empty) {
    Stone::Side s;
    EXPECT_TRUE(s.getPlayedCards().empty());
}

TEST(StoneSide, getPlayedCards_Filled) {
    Stone::Side s;

    Cards::ClanCard c(5, Cards::CardColors::BROWN);
    s.tryPlayCard(c);
    c = Cards::ClanCard(2, Cards::CardColors::RED);
    s.tryPlayCard(c);

    const std::vector<Cards::ClanCard>& vec = s.getPlayedCards();

    EXPECT_FALSE(vec.empty());
    EXPECT_EQ(vec.size(), 2);
    EXPECT_EQ(vec.at(0), Cards::ClanCard(5, Cards::CardColors::BROWN));
    EXPECT_EQ(vec.at(1), Cards::ClanCard(2, Cards::CardColors::RED));
}