#ifndef UNO_H
#define UNO_H

#include <string>
#include "Game.h"
#include "Pile.h"
#include "UnoPlayer.h"
#include "Crazy8.h"

class Uno : public Crazy8 {
 public:
	 Uno() :Crazy8() {}
  /**
  * Runs the game Uno.
  */
  void run();
  /**
  * Runs one round of Uno
  */
  void round();
  /**
  * @param p for the player who is taking the their turn
  * Runs the UI logic for a human player's turn
  */
  void takeTurn(Player *p);
  /**
  * @param p for the player who is taking the their turn
  * Runs the CPU logic for a computer player's turn
  */
  void CPUTurn(Player* p);
  /**
  * Handles input logic from the user
  * @param p the human player whose turn it is
  */
  void humanTurn(Player* p);
  /**
  * Sets the card piles for Uno
  */
  void createPiles();
  /**
  * Prints the help method for Uno
  */
  void help();
  /**
  * Converts pickup, reverse, and skip cards from string representation to int
  * @param s A face value of a special card
  * @return int representation of face value s
  */
  int returnCardRank(std::string s);
  /**
  * Handles the UI for a player picking up a card from the pile
  * @param p the player who is drawing cards
  */
  void drawCards(Player* p);
  /**
  * Changes the direction of turn orders
  */
  void swapTurnOrder();
  /**
  * @return the current colour
  */
  char getCurrentColour();
  /**
  * Sets the valid colour for which players can lay cards on discardPile
  */
  void setCurrentColour(char c);
  /**
  * @param c The card a player wishes to lay on discardPile
  * @return True if placing c is permitted. Else, return false.
  */
  bool isPlayable(Card* c);
  /**
  * Lays a Card onto discardPile. Handles implications of special Cards.
  * @param c The Card to be laid
  * @param p The Player who is laying the card
  */
  void playCard(Card* c, Player* p);
  /**
  * Handles changing currentColour when the appropriate Card is laid
  * @param p The player who laid the colour-changing Card
  */
  void changeColour(Player *p);
  /**
  * @return an int representation of how many consecutive pickup
  cards have been laid
  */
  int getStackTally();
  /**
  * Sets the int representation of how many consecutive pickup
  cards have been laid
  * @param n The int we want stackTally to be set to
  */
  void setStackTally(int n);
  /**
  * Forces the player to drawn all the cards tallied up.
  * @param p the player who has to draw the cards
  */
  void forcedPickup(Player* p);

 protected:
  char currentColour = 'b';
  int stackTally = 0;
};

#endif // GAME
