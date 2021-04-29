/*
Test file for PlayingCard class.
*/

#include "gtest/gtest.h"
#include "PlayingCard.h"
#include "Exceptions.h"

TEST(TestPlayingCard, constructor) {
  //Tests to ensure error is not thrown for valid constructor parameters.
  EXPECT_NO_THROW(PlayingCard c1(1, 'c'));
  EXPECT_NO_THROW(PlayingCard c2(13, 'h'));
  EXPECT_NO_THROW(PlayingCard c3(5, 'd'));
  EXPECT_NO_THROW(PlayingCard c4(8, 's'));
}

TEST(TestPlayingCard, invalidConstructor) {
  //Tests to ensure errors are thrown for invalid constructor parameters.

  EXPECT_THROW(PlayingCard c1(0, 'c'), illegal_card_error);
  EXPECT_THROW(PlayingCard c2(14, 'h'), illegal_card_error);
  EXPECT_THROW(PlayingCard c3(8, 'm'), illegal_card_error);
  EXPECT_THROW(PlayingCard c4(4, 'x'), illegal_card_error);
  EXPECT_THROW(PlayingCard c5(60, 'c'), illegal_card_error);
  EXPECT_THROW(PlayingCard c6(-20, 'h'), illegal_card_error);
  EXPECT_THROW(PlayingCard c7(100, 'p'), illegal_card_error);
}

TEST(TestPlayingCard, getSuit) {
  //Test to ensure the getSuitStr() method returns correct value.
  //Creating PlayingCard objects.
  PlayingCard* c1 = new PlayingCard(2, 'd');
  PlayingCard* c2 = new PlayingCard(3, 'h');
  PlayingCard* c3 = new PlayingCard(9, 'c');
  PlayingCard* c4 = new PlayingCard(10, 's');

  //Testing to ensure getSuitStr() returns correct value.
  EXPECT_EQ(c1 -> getSuitStr(), "diamonds");
  EXPECT_EQ(c2 -> getSuitStr(), "hearts");
  EXPECT_EQ(c3 -> getSuitStr(), "clubs");
  EXPECT_EQ(c4 -> getSuitStr(), "spades");

  //Deleting PlayingCard objects.
  delete c1;
  delete c2;
  delete c3;
  delete c4;
}

TEST(TestPlayingCard, getFace) {
  //Test to ensure the getFaceStr() method returns correct value.
  //Creating PlayingCard objects.
  PlayingCard* cards[13];
  for (int i = 0; i < 13; i++) {
    cards[i] = new PlayingCard(i + 1, 's');
  }

  //Testing to ensure getFaceStr() returns correct value.
  EXPECT_EQ(cards[0] -> getFaceStr(), "ace");
  EXPECT_EQ(cards[1] -> getFaceStr(), "two");
  EXPECT_EQ(cards[2] -> getFaceStr(), "three");
  EXPECT_EQ(cards[3] -> getFaceStr(), "four");
  EXPECT_EQ(cards[4] -> getFaceStr(), "five");
  EXPECT_EQ(cards[5] -> getFaceStr(), "six");
  EXPECT_EQ(cards[6] -> getFaceStr(), "seven");
  EXPECT_EQ(cards[7] -> getFaceStr(), "eight");
  EXPECT_EQ(cards[8] -> getFaceStr(), "nine");
  EXPECT_EQ(cards[9] -> getFaceStr(), "ten");
  EXPECT_EQ(cards[10] -> getFaceStr(), "jack");
  EXPECT_EQ(cards[11] -> getFaceStr(), "queen");
  EXPECT_EQ(cards[12] -> getFaceStr(), "king");

  //Deleting PlayingCard objects.
  for (int i = 0; i < 13; i++) {
    delete cards[i];
  }
}

TEST(TestPlayingCard, getName) {
  //Test to ensure the getName() method returns correct value.
  //Creating PlayingCard objects.
  PlayingCard* c1 = new PlayingCard(2, 'd');
  PlayingCard* c2 = new PlayingCard(9, 'h');
  PlayingCard* c3 = new PlayingCard(1, 'c');
  PlayingCard* c4 = new PlayingCard(10, 's');
  PlayingCard* c5 = new PlayingCard(11, 'h');
  PlayingCard* c6 = new PlayingCard(12, 'c');
  PlayingCard* c7 = new PlayingCard(13, 's');

  //Testing to ensure getName() returns correct value.
  EXPECT_EQ(c1 -> getName(), "two of diamonds");
  EXPECT_EQ(c2 -> getName(), "nine of hearts");
  EXPECT_EQ(c3 -> getName(), "ace of clubs");
  EXPECT_EQ(c4 -> getName(), "ten of spades");
  EXPECT_EQ(c5 -> getName(), "jack of hearts");
  EXPECT_EQ(c6 -> getName(), "queen of clubs");
  EXPECT_EQ(c7 -> getName(), "king of spades");

  //Deleting PlayingCard objects.
  delete c1;
  delete c2;
  delete c3;
  delete c4;
  delete c5;
  delete c6;
  delete c7;
}

TEST(TestPlayingCard, getSimpleName) {
  //Test to ensure the getSimpleName() method returns correct value.
  //Creating PlayingCard objects.
  PlayingCard* c1 = new PlayingCard(2, 'd');
  PlayingCard* c2 = new PlayingCard(9, 'h');
  PlayingCard* c3 = new PlayingCard(1, 'c');
  PlayingCard* c4 = new PlayingCard(10, 's');
  PlayingCard* c5 = new PlayingCard(11, 'h');
  PlayingCard* c6 = new PlayingCard(12, 'c');
  PlayingCard* c7 = new PlayingCard(13, 's');

  //Testing to ensure getSimpleName() returns correct value.
  EXPECT_EQ(c1 -> getSimpleName(), "d2");
  EXPECT_EQ(c2 -> getSimpleName(), "h9");
  EXPECT_EQ(c3 -> getSimpleName(), "ca");
  EXPECT_EQ(c4 -> getSimpleName(), "s10");
  EXPECT_EQ(c5 -> getSimpleName(), "hj");
  EXPECT_EQ(c6 -> getSimpleName(), "cq");
  EXPECT_EQ(c7 -> getSimpleName(), "sk");

  //Deleting PlayingCard objects.
  delete c1;
  delete c2;
  delete c3;
  delete c4;
  delete c5;
  delete c6;
  delete c7;
}
