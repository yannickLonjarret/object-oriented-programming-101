#ifndef CARD_H
#define CARD_H

namespace Cards {
enum class CardColors { EMPTY, GREEN, BLUE, RED, YELLOW, PURPLE, BROWN };

class Card {};

class ClanCard : public Card {
  private:
    int value;
    CardColors color;

  public:
    ClanCard(int v = -1, CardColors c = CardColors::EMPTY) : value(v), color(c) {};

    inline int getValue() const noexcept { return value; }
    inline CardColors getColor() const noexcept { return color; }

    inline bool operator==(const ClanCard& c) const { return color == c.color && value == c.value; };
};
} // namespace Cards

#endif