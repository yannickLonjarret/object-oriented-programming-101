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
    size_t maxHandSize = 3;

  public:
    Player(const std::string& playerName, const size_t& max) : name(playerName), maxHandSize(max) {}
    std::string_view getName() const noexcept { return name; }
    bool isHandEmpty() const noexcept { return hand.empty(); }

    bool try_addCard(const Cards::Card& c);
    std::optional<Cards::Card> try_getCard(const size_t i);
};

} // namespace Agent

#endif