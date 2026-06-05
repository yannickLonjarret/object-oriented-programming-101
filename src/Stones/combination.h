#ifndef COMBINATION_H
#define COMBINATION_H

#include <vector>

#include "card.h"

namespace Combination {

enum class Type { SUM = 100, SERIE = 200, COLOR = 300, KIND = 400, COLORED_SERIE = 500 };

Type computeCombinationType(const std::vector<Card>& cards);

class CardCombination {
  private:
    Type combinationType;
    int sumOfCards;

  public:
    CardCombination(Type type, int sum) : combinationType(type), sumOfCards(sum) {};

    ~CardCombination() = default;
};

} // namespace Combination

#endif