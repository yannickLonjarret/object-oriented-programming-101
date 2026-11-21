#include "completionOrder.h"
#include "playerId.h"

#include <algorithm>
#include <stdexcept>

namespace Stone {

void CompletionOrder::addCompletion(const Agent::PlayerID& player) {
    if (std::ranges::find(order, player) != order.cend()) {
        return;
    }
    order.push_back(player);
}

Agent::PlayerID CompletionOrder::getEarliest(const Agent::PlayerID& candidate, const Agent::PlayerID& contender) const {
    const auto& candidateIterator = std::ranges::find(order, candidate);
    const auto& contenderIterator = std::ranges::find(order, contender);

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
