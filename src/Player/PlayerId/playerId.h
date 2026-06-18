#ifndef PLAYERID_H
#define PLAYERID_H

#include <functional>
#include <string>

namespace Agent {

class PlayerID {
  private:
    size_t id;

  public:
    PlayerID(std::string stringToHash = "Hello world") { id = std::hash<std::string>()(stringToHash); };
    inline bool operator==(const PlayerID& p) const noexcept { return id == p.id; };
    inline bool operator<(const PlayerID& p) const noexcept { return id < p.id; };
};

} // namespace Agent

#endif