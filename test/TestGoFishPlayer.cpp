/*
Test file for GoFishPlayer class.
*/

#include <string>
#include "gtest/gtest.h"
#include "GoFishPlayer.h"
#include "PlayingCard.h"
#include "Pile.h"

TEST(TestGoFishPlayer, getPairs) {
  Pile* discardPile = new Pile;
  GoFishPlayer* p = new GoFishPlayer("Al", false);

  p->getHand()->addCard(new PlayingCard(1, 's'));
  p->getHand()->addCard(new PlayingCard(1, 'c'));
  p->getHand()->addCard(new PlayingCard(1, 'h'));
  p->getHand()->addCard(new PlayingCard(1, 'd'));

  EXPECT_EQ(p->getPairs(), 0);
  p->makePair(1, discardPile);
  EXPECT_EQ(p->getPairs(), 1);
  p->makePair(1, discardPile);
  EXPECT_EQ(p->getPairs(), 2);

  delete p;
  delete discardPile;
}

TEST(TestGoFishPlayer, makePairs) {
  // Create deck to draw from
  Pile* drawPile = new Pile();

  // Create 5 cards for drawPile, deletion handled by Decks
  drawPile->addCard(new PlayingCard(1, 's'));
  drawPile->addCard(new PlayingCard(1, 's'));
  drawPile->addCard(new PlayingCard(2, 's'));
  drawPile->addCard(new PlayingCard(2, 's'));
  drawPile->addCard(new PlayingCard(3, 's'));

  // Make test player and fill it with cards
  GoFishPlayer* p = new GoFishPlayer("Al", false);
  p->drawCard(drawPile, 5);

  // Test body, check for working pair finding
  EXPECT_EQ(p->makePair(1, drawPile), true);
  EXPECT_EQ(p->makePair(2, drawPile), true);
  EXPECT_EQ(p->makePair(3, drawPile), false);
  EXPECT_EQ(p->makePair(4, drawPile), false);

  // Delete all heap memory
  delete drawPile;
  delete p;
}

TEST(TestGoFishPlayer, DISABLED_test) {}

TEST(TestGoFishPlayer, DISABLED_getScore) {}
