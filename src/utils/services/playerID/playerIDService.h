#ifndef PLAYER_ID_SERVICE_H
#define PLAYER_ID_SERVICE_H

#include <memory>
#include <unordered_set>

#include "playerId.h"
namespace utils::service {
class PlayerIDService {
  private:
    std::unordered_set<Agent::PlayerID> database;
    static std::unique_ptr<PlayerIDService> singleService;

  public:
    static const std::unique_ptr<PlayerIDService>& Service();
    Agent::PlayerID generateUniqueID(const std::string& base) noexcept;
};

std::unique_ptr<PlayerIDService> PlayerIDService::singleService = nullptr;
} // namespace utils::service

#endif