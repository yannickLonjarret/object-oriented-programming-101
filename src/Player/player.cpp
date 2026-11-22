#include "player.h"

#include <optional>

#include "card.h"
#include "playerId.h"

namespace Agent {
bool Player::try_addCard(const Cards::ClanCard& c) {
    if (hand.size() == maxHandSize) {
        return false;
    }
    hand.emplace_back(c);
    return true;
}
} // namespace Agent
