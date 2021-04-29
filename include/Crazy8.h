#ifndef CRAZY8_H
#define CRAZY8_H

#include <string>
#include "Game.h"
#include "Pile.h"
#include "Crazy8Player.h"

class Crazy8 : public Game {
 public:
	 Crazy8() :Game() {}
  /**
  * Runs the game Crazy 8's
  */
  void run();
  /**
  * Runs one round of Crazy 8's
  */
  void round();
  /**
  * @param p for the player who is taking the their turn
  * runs the turn for each individual player at a time
  */
  void takeTurn(Player *p);
  /**
  * Sets the number of players for this Game
  * Initiallizes players
  * @param p the number of players
  */
  void setPlayerNum(int p);
  /**
  * Simulates a players turn as a CPU player
  * @param p the computer player whose turn it is
  */
  void CPUTurn(Player* p);
  /**
  * Handles input logic from the user
  * @param p the human player whose turn it is
  */
  void humanTurn(Player* p);
  /**
  * Runs the card-drawing process for a player who can't play
  a card from their Hand
  * @param p The player whose turn it is
  */
  void drawCards(Player* p);
  /**
  * Initializes drawPile and discardPile. Shuffles drawPile.
  */
  void createPiles();
  /**
  * Deals some fixed amount of cards to each player in this Game
  * @param numOfCards The number of cards to be dealt to each player
  */
  void deal(int numOfCards);
  /**
  * Outputs the help text for the user
  */
  void help();
  /**
  * Converts royal cards from string representation to int
  * @param s A face value of a royal card
  * @return int representation of face value s
  */
  int returnCardRank(std::string s);
  /**
  * To be used when this Game's drawPile is expended. Takes
    fashions a new drawPile from the cards in discardPile
  */
  void recyclePiles();
};

#endif // GAME
