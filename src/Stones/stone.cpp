#include "stone.h"

#include <utility>
#include <vector>

#include "card.h"
#include "combination.h"
#include "playerId.h"
#include "utils_math.h"

using namespace Combination;

namespace Stone {

Agent::PlayerID Stone::getWinner() const noexcept { return claimedBy.value_or(Agent::PlayerID()); }

bool Stone::tryPlayCardAs(const Agent::PlayerID& player, const Cards::ClanCard& card) {
    if (isClaimed()) {
        return false;
    }

    const auto& side = playerSides.find(player);
    if (side == playerSides.end()) {
        return false;
    }

    if (side->second.isComplete()) {
        return false;
    }

    if (!side->second.tryPlayCard(card)) {
        return false;
    }

    if (side->second.isComplete()) {
        history.addCompletion(player);
    }

    return true;
}

bool Stone::canPlayerClaim(const Agent::PlayerID& player) const {
    const auto it = playerSides.find(player);

    if (it == playerSides.cend()) [[unlikely]] {
        return false;
    }

    if (isClaimed()) {
        return false;
    }

    return it->second.isComplete();
}

bool Stone::tryResolveStoneCombinationAs(const Agent::PlayerID& player) {
    if (!canPlayerClaim(player)) {
        return false;
    }

    for (const auto& [_, otherSide] : playerSides) {
        if (!otherSide.isComplete()) {
            return false;
        }
    }

    const Side& side = playerSides.at(player);
    CardCombination highestCombination(side.getPlayedCards());
    Agent::PlayerID winner(player);
    for (const auto& [otherPlayer, otherSide] : playerSides) {
        if (otherPlayer == player) {
            continue;
        }

        const CardCombination candidate(otherSide.getPlayedCards());
        if (highestCombination == candidate) [[unlikely]] {
            winner = history.getEarliest(winner, otherPlayer);
        } else if (highestCombination < candidate) {
            highestCombination = candidate;
            winner = otherPlayer;
        }
    }

    claimedBy = winner;

    return true;
}

bool Stone::tryClaimStoneByProofAs(const Agent::PlayerID& player, const std::vector<Cards::ClanCard>& possibleCards) {
    if (!canPlayerClaim(player)) {
        return false;
    }

    const Side& side = playerSides.at(player);
    const CardCombination contender(side.getPlayedCards());
    for (const auto& [otherPlayer, otherSide] : playerSides) {
        if (otherPlayer == player) {
            continue;
        }

        if (!otherSide.isComplete()) {
            continue;
        }

        const CardCombination candidate(otherSide.getPlayedCards());
        if (contender == candidate) [[unlikely]] {
            if (otherPlayer == history.getEarliest(player, otherPlayer)) {
                return false;
            }
        } else if (contender < candidate) {
            return false;
        }
    }

    std::vector<Side> opponents;
    for (const auto& [id, otherSide] : playerSides) {
        if (player == id) {
            continue;
        }

        if (otherSide.isComplete()) {
            continue;
        }
        opponents.push_back(otherSide);
    }

    const std::vector<CardCombination> possibilities = combinationAllOpponents(opponents, possibleCards);
    for (const auto& combo : possibilities) {
        if (contender < combo) {
            return false;
        }
    }

    claimedBy = player;
    return true;
}

std::vector<CardCombination> Stone::combinationAllOpponents(const std::vector<Side>& allOpponents,
                                                            const std::vector<Cards::ClanCard>& possibleCards) const {
    std::vector<CardCombination> result;
    const unsigned int comboUpperBound = allOpponents.size() * utils::math::binomialCoeff(54, 3);
    result.reserve(comboUpperBound);
    for (const auto& side : allOpponents) {
        const std::vector<CardCombination> temp = combinationSingleOpponent(side, possibleCards);
        result.insert(result.cend(), temp.cbegin(), temp.cend());
    }

    return result;
}

std::vector<CardCombination> Stone::combinationSingleOpponent(const Side& opponent, const std::vector<Cards::ClanCard>& possibleCards) const {
    std::vector<CardCombination> combo;
    if (opponent.isComplete()) {
        return combo;
    }

    const auto maxIndex = static_cast<unsigned int>(possibleCards.size());
    std::vector<std::vector<unsigned int>> possibleIndex;
    constexpr unsigned int maxCardsCount = 54;
    constexpr unsigned int averageSideSize = 3;
    possibleIndex.reserve(utils::math::binomialCoeff(maxCardsCount, averageSideSize));
    possibleIndex = utils::math::k_combination(maxIndex, opponent.getRemainingSize());

    for (const auto& vec : possibleIndex) {
        std::vector<Cards::ClanCard> playedCards(opponent.getPlayedCards());
        for (const auto& i : vec) {
            playedCards.push_back(possibleCards.at(i));
        }
        combo.emplace_back(std::move(playedCards));
    }

    return combo;
}
} // namespace Stone