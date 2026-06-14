#ifndef STONE_H
#define STONE_H

#include <map>
#include <optional>
#include <string>
#include <vector>

#include "combination.h"
#include "playerId.h"
#include "side.h"

namespace Stone {

class Stone {
  private:
    std::vector<Combination::Type> eligibleCombinations;
    std::map<Agent::PlayerID, Side> playerSides;
    std::optional<Agent::PlayerID> claimedBy;

  public:
    inline bool isClaimed() const noexcept { return claimedBy.has_value(); }

    bool canPlayerClaim(const Agent::PlayerID& player) const;

    void claimStoneAs(const Agent::PlayerID& player);
};
} // namespace Stone

#endif