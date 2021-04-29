/*
Test file for Crazy8Card class.
*/

#include "gtest/gtest.h"
#include "Crazy8Card.h"

TEST(TestCrazy8Card, matches) {
  //Test to ensure matches returns proper value for matching cards.
  //Creating Crazy8Card objects.
  Crazy8Card *c1 = new Crazy8Card(13, 'c');
  Crazy8Card *c2 = new Crazy8Card(13, 's');
  Crazy8Card *c3 = new Crazy8Card(1, 'c');
  Crazy8Card *c4 = new Crazy8Card(8, 'h');

  //Performing tests to ensure correct value
  EXPECT_TRUE(c1 -> matches(c1));
  EXPECT_TRUE(c1 -> matches(c2));
  EXPECT_TRUE(c1 -> matches(c3));
  EXPECT_TRUE(c4 -> matches(c3));
  EXPECT_TRUE(c4 -> matches(c1));
  EXPECT_TRUE(c3 -> matches(c4));
  EXPECT_TRUE(c1 -> matches(c4));
  EXPECT_TRUE(c4 -> matches(c4));

  //Deleting objects.
  delete c1;
  delete c2;
  delete c3;
  delete c4;
}

TEST(TestCrazy8Card, invalidMatches) {
  //Test to ensure matches returns proper value for non-matching cards.
  //Creating Crazy8Card objects.
  Crazy8Card *c1 = new Crazy8Card(13, 'c');
  Crazy8Card *c2 = new Crazy8Card(1, 's');

  //Performing tests to ensure correct value
  EXPECT_FALSE(c1 -> matches(c2));
  EXPECT_FALSE(c2 -> matches(c1));

  //Deleting objects.
  delete c1;
  delete c2;
}
