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
    Side(Agent::PlayerID id = Agent::PlayerID(), size_t max = 3) : owner(id), maxPlayableCardCount(max) { playedCards.reserve(maxPlayableCardCount); }

    inline Agent::PlayerID getOwner() const noexcept { return owner; }

    inline const std::vector<Cards::ClanCard>& getPlayedCards() const noexcept { return playedCards; }

    inline bool isComplete() const noexcept { return playedCards.size() >= maxPlayableCardCount; }

    bool try_playCard(Cards::ClanCard&& cardToPlay) noexcept;
};

} // namespace Stone

#endif