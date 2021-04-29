/*
Test file for Uno class things.
*/

#include "gtest/gtest.h"
#include "Uno.h"

TEST(TestUno, turnChangeNormal) {
  Uno uno;
  uno.setPlayerNum(5);

  EXPECT_EQ(uno.getTurn(), 0);
  uno.nextTurn();
  EXPECT_EQ(uno.getTurn(), 1);
  uno.nextTurn();
  EXPECT_EQ(uno.getTurn(), 2);
  uno.nextTurn();
  EXPECT_EQ(uno.getTurn(), 3);
  uno.nextTurn();
  EXPECT_EQ(uno.getTurn(), 4);
  uno.nextTurn();
  EXPECT_EQ(uno.getTurn(), 0);
  uno.nextTurn();
  EXPECT_EQ(uno.getTurn(), 1);
}

TEST(TestUno, turnChangeReverse) {
  Uno uno;
  uno.setPlayerNum(5);

  uno.swapTurnOrder();
  EXPECT_EQ(uno.getTurn(), 0);
  uno.nextTurn();
  EXPECT_EQ(uno.getTurn(), 4);
  uno.nextTurn();
  EXPECT_EQ(uno.getTurn(), 3);
  uno.nextTurn();
  EXPECT_EQ(uno.getTurn(), 2);
  uno.nextTurn();
  EXPECT_EQ(uno.getTurn(), 1);
  uno.nextTurn();
  EXPECT_EQ(uno.getTurn(), 0);
  uno.nextTurn();
  EXPECT_EQ(uno.getTurn(), 4);
  uno.nextTurn();
  EXPECT_EQ(uno.getTurn(), 3);
  uno.nextTurn();
  EXPECT_EQ(uno.getTurn(), 2);
  uno.nextTurn();
  EXPECT_EQ(uno.getTurn(), 1);
}
