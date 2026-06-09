#ifndef COMBINATION_H
#define COMBINATION_H

#include <numeric>
#include <vector>

#include "card.h"

using namespace Cards;

namespace Combination {

enum class Type { SUM = 100, SERIE = 200, COLOR = 300, KIND = 400, COLORED_SERIE = 500 };

Type computeCombinationType(const std::vector<ClanCard>& cards);

bool isSerie(std::vector<ClanCard> cards);
bool isColor(const std::vector<ClanCard>& cards);
bool isKind(const std::vector<ClanCard>& cards);
bool isColoredSerie(const std::vector<ClanCard>& cards);

class CardCombination {
  private:
    Type combinationType;
    int sumOfCards;

  public:
    CardCombination(Type type, int sum) : combinationType(type), sumOfCards(sum) {};

    CardCombination(const std::vector<ClanCard>& cards) {
        combinationType = computeCombinationType(cards);
        sumOfCards = std::accumulate(cards.begin(), cards.end(), 0, [](int sum, const ClanCard& c) { return sum + c.getValue(); });
    }

    Type getCombinationType() const { return combinationType; }

    bool operator<(const CardCombination& cc) const {
        if (combinationType == cc.combinationType) {
            return sumOfCards < cc.sumOfCards;
        }
        return combinationType < cc.combinationType;
    }

    bool operator==(const CardCombination& cc) const { return (combinationType == cc.combinationType) && (sumOfCards == cc.sumOfCards); }

    ~CardCombination() = default;
};

} // namespace Combination

#endif