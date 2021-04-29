#ifndef CRAZY8CARD_H
#define CRAZY8CARD_H

#include "PlayingCard.h"

class Crazy8Card : public PlayingCard {
 public:
  /**
  * @param face The card face represented by a number
  * @param suit The card suit represented by the first
  * character of the suit name.
  */
  Crazy8Card(int face, char suit): PlayingCard(face, suit) {}

  /**
  * @param soreCard the card which is being checked against
  * @return whether or not the cards match according to crazy 8 rules
  */
  bool matches(Card* c);
};

#endif // CRAZY8CARD_H
