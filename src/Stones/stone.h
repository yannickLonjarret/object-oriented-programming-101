#ifndef STONE_H
#define STONE_H

#include <map>
#include <optional>
#include <string>
#include <vector>

#include "combination.h"
#include "completionOrder.h"
#include "playerId.h"
#include "side.h"

namespace Stone {
using namespace Combination;

class Stone {
  private:
    std::vector<Combination::Type> eligibleCombinations;
    std::map<Agent::PlayerID, Side> playerSides;
    std::optional<Agent::PlayerID> claimedBy;
    CompletionOrder history;

  public:
    Stone() {};

    Stone(const std::vector<Agent::PlayerID>& players, const std::vector<Type>& combinations) : eligibleCombinations(combinations) {
        for (const auto& p : players) {
            playerSides.try_emplace(p);
        }
    }

    bool tryPlayCardAs(const Agent::PlayerID& player, const Cards::ClanCard& card);

    inline bool isClaimed() const noexcept { return claimedBy.has_value(); }

    Agent::PlayerID getWinner() const noexcept;

    bool canPlayerClaim(const Agent::PlayerID& player) const;

    bool tryResolveStoneCombinationAs(const Agent::PlayerID& player);

    bool tryClaimStoneByProofAs(const Agent::PlayerID& player, const std::vector<Cards::ClanCard>& possibleCards);

  private:
    std::vector<CardCombination> combinationAllOpponents(const std::vector<Side>& allOpponents,
                                                         const std::vector<Cards::ClanCard>& possibleCards) const;

    std::vector<CardCombination> combinationSingleOpponent(const Side& opponent, const std::vector<Cards::ClanCard>& possibleCards) const;

    std::vector<std::vector<int>> cardIndexCombinationGeneration(const int combinationSize, const int maxIndex) const;
};
} // namespace Stone

#endif