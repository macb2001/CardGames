/*
Test file for Player class.
*/

#include <string>
#include "gtest/gtest.h"
#include "Player.h"
#include "PlayingCard.h"
#include "Pile.h"

TEST(TestPlayer, constructor) {
  //Test to make sure valid constructor parameters don't throw an error.
  EXPECT_NO_THROW(Player p1("human", true));
  EXPECT_NO_THROW(Player p1("non-human", false));
}

TEST(TestPlayer, drawCard) {
  // Create mini game setup to test card drawing
  Pile* drawPile = new Pile();
  PlayingCard* c = new PlayingCard(1, 's');
  drawPile -> addCard(c);
  Player* p = new Player("Al", false);

  // Check that there are no errors from trying to draw a card
  EXPECT_NO_THROW(p->drawCard(drawPile));

  // Check that player has the card now
  EXPECT_EQ(p->getHand()->getSize(), 1);
  EXPECT_EQ(p->getHand()->getCards()[0], c);

  // Delete all heap memory
  delete drawPile;
  delete p;
}

TEST(TestPlayer, drawCard2) {
  // Create deck to draw from
  Pile* drawPile = new Pile();

  // Create 5 cards for drawPile, deletion handled by Deck
  for (int i = 0; i < 5; i++) {
    drawPile -> addCard(new PlayingCard(i + 1, 's'));
  }

  // Make test player
  Player* p = new Player("Al", false);

  // Check that there are no errors from trying to draw a card
  EXPECT_NO_THROW(p->drawCard(drawPile, 5));

  // Check that player has the card now
  EXPECT_EQ(p->getHand()->getSize(), 5);

  // Delete all heap memory
  delete drawPile;
  delete p;
}

// No definition for this test, perhaps a relic?
//TEST(TestPlayer, DISABLED_placeCard) {}

// No need to write unit tests for getters
// TEST(TestPlayer, DISABLED_getHand) {}

TEST(TestPlayer, getNumOfCards) {
  // Create deck to draw from
  Pile* drawPile = new Pile();

  // Create 5 cards for drawPile, deletion handled by Deck
  for (int i = 0; i < 5; i++) {
    drawPile -> addCard(new PlayingCard(i + 1, 's'));
  }

  // Make test player
  Player* p = new Player("Al", false);

  // Put 5 cards in hand
  p->drawCard(drawPile, 5);

  // Check that player has the card now
  EXPECT_EQ(p->getNumOfCards(), 5);

  // Delete all heap memory
  delete drawPile;
  delete p;
}

TEST(TestPlayer, getName) {
  Player* p = new Player("john", false);

  EXPECT_EQ(p->getName(), "john");

  delete p;
}

TEST(TestPlayer, getIsHuman) {
  Player* p = new Player("john", false);

  EXPECT_EQ(p->getIsHuman(), false);

  delete p;
}
