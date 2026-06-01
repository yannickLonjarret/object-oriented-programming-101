#ifndef CARD_H
#define CARD_H

enum class CardColors { EMPTY, GREEN, BLUE, RED, YELLOW, PURPLE, BROWN };

class Card {
  private:
    const int value;
    const CardColors color;
};

#endif