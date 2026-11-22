#include <gtest/gtest.h>

#include "playerIDService.h"

TEST(PlayerIDServiceTest, UnicityTest) {

    Agent::PlayerID first(utils::service::PlayerID::Fetch()->generateUniqueID("Hello"));
    Agent::PlayerID second(utils::service::PlayerID::Fetch()->generateUniqueID("Hello"));

    EXPECT_NE(first, second);
}
