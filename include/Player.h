#ifndef PLAYER_H
#define PLAYER_H

#include "Deck.h"
#include "Pile.h"
#include "Hand.h"
#include <string>

class Player {
 public:
  Player(std::string name, bool isHuman);
  virtual ~Player();

  /**
  * @param d is the deck which we take the card
  */
  void drawCard(Pile* d);
  /**
  * @param d is the deck which we take the card
  * @param numb is number of cards to draw
  */
  void drawCard(Pile* d, int numb);
  /**
  * @return gets hand
  */
  Hand* getHand();
  /**
  * @return the total number of cards from the players hand
  */
  int getNumOfCards();
  /**
  * @return the suit and face of a card as name of card
  */
  std::string getName();
  /**
  * @return isHuman
  */
  bool getIsHuman();

 protected:
  Hand* hand;
  bool isHuman;
  std::string name;
};

#endif // PLAYER_H
