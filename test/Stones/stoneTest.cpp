#include <gtest/gtest.h>

#include "stone.h"

Stone::Stone getTestStone() {
    using namespace Combination;
    std::vector<Agent::PlayerID> players = {Agent::PlayerID("Player_1"), Agent::PlayerID("Player_2")};
    std::vector<Combination::Type> winConditions = {Type::COLOR, Type::COLORED_SERIE, Type::KIND, Type::SERIE, Type::SUM};

    return Stone::Stone(players, winConditions);
}

TEST(StoneTest, isClaimed_False) {
    Stone::Stone testStone = getTestStone();
    Agent::PlayerID player1("Player_1");
    Agent::PlayerID player2("Player_2");

    EXPECT_FALSE(testStone.isClaimed());

    constexpr int defaultMaxSize = 3;
    for (int i = 0; i < defaultMaxSize; i++) {
        testStone.tryPlayCardAs(player1, ClanCard::ClanCard());
        testStone.tryPlayCardAs(player2, ClanCard::ClanCard());
    }

    EXPECT_FALSE(testStone.isClaimed());
}

TEST(StoneTest, isClaimed_True) {
    Stone::Stone testStone = getTestStone();
    Agent::PlayerID player1("Player_1");
    Agent::PlayerID player2("Player_2");

    constexpr int defaultMaxSize = 3;
    for (int i = 0; i < defaultMaxSize; i++) {
        testStone.tryPlayCardAs(player1, ClanCard::ClanCard());
        testStone.tryPlayCardAs(player2, ClanCard::ClanCard());
    }
    testStone.tryResolveStoneCombinationAs(player1);

    EXPECT_TRUE(testStone.isClaimed());
}

TEST(StoneTest, tryPlayCardAs_Success) {
    Stone::Stone testStone = getTestStone();
    Agent::PlayerID player1("Player_1");

    EXPECT_TRUE(testStone.tryPlayCardAs(player1, ClanCard::ClanCard()));
}

TEST(StoneTest, tryPlayCardAs_FailureFull) {
    Stone::Stone testStone = getTestStone();
    Agent::PlayerID player1("Player_1");

    constexpr int defaultMaxSize = 3;
    for (int i = 0; i < defaultMaxSize; i++) {
        testStone.tryPlayCardAs(player1, ClanCard::ClanCard());
    }
    EXPECT_FALSE(testStone.tryPlayCardAs(player1, ClanCard::ClanCard()));
}

TEST(StoneTest, tryPlayCardAs_FailureClaimed) {
    Stone::Stone testStone = getTestStone();
    Agent::PlayerID player1("Player_1");
    Agent::PlayerID player2("Player_2");

    constexpr int defaultMaxSize = 3;
    for (int i = 0; i < defaultMaxSize; i++) {
        testStone.tryPlayCardAs(player1, ClanCard::ClanCard());
        testStone.tryPlayCardAs(player2, ClanCard::ClanCard());
    }
    testStone.tryResolveStoneCombinationAs(player1);

    EXPECT_FALSE(testStone.tryPlayCardAs(player1, ClanCard::ClanCard()));
}

TEST(StoneTest, canPlayerClaim_Success) {
    Stone::Stone testStone = getTestStone();
    Agent::PlayerID player1("Player_1");

    constexpr int defaultMaxSize = 3;
    for (int i = 0; i < defaultMaxSize; i++) {
        testStone.tryPlayCardAs(player1, ClanCard::ClanCard());
    }

    EXPECT_TRUE(testStone.canPlayerClaim(player1));
}

TEST(StoneTest, canPlayerClaim_FailureNotFull) {
    Stone::Stone testStone = getTestStone();
    Agent::PlayerID player1("Player_1");

    EXPECT_FALSE(testStone.canPlayerClaim(player1));
}

TEST(StoneTest, canPlayerClaim_FailureAlreadyClaimed) {
    Stone::Stone testStone = getTestStone();
    Agent::PlayerID player1("Player_1");
    Agent::PlayerID player2("Player_2");

    constexpr int defaultMaxSize = 3;
    for (int i = 0; i < defaultMaxSize; i++) {
        testStone.tryPlayCardAs(player1, ClanCard::ClanCard());
        testStone.tryPlayCardAs(player2, ClanCard::ClanCard());
    }
    testStone.tryResolveStoneCombinationAs(player1);

    EXPECT_FALSE(testStone.canPlayerClaim(player1));
}

TEST(StoneTest, canPlayerClaim_FailureBadInput) {
    Stone::Stone testStone = getTestStone();
    Agent::PlayerID player1;

    EXPECT_FALSE(testStone.canPlayerClaim(player1));
}
