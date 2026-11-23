#ifndef PLAYER_H
#define PLAYER_H

#include <optional>
#include <string>
#include <string_view>

#include "card.h"
#include "playerIDService.h"
#include "playerId.h"

namespace Agent {
using namespace utils;
class Player {
  private:
    std::string name;
    PlayerID id;
    // Given behaviour of try_getCard, std::hive would the best here
    std::vector<Cards::ClanCard> hand;
    const unsigned int maxHandSize = 6;

  public:
    Player(const std::string& playerName) : name(playerName) { id = service::PlayerID::Fetch()->generateUniqueID(name); }
    std::string_view getName() const noexcept { return name; }
    bool isHandEmpty() const noexcept { return hand.empty(); }

    bool try_addCard(const Cards::ClanCard& c);
    std::optional<Cards::ClanCard> try_getCard(const unsigned int i = 0);
};

} // namespace Agent

#endif