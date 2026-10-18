#include "side.h"

namespace Stone {

bool Side::tryPlayCard(const Cards::ClanCard& cardToPlay) {
    if (isComplete()) {
        return false;
    }
    playedCards.push_back(cardToPlay);
    return true;
}

} // namespace Stone