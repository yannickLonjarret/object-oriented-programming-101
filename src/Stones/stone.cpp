#include "stone.h"

namespace Stone {

bool Stone::canPlayerClaim(const Agent::PlayerID& player) const {
    const auto it = playerSides.find(player);

    if (it == playerSides.cend()) [[unlikely]] {
        return false;
    }
    return it->second.isComplete();
}

void Stone::claimStoneAs(const Agent::PlayerID& player) {
    if (!canPlayerClaim(player)) {
        // TODO: Add a better claim failure handler
        return;
    }
    // TODO: Claim logic
}

} // namespace Stone