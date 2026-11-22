#ifndef PLAYER_ID_SERVICE_H
#define PLAYER_ID_SERVICE_H

#include <memory>
#include <set>

#include "playerId.h"
namespace utils::service {
class PlayerIDService {
  private:
    std::set<Agent::PlayerID> database;
    static std::unique_ptr<PlayerIDService> singleService;

  public:
    static const std::unique_ptr<PlayerIDService>& Service() noexcept;
    Agent::PlayerID generateUniqueID(const std::string& base) noexcept;
};

std::unique_ptr<PlayerIDService> PlayerIDService::singleService = nullptr;
} // namespace utils::service

#endif