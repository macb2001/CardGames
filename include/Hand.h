#ifndef HAND_H
#define HAND_H

#include <string>
#include "Deck.h"
#include "Pile.h"

class Hand : public Deck {
 public:
  /**
  * @param a the card which is being checked against card b
  * @param b the card which is being checked against card a
  * @return whether or not card a is less than b
  */
//  bool lessThan(Card* a, Card* b);
  /**
  * Written string of simple card names between |'s
  * @return a representation of the hand in the form of a string
  */
  std::string displayHand();
  /**
  * @param face The desired face of any card in Hand
  * @throw invalid_deck_operation if hand is empty
  * @return A card with the desired face if it exists. If such
  * a card doesn't exist, return a null pointer
  */
  Card* findFace(int face);
  /**
  * @param suit The desired suit of any card in Hand
  * @throw invalid_deck_operation if hand is empty
  * @return A card with the desired suit if it exists. If such
  * a card doesn't exist, return a null pointer
  */
  Card* findSuit(char suit);
  /**
  * @throw invalid_deck_operation if hand is empty
  * @return A random card from Hand
  */
  Card* getRandomCard();
  /**
  * @param face The face of the card we want to find in Hand
  * @param suit The suit of the card we want to find in Hand
  * @throw invalid_deck_operation if hand is empty
  * @return The card with the matching face and suit. If such
  * a card doesn't exist, return a null pointer
  */
  Card* findCard(int face, char suit);
  /**
  * @param p The pile we wish to place the card on
  * @param c The card we wish to place on p
  * @throw invalid_deck_operation if c is not in this hand
  * @throw invalid_deck_operation if hand is empty
  */
  void placeCard(Pile* p, Card* c);
  /**
  * @throw invalid_deck_operation if there are no cards in hand.
  */
  void checkEmptyHand();
};

/**
* Helper function for comparing card values
* @param a LHS card
* @param b RHS card
* @return true if a < b (by our defined hierarchy). Else, return false.
*/
bool lessThan(Card* a, Card* b);

#endif // HAND_H
