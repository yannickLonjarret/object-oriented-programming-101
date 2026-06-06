#ifndef COMBINATION_H
#define COMBINATION_H

#include <numeric>
#include <vector>

#include "card.h"

using namespace Cards;

namespace Combination {

enum class Type { SUM = 100, SERIE = 200, COLOR = 300, KIND = 400, COLORED_SERIE = 500 };

Type computeCombinationType(const std::vector<ClanCard>& cards);

bool IsSerie(std::vector<ClanCard> cards);
bool IsColor(const std::vector<ClanCard>& cards);
bool IsKind(const std::vector<ClanCard>& cards);
bool IsColoredSerie(const std::vector<ClanCard>& cards);

class CardCombination {
  private:
    Type combinationType;
    int sumOfCards;

  public:
    CardCombination(Type type, int sum) : combinationType(type), sumOfCards(sum) {};

    CardCombination(const std::vector<ClanCard>& cards) {
        combinationType = computeCombinationType(cards);
        sumOfCards = std::accumulate(cards.begin(), cards.end(), 0, [](int sum, const ClanCard& c) { return sum + c.GetValue(); });
    }

    Type GetCombinationType() const { return combinationType; }

    void CombinationTypeConversion(const Type& convertTo);

    bool operator<(const CardCombination& cc) {
        if (combinationType == cc.combinationType) {
            return sumOfCards < cc.sumOfCards;
        }
        return combinationType == cc.combinationType;
    }

    bool operator==(const CardCombination& cc) { return (combinationType == cc.combinationType) && (sumOfCards == cc.sumOfCards); }

    ~CardCombination() = default;
};

} // namespace Combination

#endif