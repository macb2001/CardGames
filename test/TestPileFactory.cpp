/*
Test file for PileFactory class.
*/

#include <iostream>
#include "gtest/gtest.h"
#include "PileFactory.h"
#include "Pile.h"
#include "Card.h"
#include "GoFishCard.h"
#include "Crazy8Card.h"
#include "UnoCard.h"

TEST(TestPileFactory, GoFishPile) {
  PileFactory factory;
  Pile* p = factory.createPile(PileFactory::GOFISH);

  int i = 0;
  Card* a = nullptr;

  for (; i < 13; i++) {
    a = new GoFishCard(i + 1, 'c');
    EXPECT_TRUE(p->getCards()[i]->matches(a));
    delete a;
    a = nullptr;
  }

  for (int j = 1; i < 26; i++) {
    a = new GoFishCard(j, 'd');
    EXPECT_TRUE(p->getCards()[i]->matches(a));
    delete a;
    a = nullptr;
    j++;
  }

  for (int j = 1; i < 39; i++) {
    a = new GoFishCard(j, 'h');
    EXPECT_TRUE(p->getCards()[i]->matches(a));
    delete a;
    a = nullptr;
    j++;
  }

  for (int j = 1; i < 52; i++) {
    a = new GoFishCard(j, 's');
    EXPECT_TRUE(p->getCards()[i]->matches(a));
    delete a;
    a = nullptr;
    j++;
  }

  delete p;
}

TEST(TestPileFactory, Crazy8Pile) {
  PileFactory factory;
  Pile* p = factory.createPile(PileFactory::CRAZY8);

  int i = 0;
  Card* a = nullptr;

  for (; i < 13; i++) {
    a = new Crazy8Card(i + 1, 'c');
    EXPECT_TRUE(p->getCards()[i]->matches(a));
    delete a;
    a = nullptr;
  }

  for (int j = 1; i < 26; i++) {
    a = new Crazy8Card(j, 'd');
    EXPECT_TRUE(p->getCards()[i]->matches(a));
    delete a;
    a = nullptr;
    j++;
  }

  for (int j = 1; i < 39; i++) {
    a = new Crazy8Card(j, 'h');
    EXPECT_TRUE(p->getCards()[i]->matches(a));
    delete a;
    a = nullptr;
    j++;
  }

  for (int j = 1; i < 52; i++) {
    a = new Crazy8Card(j, 's');
    EXPECT_TRUE(p->getCards()[i]->matches(a));
    delete a;
    a = nullptr;
    j++;
  }

  delete p;
}

TEST(TestPileFactory, UnoPile) {
  PileFactory factory;
  Pile* p = factory.createPile(PileFactory::UNO);

  int i = 0;
  Card* a = nullptr;

  for (; i < 13; i++) {
    a = new UnoCard(i, 'b');
    EXPECT_TRUE(p->getCards()[i]->matches(a));
    delete a;
  }

  for (int j = 0; i < 26; i++) {
    a = new UnoCard(j, 'g');
    EXPECT_TRUE(p->getCards()[i]->matches(a));
    delete a;
    j++;
  }

  for (int j = 0; i < 39; i++) {
    a = new UnoCard(j, 'r');
    EXPECT_TRUE(p->getCards()[i]->matches(a));
    delete a;
    j++;
  }

  for (int j = 0; i < 52; i++) {
    a = new UnoCard(j, 'b');
    EXPECT_TRUE(p->getCards()[i]->matches(a));
    delete a;
    j++;
  }

  a = new UnoCard(13, 'w');

  for (; i < 54; i++)
    EXPECT_TRUE(p->getCards()[i]->matches(a));

  delete a;
  a = new UnoCard(14, 'w');

  for (; i < 56; i++)
    EXPECT_TRUE(p->getCards()[i]->matches(a));

  delete a;
  a = nullptr;

  delete p;
  p = nullptr;
}
