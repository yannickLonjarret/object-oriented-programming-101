#include <deque>

#include "playerId.h"

namespace Stone {
class CompletionOrder {
  private:
    std::deque<Agent::PlayerID> order;

  public:
    inline Agent::PlayerID CompletionOrder::getFirstToComplete() const noexcept { return order.front(); }
    void addCompletion(const Agent::PlayerID& player);
};

} // namespace Stone
