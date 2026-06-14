#include <gtest/gtest.h>

#include "playerId.h"

TEST(PlayerIdTest, Comparison_SameHashSource) {
    Agent::PlayerID idA = Agent::PlayerID();
    Agent::PlayerID idB = Agent::PlayerID();

    EXPECT_EQ(idA, idB);
    EXPECT_EQ(idB, idA);
}

TEST(PlayerIdTest, Comparison_DifferentHashSource) {
    Agent::PlayerID idA = Agent::PlayerID("Test1");
    Agent::PlayerID idB = Agent::PlayerID("Test2");

    EXPECT_NE(idA, idB);
    EXPECT_NE(idB, idA);
}
