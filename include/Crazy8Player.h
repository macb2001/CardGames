#ifndef CRAZY8PLAYER_H
#define CRAZY8PLAYER_H

#include <string>
#include "Player.h"

class Crazy8Player : public Player {
 public:
  Crazy8Player(std::string name, bool isHuman) : Player(name, isHuman) {}
};

#endif
