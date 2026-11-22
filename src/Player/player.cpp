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

std::optional<Cards::ClanCard> Player::try_getCard(const size_t i) {
    if (isHandEmpty()) {
        return std::nullopt;
    }

    if (hand.size() - 1 < i) {
        return std::nullopt;
    }
    Cards::ClanCard c(hand.at(i));
    std::erase(hand, c);

    auto option(std::make_optional<Cards::ClanCard>(c));
    return option;
}
} // namespace Agent
