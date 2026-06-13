#ifndef STONE_H
#define STONE_H

#include "combination.h"

namespace Stone {

class Stone {
  private:
    std::vector<Combination::Type> eligibleCombination;
};
} // namespace Stone

#endif