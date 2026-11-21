#include "side.h"

#include "card.h"

namespace Stone {

bool Side::tryPlayCard(const Cards::ClanCard& cardToPlay) {
    if (isComplete()) {
        return false;
    }
    playedCards.emplace_back(cardToPlay);
    return true;
}

} // namespace Stone