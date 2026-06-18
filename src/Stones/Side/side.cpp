#include "side.h"

namespace Stone {

bool Side::try_playCard(Cards::ClanCard&& cardToPlay) {
    if (isComplete()) {
        return false;
    }
    playedCards.push_back(std::move(cardToPlay));
    return true;
}

} // namespace Stone