#ifndef CARD_H
#define CARD_H

#include <string>
#include "Exceptions.h"

class Card {
 public:
  Card(int face, char suit);
  ~Card() {}
  /**
  * @return The char representing suit
  */
  char getSuit() const;
  /**
  * @return The int representing face
  */
  int getFace() const;
  /**
  * @return The suit of the card
  */
  virtual std::string getSuitStr() = 0;
  /**
  * @return The face of the card as a word not number
  */
  virtual std::string getFaceStr() = 0;
  /**
  * @return The suit and face of the card as a single string
  */
  virtual std::string getName() = 0;
  /**
  * @return A minimalist representation of the card contents
  */
  virtual std::string getSimpleName() = 0;
  /**
  * @param c the card which is being checked against
  * @return whether or not the cards match according to game rules
  */
  virtual bool matches(Card* c) = 0;

 protected:
  const int face;
  const char suit;
};

#endif // CARD_H
