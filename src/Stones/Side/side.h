#ifndef SIDE_H
#define SIDE_H

#include <format>
#include <stdexcept>
#include <vector>

#include "card.h"
#include "playerId.h"

namespace Stone {
class Side {
  private:
    Agent::PlayerID owner;
    size_t maxPlayableCardCount;
    std::vector<Cards::ClanCard> playedCards;

  public:
    Side(Agent::PlayerID id, size_t max = 3) : owner(id), maxPlayableCardCount(max) { playedCards.reserve(maxPlayableCardCount); }

    inline Agent::PlayerID getOwner() const noexcept { return owner; }

    inline const std::vector<Cards::ClanCard>& getPlayedCards() const noexcept { return playedCards; }

    inline bool isComplete() const noexcept { return playedCards.size() >= maxPlayableCardCount; }

    inline void playCard(Cards::ClanCard&& cardToPlay) {
        if (isComplete()) {
            throw std::logic_error("Cannot play card, complete site.");
        }
        playedCards.push_back(std::move(cardToPlay));
    }
};

} // namespace Stone

#endif