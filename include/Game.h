#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Pile.h"
#include <string>
#include <vector>

class Game {
 public:
	Game() {}
  virtual ~Game();
  /**
  * Runs an instance of given game and handles initializations.
  */
  virtual void run() = 0;
  /**
  * Runs one round of this Game, as in until scores are aquired
  */
  virtual void round() = 0;
  /**
  * Runs one turn for a given player of this Game
  * @param p The player that is taking a turn
  */
  virtual void takeTurn(Player* p) = 0;
  /**
  * Sets the number of players for this Game
  * Initiallizes players
  * @param p the number of players
  */
  virtual void setPlayerNum(int p) = 0;
  /**
  * Changes turn number to the next expected turn
  */
  void nextTurn();
  /**
  * @return The number of players in this Game
  */
  int getNumOfPlayers();
  /**
  * @return A random player that isn't taking their turn
  */
  Player* getRandPlayer();
  /**
  * @return The draw pile of this Game
  */
  Pile* getDrawPile();
  /**
  * @return The discard pile of this Game
  */
  Pile* getDiscardPile();
  /**
  * @return The current turn
  */
  std::vector<Player*> getPlayers();
  int getTurn();
  std::string displayPlayers();
  void deal(int n);

 protected:
  Pile* drawPile = nullptr;
  Pile* discardPile = nullptr;
  bool reversedTurnOrder = false;
  std::vector<Player*> players;
  int turn = 0;
  bool isWinner = false;
};

#endif // GAME_H
