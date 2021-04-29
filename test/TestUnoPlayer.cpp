/*
Test file for UnoPlayer class.
*/

#include "gtest/gtest.h"
#include "UnoPlayer.h"
#include "UnoCard.h"
#include "Deck.h"
#include "Pile.h"

TEST(TestUnoPlayer, constructor) {
  //Test to ensure valid constructor parameters don't throw error.
  EXPECT_NO_THROW(UnoPlayer("Sam", true));
  EXPECT_NO_THROW(UnoPlayer("CPU", false));
}
