#ifndef UNOPLAYER_H
#define UNOPLAYER_H

#include <string>
#include "Card.h"
#include "Player.h"
#include "Pile.h"

class UnoPlayer : public Player {
 public:
  /**
  * @param name the player identifyer name
  * @param isHuman whether or not it is CPU or human
  */
  UnoPlayer(std::string name, bool isHuman) : Player(name, isHuman) {}
  /**
  * @return this UnoPlayer's saidUNO attribute
  */
  bool getSaidUNO();
  /**
  * Setter for this UnoPlayer's saidUNO attribute
  * @param b The truth value for which we will set this UnoPlayer's
  saidUNO attribute
  */
  void setSaidUNO(bool b);

 protected:
  bool saidUNO = false;
};

#endif
