#ifndef PLAYINGCARD_H
#define PLAYINGCARD_H

#include <string>
#include "Card.h"

const int MAX_NUM_SUITS = 4;
const int MAX_NUM_RANKS = 13;

class PlayingCard : public Card {
 public:
  /**
  * @throw illegal_card_error if rank is is less than 1 or more than 13 or if
  * suit isn't c, d, h, or s.
  * @param face The card face represented by a number
  * @param suit The card suit represented by the first
  * character of the suit name.
  */
  PlayingCard(int face, char suit);

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
  * A quick hack to allow for the creation of concrete PlayingCards
  * @return true always
  */
  virtual bool matches(Card* c) {
    return true;
  }
};

#endif // PLAYINGCARD_H
