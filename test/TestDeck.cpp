/*
Test file for Deck class.
*/

#include "gtest/gtest.h"
#include "Deck.h"
#include "PlayingCard.h"
#include "Exceptions.h"
#include "Hand.h"

TEST(TestDeck, constructor) {
  //Test to ensure constructor does not throw error.
  EXPECT_NO_THROW(Deck d1);
}

TEST(TestDeck, addCard) {
  //Test to ensure addCard() method functions properly.
  //Creating objects.
  Deck *d1 = new Deck;
  PlayingCard *c1 = new PlayingCard(1, 'c');

  int size = d1 -> getSize();

  //Performing test.
  EXPECT_NO_THROW(d1 -> addCard(c1));
  EXPECT_EQ(d1 -> getSize(), size + 1);

  //Deleting objects.
  delete d1;
}

TEST(TestDeck, removeCard) {
  //Test to ensure removeCard() method functions properly.
  //Creating objects.
  Deck *d1 = new Deck;
  PlayingCard *c1 = new PlayingCard(1, 'c');
  PlayingCard *c2 = new PlayingCard(1, 'd');

  //Adding cards to the deck.
  d1 -> addCard(c1);
  d1 -> addCard(c2);

  int size = d1 -> getSize();

  //Performing tests
  EXPECT_NO_THROW(d1 -> removeCard(c1));
  EXPECT_EQ(d1 -> getSize(), size - 1);
  size = d1 -> getSize();

  EXPECT_NO_THROW(d1 -> removeCard(c2));
  EXPECT_EQ(d1 -> getSize(), size - 1);

  //Deleting objects.
  delete d1;
  delete c1;
  delete c2;
}

TEST(TestDeck, invalidRemoveCard) {
  //Test to ensure removeCard() throws error for invalid/non-existent Card;
  //Creating objects.
  Deck *d1 = new Deck;
  PlayingCard *c1 = new PlayingCard(1, 'c');
  PlayingCard *c2 = new PlayingCard(2, 'c');
  PlayingCard *c3 = new PlayingCard(1, 'h');
  PlayingCard *c4 = new PlayingCard(2, 'h');

  //Test to ensure error is thrown when removing card from empty deck.
  EXPECT_THROW(d1 -> removeCard(c1), invalid_deck_operation);

  //Adding card to the deck.
  d1 -> addCard(c1);

  //Performing test.
  EXPECT_THROW(d1 -> removeCard(c2), invalid_deck_operation);
  EXPECT_THROW(d1 -> removeCard(c3), invalid_deck_operation);
  EXPECT_THROW(d1 -> removeCard(c4), invalid_deck_operation);

  //Deleting objects.
  delete d1;
  delete c2;
  delete c3;
  delete c4;
}

TEST(TestDeck, takeCard) {
  //Test to ensure takeCard() method functions properly.
  //Creating objects.
  Deck *d1 = new Deck;
  Deck *d2 = new Deck;
  PlayingCard *c1 = new PlayingCard(1, 'c');

  //Adding card to Deck d1.
  d1 -> addCard(c1);

  int d1Size = d1 -> getSize();
  int d2Size = d2 -> getSize();

  //Performing test.
  EXPECT_NO_THROW(d2 -> takeCard(d1, c1));
  EXPECT_EQ(d1 -> getSize(), d1Size - 1);
  EXPECT_EQ(d2 -> getSize(), d2Size + 1);

  //Deleting objects.
  delete d1;
  delete d2;
}

TEST(TestDeck, invalidTakeCard) {
  //Test to ensure takeCard() method throws error for invalid/non-existent card.
  //Creating objects.
  Deck *d1 = new Deck;
  Deck *d2 = new Deck;
  PlayingCard *c1 = new PlayingCard(1, 'c');
  PlayingCard *c2 = new PlayingCard(2, 'c');
  PlayingCard *c3 = new PlayingCard(1, 'h');
  PlayingCard *c4 = new PlayingCard(2, 'h');


  //Test to ensure error is thrown when attempting take card from empty deck.
  EXPECT_THROW(d1 -> takeCard(d2, c1), invalid_deck_operation);

  //Adding card to the deck.
  d1 -> addCard(c1);

  //Performing test.
  EXPECT_THROW(d1 -> takeCard(d2, c2), invalid_deck_operation);
  EXPECT_THROW(d1 -> takeCard(d2, c3), invalid_deck_operation);
  EXPECT_THROW(d1 -> takeCard(d2, c4), invalid_deck_operation);

  //Deleting objects.
  delete d1;
  delete d2;
  delete c2;
  delete c3;
  delete c4;
}

TEST(TestDeck, getSize) {
  //Test to ensure getSize() method returns correct value.
  //Creating objects.
  Deck *d1 = new Deck;
  PlayingCard *c1 = new PlayingCard(1, 'c');
  PlayingCard *c2 = new PlayingCard(1, 'd');

  //Adding card to the deck.
  d1 -> addCard(c1);

  //Performing test.
  EXPECT_EQ(d1 -> getSize(), 1);

  //Adding another card.
  d1 -> addCard(c2);

  //Performing test.
  EXPECT_EQ(d1 -> getSize(), 2);

  //Removing card from the deck.
  d1 -> removeCard(c1);

  //Performing test.
  EXPECT_EQ(d1 -> getSize(), 1);

  //Removing another card.
  d1 -> removeCard(c2);

  //Performing test.
  EXPECT_EQ(d1 -> getSize(), 0);

  //Deleting objects.
  delete d1;
  delete c1;
  delete c2;
}
