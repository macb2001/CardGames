/*
Test file for GoFishCard class.
*/

#include "gtest/gtest.h"
#include "GoFishCard.h"

TEST(TestGoFishCard, matches) {
  //Test to ensure matches returns proper value for matching cards.
  //Creating GoFishCard objects.
  GoFishCard *c1 = new GoFishCard(13, 'c');
  GoFishCard *c2 = new GoFishCard(13, 's');
  GoFishCard *c3 = new GoFishCard(1, 'd');
  GoFishCard *c4 = new GoFishCard(1, 'h');

  //Performing tests to ensure correct value
  EXPECT_TRUE(c1 -> matches(c1));
  EXPECT_TRUE(c1 -> matches(c2));
  EXPECT_TRUE(c3 -> matches(c3));
  EXPECT_TRUE(c3 -> matches(c4));

  //Deleting objects.
  delete c1;
  delete c2;
  delete c3;
  delete c4;
}

TEST(TestGoFishCard, invalidMatches) {
  //Test to ensure matches returns proper value for non-matching cards.
  //Creating GoFishCard objects.
  GoFishCard *c1 = new GoFishCard(13, 'c');
  GoFishCard *c2 = new GoFishCard(12, 'c');
  GoFishCard *c3 = new GoFishCard(1, 'd');

  //Performing tests to ensure correct value
  EXPECT_FALSE(c1 -> matches(c2));
  EXPECT_FALSE(c1 -> matches(c3));
  EXPECT_FALSE(c2 -> matches(c3));

  //Deleting objects.
  delete c1;
  delete c2;
  delete c3;
}
