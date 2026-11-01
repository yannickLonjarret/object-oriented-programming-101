#include "stone.h"

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

        CardCombination candidate(otherSide.getPlayedCards());
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

    std::vector<Side> opponents;
    for (const auto& [id, otherSide] : playerSides) {
        if (player == id) {
            continue;
        }
        opponents.push_back(otherSide);
    }

    const Side& side = playerSides.at(player);
    CardCombination contender(side.getPlayedCards());

    std::vector<CardCombination> possibilities = combinationAllOpponents(opponents, possibleCards);
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

    for (const auto& side : allOpponents) {
        std::vector<CardCombination> temp = combinationSingleOpponent(side, possibleCards);
        result.insert(result.cend(), temp.cbegin(), temp.cend());
    }

    return result;
}

std::vector<CardCombination> Stone::combinationSingleOpponent(const Side& opponent, const std::vector<Cards::ClanCard>& possibleCards) const {
    const int maxIndex = static_cast<int>(possibleCards.size());
    std::vector<std::vector<int>> possibleIndex = cardIndexCombinationGeneration(opponent.getRemainingSize(), maxIndex);
    std::vector<CardCombination> combo;
    for (const auto& vec : possibleIndex) {
        std::vector<Cards::ClanCard> playedCards(opponent.getPlayedCards());
        for (const auto& i : vec) {
            playedCards.push_back(possibleCards.at(i));
        }
        combo.push_back(playedCards);
    }

    return combo;
}

std::vector<std::vector<int>> Stone::cardIndexCombinationGeneration(const int combinationSize, const int maxIndex) const {
    if (combinationSize > maxIndex) {
        return {};
    }
    std::vector<std::vector<int>> results;
    std::vector<int> combo;
    combo.reserve(combinationSize);
    for (int i = 0; i < combinationSize; i++) {
        combo.push_back(i);
    }

    while (true) {
        results.push_back(combo);
        int i = combinationSize - 1;

        while (i >= 0 && combo.at(i) == maxIndex - combinationSize + i) {
            i--;
        }

        if (i < 0) {
            break;
        }

        combo.at(i)++;

        for (int j = i + 1; j < combinationSize; j++) {
            combo.at(j) = combo.at(j - 1) + 1;
        }
    }

    return results;
}
} // namespace Stone