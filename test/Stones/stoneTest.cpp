#include <gtest/gtest.h>

#include "stone.h"

Stone::Stone getTestStone() {
    using namespace Combination;
    std::vector<Agent::PlayerID> players = {Agent::PlayerID("Player_1"), Agent::PlayerID("Player_2")};
    std::vector<Combination::Type> winConditions = {Type::COLOR, Type::COLORED_SERIE, Type::KIND, Type::SERIE, Type::SUM};

    return Stone::Stone(players, winConditions);
}

Cards::ClanCard getDefaultClanCard() { return Cards::ClanCard(); }

TEST(StoneTest, isClaimed_False) {
    Stone::Stone testStone = getTestStone();
    Agent::PlayerID player1("Player_1");
    Agent::PlayerID player2("Player_2");

    EXPECT_FALSE(testStone.isClaimed());

    constexpr int defaultMaxSize = 3;
    for (int i = 0; i < defaultMaxSize; i++) {
        testStone.tryPlayCardAs(player1, getDefaultClanCard());
        testStone.tryPlayCardAs(player2, getDefaultClanCard());
    }

    EXPECT_FALSE(testStone.isClaimed());
}

TEST(StoneTest, isClaimed_True) {
    Stone::Stone testStone = getTestStone();
    Agent::PlayerID player1("Player_1");
    Agent::PlayerID player2("Player_2");

    constexpr int defaultMaxSize = 3;
    for (int i = 0; i < defaultMaxSize; i++) {
        testStone.tryPlayCardAs(player1, getDefaultClanCard());
        testStone.tryPlayCardAs(player2, getDefaultClanCard());
    }
    testStone.tryResolveStoneCombinationAs(player1);

    EXPECT_TRUE(testStone.isClaimed());
}

TEST(StoneTest, tryPlayCardAs_Success) {
    Stone::Stone testStone = getTestStone();
    Agent::PlayerID player1("Player_1");

    EXPECT_TRUE(testStone.tryPlayCardAs(player1, getDefaultClanCard()));
}

TEST(StoneTest, tryPlayCardAs_FailureFull) {
    Stone::Stone testStone = getTestStone();
    Agent::PlayerID player1("Player_1");

    constexpr int defaultMaxSize = 3;
    for (int i = 0; i < defaultMaxSize; i++) {
        testStone.tryPlayCardAs(player1, getDefaultClanCard());
    }
    EXPECT_FALSE(testStone.tryPlayCardAs(player1, getDefaultClanCard()));
}

TEST(StoneTest, tryPlayCardAs_FailureClaimed) {
    Stone::Stone testStone = getTestStone();
    Agent::PlayerID player1("Player_1");
    Agent::PlayerID player2("Player_2");

    constexpr int defaultMaxSize = 3;
    for (int i = 0; i < defaultMaxSize; i++) {
        testStone.tryPlayCardAs(player1, getDefaultClanCard());
        testStone.tryPlayCardAs(player2, getDefaultClanCard());
    }
    testStone.tryResolveStoneCombinationAs(player1);

    EXPECT_FALSE(testStone.tryPlayCardAs(player1, getDefaultClanCard()));
}

TEST(StoneTest, canPlayerClaim_Success) {
    Stone::Stone testStone = getTestStone();
    Agent::PlayerID player1("Player_1");

    constexpr int defaultMaxSize = 3;
    for (int i = 0; i < defaultMaxSize; i++) {
        testStone.tryPlayCardAs(player1, getDefaultClanCard());
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
        testStone.tryPlayCardAs(player1, getDefaultClanCard());
        testStone.tryPlayCardAs(player2, getDefaultClanCard());
    }
    testStone.tryResolveStoneCombinationAs(player1);

    EXPECT_FALSE(testStone.canPlayerClaim(player1));
}

TEST(StoneTest, canPlayerClaim_BadInput) {
    Stone::Stone testStone = getTestStone();

    EXPECT_FALSE(testStone.canPlayerClaim(Agent::PlayerID()));
}

TEST(StoneTest, tryResolveStoneCombinationAs_Player1Win) {
    Stone::Stone testStone = getTestStone();
    Agent::PlayerID player1("Player_1");
    Agent::PlayerID player2("Player_2");

    testStone.tryPlayCardAs(player1, (ClanCard(1, CardColors::BLUE)));
    testStone.tryPlayCardAs(player1, (ClanCard(2, CardColors::BLUE)));
    testStone.tryPlayCardAs(player1, (ClanCard(3, CardColors::BLUE)));

    testStone.tryPlayCardAs(player2, (ClanCard(7, CardColors::RED)));
    testStone.tryPlayCardAs(player2, (ClanCard(7, CardColors::BLUE)));
    testStone.tryPlayCardAs(player2, (ClanCard(7, CardColors::YELLOW)));

    EXPECT_TRUE(testStone.tryResolveStoneCombinationAs(player1));
    EXPECT_EQ(testStone.getWinner(), player1);
}

TEST(StoneTest, tryResolveStoneCombinationAs_Player2Win) {
    Stone::Stone testStone = getTestStone();
    Agent::PlayerID player1("Player_1");
    Agent::PlayerID player2("Player_2");

    testStone.tryPlayCardAs(player2, (ClanCard(1, CardColors::BLUE)));
    testStone.tryPlayCardAs(player2, (ClanCard(2, CardColors::BLUE)));
    testStone.tryPlayCardAs(player2, (ClanCard(3, CardColors::BLUE)));

    testStone.tryPlayCardAs(player1, (ClanCard(7, CardColors::RED)));
    testStone.tryPlayCardAs(player1, (ClanCard(7, CardColors::BLUE)));
    testStone.tryPlayCardAs(player1, (ClanCard(7, CardColors::YELLOW)));

    EXPECT_TRUE(testStone.tryResolveStoneCombinationAs(player2));
    EXPECT_EQ(testStone.getWinner(), player2);
}

TEST(StoneTest, tryResolveStoneCombinationAs_Player1Win_TieBreak) {
    Stone::Stone testStone = getTestStone();
    Agent::PlayerID player1("Player_1");
    Agent::PlayerID player2("Player_2");

    constexpr int defaultMaxSize = 3;
    for (int i = 0; i < defaultMaxSize; i++) {
        testStone.tryPlayCardAs(player1, getDefaultClanCard());
        testStone.tryPlayCardAs(player2, getDefaultClanCard());
    }

    EXPECT_TRUE(testStone.tryResolveStoneCombinationAs(player1));
    EXPECT_EQ(testStone.getWinner(), player1);
}

TEST(StoneTest, tryResolveStoneCombinationAs_Player2Win_TieBreak) {
    Stone::Stone testStone = getTestStone();
    Agent::PlayerID player1("Player_1");
    Agent::PlayerID player2("Player_2");

    constexpr int defaultMaxSize = 3;
    for (int i = 0; i < defaultMaxSize; i++) {
        testStone.tryPlayCardAs(player2, getDefaultClanCard());
        testStone.tryPlayCardAs(player1, getDefaultClanCard());
    }

    EXPECT_TRUE(testStone.tryResolveStoneCombinationAs(player2));
    EXPECT_EQ(testStone.getWinner(), player2);
}

TEST(StoneTest, tryResolveStoneCombinationAs_IncompleteHand) {
    Stone::Stone testStone = getTestStone();
    Agent::PlayerID player1("Player_1");
    Agent::PlayerID player2("Player_2");

    constexpr int defaultMaxSize = 3;
    for (int i = 0; i < defaultMaxSize; i++) {
        testStone.tryPlayCardAs(player2, getDefaultClanCard());
    }

    EXPECT_FALSE(testStone.tryResolveStoneCombinationAs(player1));
    EXPECT_EQ(testStone.getWinner(), Agent::PlayerID());
}

TEST(StoneTest, tryResolveStoneCombinationAs_IncompleteOpponenHand) {
    Stone::Stone testStone = getTestStone();
    Agent::PlayerID player1("Player_1");

    constexpr int defaultMaxSize = 3;
    for (int i = 0; i < defaultMaxSize; i++) {
        testStone.tryPlayCardAs(player1, getDefaultClanCard());
    }

    EXPECT_FALSE(testStone.tryResolveStoneCombinationAs(player1));
    EXPECT_EQ(testStone.getWinner(), Agent::PlayerID());
}

TEST(StoneTest, tryResolveStoneCombinationAs_UnknownPlayer) {
    Stone::Stone testStone = getTestStone();
    Agent::PlayerID badPlayer("RandomInput");

    EXPECT_FALSE(testStone.tryResolveStoneCombinationAs(badPlayer));
    EXPECT_EQ(testStone.getWinner(), Agent::PlayerID());
}
