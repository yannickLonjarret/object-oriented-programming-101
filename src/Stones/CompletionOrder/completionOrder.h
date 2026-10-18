#ifndef COMPLETION_ORDER_H
#define COMPLETION_ORDER_H

#include <deque>

#include "playerId.h"

namespace Stone {
class CompletionOrder {
  private:
    std::deque<Agent::PlayerID> order;

  public:
    [[nodiscard]] Agent::PlayerID getEarliest(const Agent::PlayerID& candidate, const Agent::PlayerID& contender) const;
    void addCompletion(const Agent::PlayerID& player);
};

} // namespace Stone
#endif