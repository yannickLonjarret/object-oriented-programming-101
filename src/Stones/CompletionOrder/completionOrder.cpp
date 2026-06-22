#include "completionOrder.h"

namespace Stone {

void CompletionOrder::addCompletion(const Agent::PlayerID& player) {
    if (std::find(order.cbegin(), order.cend(), player) != order.cend()) {
        return;
    }
    order.push_back(player);
}
} // namespace Stone
