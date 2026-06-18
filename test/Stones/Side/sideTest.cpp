#include <gtest/gtest.h>

#include "side.h"

TEST(StoneSide, PlayCard_Success) {
    Stone::Side s = Stone::Side();
    Cards::ClanCard c = Cards::ClanCard();
    EXPECT_TRUE(s.try_playCard(std::move(c)));
}

TEST(StoneSide, PlayCard_Failure) {
    Agent::PlayerID id = Agent::PlayerID();
    Stone::Side s = Stone::Side(id, 0);
    Cards::ClanCard c = Cards::ClanCard();
    EXPECT_FALSE(s.try_playCard(std::move(c)));
    EXPECT_EQ(c.getColor(), Cards::CardColors::EMPTY);
}

TEST(StoneSide, PlayCard_FailureAfterFill) {
    Agent::PlayerID id = Agent::PlayerID();
    Stone::Side s = Stone::Side(id, 1);
    Cards::ClanCard c = Cards::ClanCard();
    EXPECT_TRUE(s.try_playCard(std::move(c)));
    c = Cards::ClanCard();
    EXPECT_FALSE(s.try_playCard(std::move(c)));
}

TEST(StoneSide, isComplete_False) {
    Stone::Side s = Stone::Side();
    EXPECT_FALSE(s.isComplete());
}

TEST(StoneSide, isComplete_True) {
    Agent::PlayerID id = Agent::PlayerID();
    Stone::Side s = Stone::Side(id, 1);
    Cards::ClanCard c = Cards::ClanCard();

    s.try_playCard(std::move(c));
    EXPECT_TRUE(s.isComplete());
}

TEST(StoneSide, isComplete_StatusTransition) {
    Agent::PlayerID id = Agent::PlayerID();
    Stone::Side s = Stone::Side(id, 1);
    Cards::ClanCard c = Cards::ClanCard();

    EXPECT_FALSE(s.isComplete());
    s.try_playCard(std::move(c));
    EXPECT_TRUE(s.isComplete());
}

TEST(StoneSide, getPlayedCards_Empty) {
    Stone::Side s = Stone::Side();
    EXPECT_TRUE(s.getPlayedCards().empty());
}

TEST(StoneSide, getPlayedCards_Filled) {
    Stone::Side s = Stone::Side();

    Cards::ClanCard c = Cards::ClanCard(5, Cards::CardColors::BROWN);
    s.try_playCard(std::move(c));
    c = Cards::ClanCard(2, Cards::CardColors::RED);
    s.try_playCard(std::move(c));

    const std::vector<Cards::ClanCard>& vec = s.getPlayedCards();

    EXPECT_FALSE(vec.empty());
    EXPECT_EQ(vec.size(), 2);
    EXPECT_EQ(vec.at(0), Cards::ClanCard(5, Cards::CardColors::BROWN));
    EXPECT_EQ(vec.at(1), Cards::ClanCard(2, Cards::CardColors::RED));
}

TEST(StoneSide, getOwner) {
    Stone::Side s = Stone::Side();
    EXPECT_EQ(s.getOwner(), Agent::PlayerID());
}