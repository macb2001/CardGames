/*
Test file for UnoCard class.
*/

#include "gtest/gtest.h"
#include "UnoCard.h"

TEST(TestUnoCard, constructor) {
  //Tests to ensure valid constructor parameters don't cause error.
  EXPECT_NO_THROW(UnoCard c1(0, 'r'));
  EXPECT_NO_THROW(UnoCard c2(12, 'g'));
  EXPECT_NO_THROW(UnoCard c3(11, 'b'));
  EXPECT_NO_THROW(UnoCard c4(10, 'y'));
  EXPECT_NO_THROW(UnoCard c5(13, 'w'));
  EXPECT_NO_THROW(UnoCard c7(14, 'w'));
}

TEST(TestUnoCard, invalidConstructor) {
  //Tests to ensure invalid constructor parameters cause error.
  EXPECT_THROW(UnoCard c1(-1, 'r'), illegal_card_error);
  EXPECT_THROW(UnoCard c2(15, 'g'), illegal_card_error);
  EXPECT_THROW(UnoCard c3(8, 'w'), illegal_card_error);
  EXPECT_THROW(UnoCard c4(13, 'y'), illegal_card_error);
  EXPECT_THROW(UnoCard c5(14, 'b'), illegal_card_error);
  EXPECT_THROW(UnoCard c6(60, 'w'), illegal_card_error);
  EXPECT_THROW(UnoCard c7(-20, 'b'), illegal_card_error);
  EXPECT_THROW(UnoCard c7(-20, 'z'), illegal_card_error);
}

TEST(TestUnoCard, getSuitStr) {
  //Test to ensure getSuit() method returns correct value.
  //Creating UnoCard objects.
  UnoCard *c1 = new UnoCard(12, 'g');
  UnoCard *c2 = new UnoCard(11, 'r');
  UnoCard *c3 = new UnoCard(10, 'b');
  UnoCard *c4 = new UnoCard(0, 'y');
  UnoCard *c5 = new UnoCard(13, 'w');

  //Testing method return value.
  EXPECT_EQ(c1 -> getSuitStr(), "green");
  EXPECT_EQ(c2 -> getSuitStr(), "red");
  EXPECT_EQ(c3 -> getSuitStr(), "blue");
  EXPECT_EQ(c4 -> getSuitStr(), "yellow");
  EXPECT_EQ(c5 -> getSuitStr(), "wild");

  //Deleting objects.
  delete c1;
  delete c2;
  delete c3;
  delete c4;
  delete c5;
}

TEST(TestUnoCard, getFaceStr) {
  //Test to ensure getFace() method returns correct value.

  //Creating UnoCard objects.
  UnoCard* cards[15];
  for (int i = 0; i < 13; i++) {
    cards[i] = new UnoCard(i, 'g');
  }
  cards[13] = new UnoCard(13, 'w');
  cards[14] = new UnoCard(14, 'w');

  //Testing method return value.
  EXPECT_EQ(cards[0] -> getFaceStr(), "zero");
  EXPECT_EQ(cards[1] -> getFaceStr(), "one");
  EXPECT_EQ(cards[2] -> getFaceStr(), "two");
  EXPECT_EQ(cards[3] -> getFaceStr(), "three");
  EXPECT_EQ(cards[4] -> getFaceStr(), "four");
  EXPECT_EQ(cards[5] -> getFaceStr(), "five");
  EXPECT_EQ(cards[6] -> getFaceStr(), "six");
  EXPECT_EQ(cards[7] -> getFaceStr(), "seven");
  EXPECT_EQ(cards[8] -> getFaceStr(), "eight");
  EXPECT_EQ(cards[9] -> getFaceStr(), "nine");
  EXPECT_EQ(cards[10] -> getFaceStr(), "skip");
  EXPECT_EQ(cards[11] -> getFaceStr(), "reverse");
  EXPECT_EQ(cards[12] -> getFaceStr(), "plus two");
  EXPECT_EQ(cards[13] -> getFaceStr(), "plus four");
  EXPECT_EQ(cards[14] -> getFaceStr(), "change colour");

  //Deleting objects.
  for (int i = 0; i < 15; i++) {
    delete cards[i];
  }
}

TEST(TestUnoCard, getName) {
  //Test to ensure getFace() method returns correct value.
  //Creating UnoCard objects.
  UnoCard *c1 = new UnoCard(12, 'g');
  UnoCard *c2 = new UnoCard(11, 'r');
  UnoCard *c3 = new UnoCard(10, 'b');
  UnoCard *c4 = new UnoCard(0, 'y');
  UnoCard *c5 = new UnoCard(14, 'w');

  //Testing method return value.
  EXPECT_EQ(c1 -> getName(), "green plus two");
  EXPECT_EQ(c2 -> getName(), "red reverse");
  EXPECT_EQ(c3 -> getName(), "blue skip");
  EXPECT_EQ(c4 -> getName(), "yellow zero");
  EXPECT_EQ(c5 -> getName(), "wild change colour");

  //Deleting objects.
  delete c1;
  delete c2;
  delete c3;
  delete c4;
  delete c5;
}

TEST(TestUnoCard, getSimpleName) {
  //Test to ensure getSimpleName() method returns correct value.
  //Creating UnoCard objects.
  UnoCard *c1 = new UnoCard(12, 'g');
  UnoCard *c2 = new UnoCard(11, 'r');
  UnoCard *c3 = new UnoCard(10, 'b');
  UnoCard *c4 = new UnoCard(0, 'y');
  UnoCard *c5 = new UnoCard(14, 'w');
  UnoCard *c6 = new UnoCard(13, 'w');

  //Testing method return value.
  EXPECT_EQ(c1 -> getSimpleName(), "g+2");
  EXPECT_EQ(c2 -> getSimpleName(), "rr");
  EXPECT_EQ(c3 -> getSimpleName(), "bs");
  EXPECT_EQ(c4 -> getSimpleName(), "y0");
  EXPECT_EQ(c5 -> getSimpleName(), "wcc");
  EXPECT_EQ(c6 -> getSimpleName(), "w+4");

  //Deleting objects.
  delete c1;
  delete c2;
  delete c3;
  delete c4;
  delete c5;
  delete c6;
}

TEST(TestUnoCard, matches) {
  //Test to ensure matches returns proper value for matching cards.
  //Creating UnoCard objects.
  UnoCard *c1 = new UnoCard(0, 'g');
  UnoCard *c2 = new UnoCard(0, 'r');
  UnoCard *c3 = new UnoCard(12, 'g');
  UnoCard *c4 = new UnoCard(14, 'w');

  //Performing tests to ensure correct value
  EXPECT_TRUE(c1 -> matches(c1));
  EXPECT_TRUE(c1 -> matches(c2));
  EXPECT_TRUE(c1 -> matches(c3));
  EXPECT_TRUE(c4 -> matches(c1));
  EXPECT_TRUE(c3 -> matches(c1));
  EXPECT_TRUE(c3 -> matches(c4));
  EXPECT_TRUE(c4 -> matches(c4));

  //Deleting objects.
  delete c1;
  delete c2;
  delete c3;
  delete c4;
}

TEST(TestUnoCard, invalidMatches) {
  //Test to ensure matches returns proper value for non-matching cards.
  //Creating UnoCard objects.
  UnoCard *c1 = new UnoCard(8, 'b');
  UnoCard *c2 = new UnoCard(6, 'r');

  //Performing tests to ensure correct value
  EXPECT_FALSE(c1 -> matches(c2));
  EXPECT_FALSE(c2 -> matches(c1));

  //Deleting objects.
  delete c1;
  delete c2;
}
