#ifndef COMBINATION_H
#define COMBINATION_H

namespace Combination {

enum class Type { SUM = 100, SERIE = 200, COLOR = 300, KIND = 400, COLORED_SERIE = 500 };

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