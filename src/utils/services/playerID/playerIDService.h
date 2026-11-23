#ifndef PLAYER_ID_SERVICE_H
#define PLAYER_ID_SERVICE_H

#include <memory>
#include <set>
#include <string>

#include "playerId.h"
namespace utils::service {
class PlayerID {
  private:
    std::set<Agent::PlayerID> database;
    static std::unique_ptr<PlayerID> singleService;

  public:
    static const std::unique_ptr<PlayerID>& Fetch() noexcept;
    Agent::PlayerID generateUniqueID(const std::string& base);
};
} // namespace utils::service

#endif