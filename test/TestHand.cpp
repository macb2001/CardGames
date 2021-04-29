/*
Test file for Hand class.
*/

#include "gtest/gtest.h"
#include "Hand.h"
#include "Pile.h"
#include "Exceptions.h"
#include "PlayingCard.h"
#include "UnoCard.h"

TEST(TestHand, constructor) {
  //Test to ensure contructor does not throw error
  EXPECT_NO_THROW(Hand h1);
}

TEST(TestHand, trueLessThan) {
  //Test to ensure Hand::lessThan() returns correct value.
  //Creating objects.
  PlayingCard *c1 = new PlayingCard(1, 'c');
  PlayingCard *c2 = new PlayingCard(2, 'c');
  PlayingCard *c3 = new PlayingCard(13, 's');
  PlayingCard *c4 = new PlayingCard(12, 's');
  PlayingCard *c5 = new PlayingCard(5, 'h');
  PlayingCard *c6 = new PlayingCard(8, 'd');

  UnoCard *c7 = new UnoCard(14, 'w');
  UnoCard *c8 = new UnoCard(13, 'w');
  UnoCard *c9 = new UnoCard(0, 'b');
  UnoCard *c10 = new UnoCard(1, 'b');
  UnoCard *c11 = new UnoCard(5, 'g');
  UnoCard *c12 = new UnoCard(8, 'r');
  UnoCard *c13 = new UnoCard(12, 'y');

  //Performing tests.
  EXPECT_TRUE(lessThan(c1, c2));
  EXPECT_TRUE(lessThan(c2, c3));
  EXPECT_TRUE(lessThan(c2, c4));
  EXPECT_TRUE(lessThan(c6, c5));
  EXPECT_TRUE(lessThan(c6, c3));

  EXPECT_TRUE(lessThan(c8, c7));
  EXPECT_TRUE(lessThan(c9, c10));
  EXPECT_TRUE(lessThan(c2, c7));
  EXPECT_TRUE(lessThan(c11, c12));
  EXPECT_TRUE(lessThan(c12, c13));

  //Deleting objects.
  delete c1;
  delete c2;
  delete c3;
  delete c4;
  delete c5;
  delete c6;
  delete c7;
  delete c8;
  delete c9;
  delete c10;
  delete c11;
  delete c12;
  delete c13;
}

TEST(TestHand, falseLesserThan) {
  //Test to ensure Hand::lesserThan() returns correct value.
  //Creating objects.
  PlayingCard *c1 = new PlayingCard(1, 'c');
  PlayingCard *c2 = new PlayingCard(2, 'c');
  PlayingCard *c3 = new PlayingCard(13, 's');
  PlayingCard *c4 = new PlayingCard(12, 's');
  PlayingCard *c5 = new PlayingCard(5, 'h');
  PlayingCard *c6 = new PlayingCard(8, 'd');

  UnoCard *c7 = new UnoCard(14, 'w');
  UnoCard *c8 = new UnoCard(13, 'w');
  UnoCard *c9 = new UnoCard(0, 'b');
  UnoCard *c10 = new UnoCard(1, 'b');
  UnoCard *c11 = new UnoCard(5, 'g');
  UnoCard *c12 = new UnoCard(8, 'r');
  UnoCard *c13 = new UnoCard(12, 'y');

  //Performing tests.
  EXPECT_FALSE(lessThan(c2, c1));
  EXPECT_FALSE(lessThan(c3, c2));
  EXPECT_FALSE(lessThan(c4, c2));
  EXPECT_FALSE(lessThan(c5, c6));
  EXPECT_FALSE(lessThan(c3, c6));

  EXPECT_FALSE(lessThan(c7, c8));
  EXPECT_FALSE(lessThan(c10, c9));
  EXPECT_FALSE(lessThan(c7, c9));
  EXPECT_FALSE(lessThan(c12, c11));
  EXPECT_FALSE(lessThan(c13, c12));

  //Deleting objects.
  delete c1;
  delete c2;
  delete c3;
  delete c4;
  delete c5;
  delete c6;
  delete c7;
  delete c8;
  delete c9;
  delete c10;
  delete c11;
  delete c12;
  delete c13;
}

TEST(TestHand, playingCardDisplayHand) {
  //Test to ensure displayHand() method functions properly for Playing cards.
  //Creating objects.
  Hand *h1 = new Hand;
  PlayingCard *c1 = new PlayingCard(1, 'c');
  PlayingCard *c2 = new PlayingCard(2, 'c');
  PlayingCard *c3 = new PlayingCard(13, 's');
  PlayingCard *c4 = new PlayingCard(11, 'h');

  //Adding Card, c2, to hand.
  h1 -> addCard(c2);

  //Performing test.
  EXPECT_EQ(h1 -> displayHand(), "|c2|");

  //Adding Card, c1, to hand.
  h1 -> addCard(c1);

  //Performing test.
  EXPECT_EQ(h1 -> displayHand(), "|ca|c2|");

  //Adding Card, c3, to hand.
  h1 -> addCard(c3);

  //Performing test.
  EXPECT_EQ(h1 -> displayHand(), "|ca|c2|sk|");

  //Removing Card, c2, from hand.
  h1 -> removeCard(c2);

  //Performing test.
  EXPECT_EQ(h1 -> displayHand(), "|ca|sk|");

  //Adding Card, c4, to hand.
  h1 -> addCard(c4);

  //Performing test.
  EXPECT_EQ(h1 -> displayHand(), "|ca|hj|sk|");

  //Deleting objects.
  delete h1;
  delete c2;
}

TEST(TestHand, unoCardDisplayHand) {
  //Test to ensure displayHand() method functions properly for Uno cards..
  //Creating objects.
  Hand *h1 = new Hand;
  UnoCard *c1 = new UnoCard(0, 'g');
  UnoCard *c2 = new UnoCard(1, 'g');
  UnoCard *c3 = new UnoCard(14, 'w');
  UnoCard *c4 = new UnoCard(11, 'b');

  //Adding Card, c2, to hand.
  h1 -> addCard(c2);

  //Performing test.
  EXPECT_EQ(h1 -> displayHand(), "|g1|");

  //Adding Card, c1, to hand.
  h1 -> addCard(c1);

  //Performing test.
  EXPECT_EQ(h1 -> displayHand(), "|g0|g1|");

  //Adding Card, c3, to hand.
  h1 -> addCard(c3);

  //Performing test.
  EXPECT_EQ(h1 -> displayHand(), "|g0|g1|wcc|");

  //Removing Card, c2, from hand.
  h1 -> removeCard(c2);

  //Performing test.
  EXPECT_EQ(h1 -> displayHand(), "|g0|wcc|");

  //Adding Card, c4, to hand.
  h1 -> addCard(c4);

  //Performing test.
  EXPECT_EQ(h1 -> displayHand(), "|br|g0|wcc|");

  //Deleting objects.
  delete h1;
  delete c2;
}

TEST(TestHand, findFace) {
  //Test to ensure findFace() method functions properly.
  //Creating objects.
  Hand *h1 = new Hand;
  PlayingCard *c1 = new PlayingCard(1, 'c');
  PlayingCard *c2 = new PlayingCard(5, 'h');
  PlayingCard *c3 = new PlayingCard(5, 'd');

  //Adding cards.
  h1 -> addCard(c1);
  h1 -> addCard(c2);
  h1 -> addCard(c3);

  //Performing test.
  EXPECT_EQ(h1 -> findFace(1), c1);
  EXPECT_EQ(h1 -> findFace(5), c2);

  //Removing a Card, c2, from the Hand.
  h1 -> removeCard(c2);

  //Performing test.
  EXPECT_EQ(h1 -> findFace(5), c3);
  EXPECT_EQ(h1 -> findFace(13), nullptr);

  //Deleting objects.
  delete h1;
  delete c2;
}

TEST(TestHand, findSuit) {
  //Test to ensure findSuit() method functions properly.
  //Creating objects.
  Hand *h1 = new Hand;
  PlayingCard *c1 = new PlayingCard(1, 'c');
  PlayingCard *c2 = new PlayingCard(5, 'h');
  PlayingCard *c3 = new PlayingCard(6, 'h');

  //Adding cards.
  h1 -> addCard(c1);
  h1 -> addCard(c2);
  h1 -> addCard(c3);

  //Performing test.
  EXPECT_EQ(h1 -> findSuit('c'), c1);
  EXPECT_EQ(h1 -> findSuit('h'), c2);

  //Removing a Card, c2, from the Hand.
  h1 -> removeCard(c2);

  //Performing test.
  EXPECT_EQ(h1 -> findSuit('h'), c3);
  EXPECT_EQ(h1 -> findSuit('d'), nullptr);

  //Deleting objects.
  delete h1;
  delete c2;
}

TEST(TestHand, placeCard) {
  //Test to ensure placeCard() method functions properly.
  //Creating objects.
  Hand *h1 = new Hand;
  Pile *p1 = new Pile;
  PlayingCard *c1 = new PlayingCard(1, 'c');

  //Adding card to hand.
  h1 -> addCard(c1);

  int handSize = h1 -> getSize();
  int pileSize = p1 -> getSize();

  //Placing Card, c1, on Pile, p1.
  h1 -> placeCard(p1, c1);

  //Test to check that Card, c1, is on Pile, p1;
  EXPECT_EQ(p1 -> getTopCard(), c1);

  //Test to ensure Hand, h1, is 1 less in size.
  EXPECT_EQ(h1 -> getSize(), handSize - 1);

  //Test to ensure Pile, p1, is 1 more in size.
  EXPECT_EQ(p1 -> getSize(), pileSize + 1);

  delete h1;
  delete p1;
}

TEST(TestHand, invalidPlaceCard) {
  /*Test to ensure placeCard() method throws error if Card parameter is not in
  hand or if hand is empty.*/
  //Creating objects.
  Hand *h1 = new Hand;
  Pile *p1 = new Pile;
  PlayingCard *c1 = new PlayingCard(1, 'c');
  PlayingCard *c2 = new PlayingCard(1, 'd');

  //Test to ensure error is thrown if attempting to place card if hand is empty.
  EXPECT_THROW(h1 -> placeCard(p1, c1), invalid_deck_operation);

  //Adding card to hand.
  h1 -> addCard(c1);

  //Test to ensure error is thrown if Card parameter is not in hand.
  EXPECT_THROW(h1 -> placeCard(p1, c2), invalid_deck_operation);

  //Deleting objects.
  delete h1;
  delete p1;
  delete c2;
}

TEST(TestHand, findCard) {
  //Test to ensure findCard() method functions properly.
  //Creating object.
  Hand *h1 = new Hand;
  PlayingCard *c1 = new PlayingCard(1, 'c');
  PlayingCard *c2 = new PlayingCard(5, 'h');
  PlayingCard *c3 = new PlayingCard(1, 'h');

  //Adding cards to hand.
  h1 -> addCard(c1);
  h1 -> addCard(c2);
  h1 -> addCard(c3);

  //Performing test.
  EXPECT_EQ(h1 -> findCard(1, 'c'), c1);
  EXPECT_EQ(h1 -> findCard(5, 'h'), c2);
  EXPECT_EQ(h1 -> findCard(1, 'h'), c3);
  EXPECT_EQ(h1 -> findCard(1, 'd'), nullptr);
  EXPECT_EQ(h1 -> findCard(6, 'h'), nullptr);

  //Deleting objects.
  delete h1;
}

TEST(TestHand, getRandomCard) {
  //Test to ensure getRandomCard() does not throw error.
  //Creating objects
  Hand* h1 = new Hand;

  //Adding cards to hand.
  h1 -> addCard(new PlayingCard(12, 'h'));
  h1 -> addCard(new PlayingCard(5, 's'));

  //Performing Test.
  EXPECT_NO_THROW(h1 -> getRandomCard());

  //Deleting objects.
  delete h1;
}

TEST(TestHand, invalidGetRandomCard) {
  //Test to ensure getRandomCard() throws error if hand is empty.
  Hand *h1 = new Hand;

  //Performing test.
  EXPECT_THROW(h1 -> getRandomCard(), invalid_deck_operation);

  //Deleting object.
  delete h1;
}
