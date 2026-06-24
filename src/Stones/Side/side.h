#ifndef SIDE_H
#define SIDE_H

#include <format>
#include <stdexcept>
#include <vector>

#include "card.h"

namespace Stone {
class Side {
  private:
    size_t maxPlayableCardCount;
    std::vector<Cards::ClanCard> playedCards;

  public:
    Side(size_t max = 3) : maxPlayableCardCount(max) { playedCards.reserve(maxPlayableCardCount); }

    inline const std::vector<Cards::ClanCard>& getPlayedCards() const noexcept { return playedCards; }

    inline bool isComplete() const noexcept { return playedCards.size() >= maxPlayableCardCount; }

    bool try_playCard(const Cards::ClanCard& cardToPlay);
};

} // namespace Stone

#endif