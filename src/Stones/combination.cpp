#include "combination.h"

#include <algorithm>

namespace Combination {
Type computeCombinationType(const std::vector<ClanCard>& cards) {
    if (isColoredSerie(cards)) {
        return Type::COLORED_SERIE;
    } else if (isKind(cards)) {
        return Type::KIND;
    } else if (isColor(cards)) {
        return Type::COLOR;
    } else if (isSerie(cards)) {
        return Type::SERIE;
    } else {
        return Type::SUM;
    }
}

bool isSerie(std::vector<ClanCard> cards) {
    if (cards.empty()) {
        return false;
    }

    std::sort(cards.begin(), cards.end(), [](const ClanCard& c1, const ClanCard& c2) { return c1.getValue() < c2.getValue(); });
    for (auto it = std::next(cards.cbegin()); it != cards.cend(); ++it) {
        if (it->getValue() - std::prev(it)->getValue() != 1) {
            return false;
        }
    }

    return true;
}

bool isColor(const std::vector<ClanCard>& cards) {
    if (cards.empty()) {
        return false;
    }
    const Cards::CardColors referenceColor = cards.front().getColor();
    auto colorPredicate = [referenceColor](const ClanCard& c) { return c.getColor() == referenceColor; };
    return std::all_of(cards.begin(), cards.end(), colorPredicate);
}

bool isKind(const std::vector<ClanCard>& cards) {
    if (cards.empty()) {
        return false;
    }
    const int referenceValue = cards.front().getValue();
    auto kindPredicate = [referenceValue](const ClanCard& c) { return c.getValue() == referenceValue; };
    return std::all_of(cards.begin(), cards.end(), kindPredicate);
}

bool isColoredSerie(const std::vector<ClanCard>& cards) { return isSerie(cards) && isColor(cards); }

void CardCombination::combinationTypeConversion(const Type& convertTo) {}
} // namespace Combination
