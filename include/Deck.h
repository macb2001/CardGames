#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>

class Deck {
 public:
  virtual ~Deck();
  /**
  * @param c The card we want to add to the deck
  */
  void addCard(Card* c);
  /**
  * @param c The card we want to remove from the deck
  * @throw invalid_deck_operation if Card c is not in this Deck
  */
  void removeCard(Card* c);
  /**
  * @param d The deck from which we wish to take a card
  * @param c The card we wish to take from Deck d
  * @throw invalid_deck_operation if Card c is not in this Deck
  */
  void takeCard(Deck* d, Card* c);
  /**
  * @return the size of the Deck
  * @throw invalid_deck_operation if Card c is not in Deck d
  */
  int getSize();
  /**
  * @return This Deck's cards attribute
  */
  std::vector<Card*> getCards();
  /**
  * @return true if there are no cards in this Deck. Else,
  * return false
  */
  bool isEmpty();

 protected:
  std::vector<Card*> cards;
};

#endif // DECK_H
