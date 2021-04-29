#ifndef GOFISH_H
#define GOFISH_H

#include "Player.h"
#include "Game.h"
#include "Pile.h"

class GoFish : public Game {
 public:
	 GoFish() :Game() {}
  /**
  * Runs the game goFish
  */
  void run();
  /**
  * Handles game setup, players, piles, ect
  */
  void initialize();
  /**
  * Runs one round of goFish
  */
  void round();
  /**
  * @param p for the player who is taking the their turn
  * runs the turn for each individual player at a time
  */
  void takeTurn(Player* p);
  /**
  * Sets the number of players for this Game
  * Initiallizes players
  * @param p the number of players
  */
  void setPlayerNum(int p);
  /**
  * Outputs the help text for the user
  */
  void help();
  /**
  * Handles input logic from the user
  * @param p the human player who's turn it is
  */
  void playerInput(Player* p);
  /**
  * Simulates a players turn as a CPU player
  * @param p the computer player who's turn it is
  */
  void cpuInput(Player* p);
};

#endif // GAME
