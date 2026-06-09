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
    int getValue() const { return value; }
    CardColors getColor() const { return color; }
};
} // namespace Cards

#endif