#include <string>
#include <iostream>
#include "Card.h"
#include "GoFishPlayer.h"
#include "Pile.h"

int GoFishPlayer::getPairs() {
  return pairs;
}

bool GoFishPlayer::makePair(int face, Pile* discardPile) {
  // Find card, if found put it in the discardPile
  Card* c1 = getHand()->findFace(face);
  if (c1 != nullptr) {
    getHand()->placeCard(discardPile, c1);
  }
  Card* c2 = getHand()->findFace(face);
  if (c2 != nullptr) {
    getHand()->placeCard(discardPile, c2);
    pairs += 1;
    return true;
  } else {
    if (c1 != nullptr) {
      drawCard(discardPile);
    }
    return false;
  }
}

void GoFishPlayer::makeAllPairs(Pile* discardPile) {
  for (int i = 1; i < 14; i++) {
    makePair(i, discardPile);
  }
}

bool GoFishPlayer::hasCard(int face) {
  if (getHand()->findFace(face) != nullptr) {
    return true;
  } else {
    return false;
  }
}
