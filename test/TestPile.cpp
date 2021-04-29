/*
Test file for Pile class.
*/

#include "gtest/gtest.h"
#include "Pile.h"
#include "Exceptions.h"
#include "PlayingCard.h"

TEST(TestPile, constructor) {
  //Test to ensure constructor does not throw error.
  EXPECT_NO_THROW(Pile p1);
}

TEST(TestPile, getTopCard) {
  //Test to ensure getTopCard() method functions properly.
  //Creating objects.
  Pile *p1 = new Pile;
  PlayingCard *c1 = new PlayingCard(1, 'c');
  PlayingCard *c2 = new PlayingCard(1, 'd');

  //Adding Card c1 to pile.
  p1 -> addCard(c1);

  //Performing test
  EXPECT_EQ(p1 -> getTopCard(), c1);

  //Adding Card c2 to pile.
  p1 -> addCard(c2);

  //Performing test
  EXPECT_EQ(p1 -> getTopCard(), c2);

  //Removing Card c2 from pile.
  p1 -> removeCard(c2);

  //Performing test
  EXPECT_EQ(p1 -> getTopCard(), c1);

  //Deleting objects
  delete p1;
  delete c2;
}

TEST(TestPile, invalidGetTopCard) {
  //Test to ensure getTopCard() method throws error for empty pile.
  //Creating object.
  Pile *p1 = new Pile;

  //Performing test
  EXPECT_THROW(p1 -> getTopCard(), invalid_deck_operation);

  //Deleting object.
  delete p1;
}

TEST(TestPile, shuffle) {
  //Test to ensure shuffle does not throw error.
  //Creating objects.
  Pile* p1 = new Pile;
  Card *c1 = new PlayingCard(13, 'h');
  Card *c2 = new PlayingCard(5, 's');

  //Adding cards to pile.
  p1 -> addCard(c1);
  p1 -> addCard(c2);

  //Performing test.
  EXPECT_NO_THROW(p1 -> shuffle());

  //Deleting objects.
  delete p1;
}
