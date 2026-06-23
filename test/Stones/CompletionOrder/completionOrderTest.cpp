#include <gtest/gtest.h>

#include "completionOrder.h"

using namespace Stone;

TEST(CompletionOrder, GetEarliest_ExceptionBadContender) {
    Agent::PlayerID candidate = Agent::PlayerID("Test1");
    Agent::PlayerID contender;

    CompletionOrder order;
    order.addCompletion(candidate);
    EXPECT_THROW(order.getEarliest(candidate, contender), std::logic_error) << "Exception not thrown when ID not found in CompletionOrder";
}

TEST(CompletionOrder, GetEarliest_ExceptionBadCandidate) {
    Agent::PlayerID contender = Agent::PlayerID("Test1");
    Agent::PlayerID candidate;

    CompletionOrder order;
    order.addCompletion(contender);
    EXPECT_THROW(order.getEarliest(candidate, contender), std::logic_error) << "Exception not thrown when ID not found in CompletionOrder";
}

TEST(CompletionOrder, GetEarliest_EarlyCandidate) {
    Agent::PlayerID candidate = Agent::PlayerID("Test1");
    Agent::PlayerID contender = Agent::PlayerID("Test2");

    CompletionOrder order;
    order.addCompletion(candidate);
    order.addCompletion(contender);
    EXPECT_EQ(order.getEarliest(candidate, contender), candidate) << "Contender is before candidate. Expected candidate";
}

TEST(CompletionOrder, GetEarliest_EarlyContender) {
    Agent::PlayerID candidate = Agent::PlayerID("Test1");
    Agent::PlayerID contender = Agent::PlayerID("Test2");

    CompletionOrder order;
    order.addCompletion(contender);
    order.addCompletion(candidate);
    EXPECT_EQ(order.getEarliest(candidate, contender), contender) << "Candidate is before contender. Expected contender";
}
