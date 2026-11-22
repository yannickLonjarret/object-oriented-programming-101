#include "playerIDService.h"

#include <format>
#include <memory>
#include <random>
#include <unordered_set>

#include "playerId.h"

namespace utils::service {

const std::unique_ptr<PlayerIDService>& PlayerIDService::Service() {
    if (!singleService) {
        singleService = std::make_unique<PlayerIDService>();
    }

    return singleService;
}

Agent::PlayerID PlayerIDService::generateUniqueID(const std::string& base) {
    static std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<unsigned int> distrib(0, 9999);

    Agent::PlayerID uniqueID;
    do {
        std::string toHash{std::format("{}#{:04d}", base, distrib(gen))};
        uniqueID = Agent::PlayerID(toHash);
    } while (!database.emplace(uniqueID).second);

    return uniqueID;
}
} // namespace utils::service