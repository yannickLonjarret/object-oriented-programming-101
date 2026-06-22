#include <deque>

#include "playerId.h"

namespace Stone {
class CompletionOrder {
  private:
    std::deque<Agent::PlayerID> order;

  public:
    inline Agent::PlayerID getFirstToComplete() const noexcept { return order.front(); }
    [[nodiscard]] Agent::PlayerID getEarliest(const Agent::PlayerID& candidate, const Agent::PlayerID& contender) const;
    void addCompletion(const Agent::PlayerID& player);
};

} // namespace Stone
