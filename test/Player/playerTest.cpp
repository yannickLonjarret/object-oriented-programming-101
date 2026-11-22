#include <gtest/gtest.h>
#include <optional>

#include "card.h"
#include "player.h"

TEST(PlayerTest, EmptyConstruction) {
    Agent::Player player("Name");

    EXPECT_TRUE(player.isHandEmpty());
    EXPECT_FALSE(player.try_getCard().has_value());
    EXPECT_EQ(player.getName(), "Name");
}

TEST(PlayerTest, CardInsertion_Success) {
    Agent::Player player("Name");
    Cards::ClanCard c;

    EXPECT_TRUE(player.try_addCard(c));
}

TEST(PlayerTest, CardInsertion_FailFullHand) {
    Agent::Player player("Name");
    Cards::ClanCard c;
    constexpr int maxHand = 6;
    for (int i = 0; i < maxHand; i++) {
        player.try_addCard(c);
    }

    EXPECT_FALSE(player.try_addCard(c));
}

TEST(PlayerTest, CardRetrieval_Success) {
    Agent::Player player("Name");
    Cards::ClanCard c;
    player.try_addCard(c);

    auto get = player.try_getCard();
    EXPECT_TRUE(get.has_value());
    EXPECT_EQ(get.value(), c);
}

TEST(PlayerTest, CardRetrieval_UpdateAfterRetrieve) {
    Agent::Player player("Name");
    Cards::ClanCard c;
    player.try_addCard(c);

    player.try_getCard();

    EXPECT_TRUE(player.isHandEmpty());
}

TEST(PlayerTest, CardRetrieval_FailureEmptyCards) {
    Agent::Player player("Name");

    EXPECT_FALSE(player.try_getCard().has_value());
    EXPECT_FALSE(player.try_getCard(1).has_value());
}

TEST(PlayerTest, CardRetrieval_FailureInputTooHigh) {
    Agent::Player player("Name");
    Cards::ClanCard c;
    constexpr int maxHand = 5;
    for (int i = 0; i < maxHand; i++) {
        player.try_addCard(c);
    }

    EXPECT_FALSE(player.try_getCard(10).has_value());
}