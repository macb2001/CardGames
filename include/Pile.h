#ifndef PILE_H
#define PILE_H

#include "Deck.h"
#include <string>

class Pile : public Deck {
 public:
  /**
  * @return the top card from deck
  */
  Card* getTopCard();
  /**
  * Shuffles this deck
  */
  void shuffle();
};

#endif // PILE_H
