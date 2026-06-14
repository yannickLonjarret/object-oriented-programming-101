#ifndef PLAYERID_H
#define PLAYERID_H

namespace Agent {

class PlayerID {
  private:
    size_t id;

  public:
    PlayerID(size_t givenId = 0) : id(givenId) {};
    inline bool operator==(const PlayerID& p) const noexcept = default;
};

} // namespace Agent

#endif