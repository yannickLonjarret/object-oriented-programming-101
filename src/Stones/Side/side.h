#ifndef SIDE_H
#define SIDE_H

#include <format>
#include <stdexcept>
#include <vector>

#include "card.h"

namespace Stone {
class Side {
  private:
    int maxPlayableCardCount;
    std::vector<Cards::ClanCard> playedCards;

  public:
    Side(int max = 3) : maxPlayableCardCount(max) { playedCards.reserve(maxPlayableCardCount); }

    inline const std::vector<Cards::ClanCard>& getPlayedCards() const noexcept { return playedCards; }

    inline const int getRemainingSize() const noexcept { return maxPlayableCardCount - static_cast<int>(playedCards.size()); }

    inline bool isComplete() const noexcept { return playedCards.size() >= maxPlayableCardCount; }

    bool tryPlayCard(const Cards::ClanCard& cardToPlay);
};

} // namespace Stone

#endif