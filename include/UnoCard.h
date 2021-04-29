#ifndef UNOCARD_H
#define UNOCARD_H

#include <string>
#include "Card.h"

class UnoCard : public Card {
 public:
  /**
  * @throw illegal_card_error if suit isn't b, g, r, w, or y or if rank is less
  * than 0 or more than 14.
  * @param face The card face represented by a number
  * @param suit The card suit represented by the first
  * character of the suit name.
  */
  UnoCard(int face, char suit);
  /**
  * @return The suit of the card
  */
  std::string getSuitStr();
  /**
  * @return The face of the card
  */
  std::string getFaceStr();
  /**
  * @return The suit and face of the card as a single string
  */
  std::string getName();
  /**
  * @return A minimalist representation of the card contents
  */
  std::string getSimpleName();
  /**
  * @param soreCard the card which is being checked against
  * @return whether or not the cards match according to uno rules
  */
  bool matches(Card* c);
};

#endif // UNOCARD_H
