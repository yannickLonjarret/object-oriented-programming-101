#include "completionOrder.h"
#include <stdexcept>

namespace Stone {

void CompletionOrder::addCompletion(const Agent::PlayerID& player) {
    if (std::find(order.cbegin(), order.cend(), player) != order.cend()) {
        return;
    }
    order.push_back(player);
}

Agent::PlayerID CompletionOrder::getEarliest(const Agent::PlayerID& candidate, const Agent::PlayerID& contender) const {
    const auto& candidateIterator = std::find(order.cbegin(), order.cend(), candidate);
    const auto& contenderIterator = std::find(order.cbegin(), order.cend(), contender);

    if (candidateIterator == order.cend() || contenderIterator == order.cend()) {
        throw std::logic_error("Combination claim tie break error, candidate or contender not complete.");
    }

    if (candidateIterator < contenderIterator) {
        return candidate;
    } else {
        return contender;
    }
}
} // namespace Stone
