#ifndef PLAYER_H
#define PLAYER_H

#include <optional>
#include <string>
#include <string_view>

#include "card.h"
#include "playerId.h"

namespace Agent {
class Player {
  private:
    std::string name;
    PlayerID id;
    std::vector<Cards::Card> hand;
    size_t maxHandSize;

  public:
    std::string_view getName() const noexcept { return name; }
    bool isHandEmpty() const noexcept { return hand.empty(); }

    bool try_addCard(const Cards::Card& c);
    std::optional<Cards::Card> try_getCard(const size_t i);
};

} // namespace Agent

#endif