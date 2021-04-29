#ifndef GOFISHPLAYER_H
#define GOFISHPLAYER_H

#include "Card.h"
#include "Player.h"
#include "Pile.h"
#include <string>

class GoFishPlayer : public Player {
 public:
  /**
  * @param name the player identifyer name
  * @param isHuman whether or not it is CPU or human
  */
  GoFishPlayer(std::string name, bool isHuman) : Player(name, isHuman) {}
  /**
  * @return the number of pairs the player has collected
  */
  int getPairs();
  /**
  * @param face to make pairs from
  * @return true if pair is successfully made
  */
  bool makePair(int face, Pile* discardPile);
  /**
  * Make all the available pairs in hand
  */
  void makeAllPairs(Pile* discardPile);
  /**
  * @param face of the card we wish to check
  * @return true if has face else false
  */
  bool hasCard(int face);

 private:
  int pairs = 0;
};

#endif // GOFISHPLAYER_H
