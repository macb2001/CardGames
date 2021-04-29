#ifndef GOFISHCARD_H
#define GOFISHCARD_H

#include "PlayingCard.h"

class GoFishCard : public PlayingCard {
 public:
  /**
  * @param face The card face represented by a number
  * @param suit The card suit represented by the first
  * character of the suit name.
  */
  GoFishCard(int face, char suit): PlayingCard(face, suit) {}

  /**
  * @param c The card which is being checked against
  * @return Whether or not the cards match according GoFish rules
  */
  bool matches(Card* c);
};

#endif // GOFISHCARD_H
