//Implementation file for PlayingCardFactory class.

#include "PileFactory.h"
#include "Deck.h"
#include "Card.h"
#include "GoFishCard.h"
#include "Crazy8Card.h"
#include "UnoCard.h"
#include "Pile.h"
#include "Hand.h"
#include <iostream>

Pile* PileFactory::createPile(PileFactory::TYPE t) {
  Pile* newPile = new Pile;
  Card* c = nullptr;

  if (t == PileFactory::GOFISH) {
    for (int i = 1; i < 14; i++)
      newPile->addCard(new GoFishCard(i, 'c'));

    for (int i = 1; i < 14; i++)
      newPile->addCard(new GoFishCard(i, 'd'));

    for (int i = 1; i < 14; i++)
      newPile->addCard(new GoFishCard(i, 'h'));

    for (int i = 1; i < 14; i++)
      newPile->addCard(new GoFishCard(i, 's'));

    return newPile;
  } else if (t == PileFactory::CRAZY8) {
    for (int i = 1; i < 14; i++)
      newPile->addCard(new Crazy8Card(i, 'c'));

    for (int i = 1; i < 14; i++)
      newPile->addCard(new Crazy8Card(i, 'd'));

    for (int i = 1; i < 14; i++)
      newPile->addCard(new Crazy8Card(i, 'h'));

    for (int i = 1; i < 14; i++)
      newPile->addCard(new Crazy8Card(i, 's'));

    return newPile;

  } else if (t == PileFactory::UNO) {
    for (int i = 0; i < 13; i++)
      newPile->addCard(new UnoCard(i, 'b'));

    for (int i = 0; i < 13; i++)
      newPile->addCard(new UnoCard(i, 'g'));

    for (int i = 0; i < 13; i++)
      newPile->addCard(new UnoCard(i, 'r'));

    for (int i = 0; i < 13; i++)
      newPile->addCard(new UnoCard(i, 'y'));

    newPile->addCard(new UnoCard(13, 'w'));
    newPile->addCard(new UnoCard(13, 'w'));

    newPile->addCard(new UnoCard(14, 'w'));
    newPile->addCard(new UnoCard(14, 'w'));

    return newPile;
  } else {
    return nullptr;
  }
}
