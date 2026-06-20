#include "stone.h"

using namespace Combination;

namespace Stone {

bool Stone::canPlayerClaim(const Agent::PlayerID& player) const {
    const auto it = playerSides.find(player);

    if (it == playerSides.cend()) [[unlikely]] {
        return false;
    }
    return it->second.isComplete();
}

bool Stone::tryClaimStoneCombinationAs(const Agent::PlayerID& player) {
    if (!canPlayerClaim(player)) {
        return false;
    }

    for (const auto& [_, otherSide] : playerSides) {
        if (!otherSide.isComplete()) {
            return false;
        }
    }

    const Side& side = playerSides.at(player);
    CardCombination highestCombination = CardCombination(side.getPlayedCards());
    Agent::PlayerID winner = player;
    for (const auto& [otherPlayer, otherSide] : playerSides) {
        if (otherPlayer == player) {
            continue;
        }

        CardCombination candidate(otherSide.getPlayedCards());
        if (highestCombination == candidate) {
            // TODO tie break logic
        }

        if (highestCombination < candidate) {
            highestCombination = candidate;
            winner = otherPlayer;
        }
    }

    claimedBy = winner;

    return true;
}

} // namespace Stone