#ifndef PLAYERID_H
#define PLAYERID_H

namespace Agent {

class PlayerID {
  private:
    size_t id;

  public:
    bool operator==(const PlayerID& p) const = default;
};

} // namespace Agent

#endif