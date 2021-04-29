#include <random>
#include <algorithm>
#include "Pile.h"
#include "Card.h"
#include "Exceptions.h"

Card* Pile::getTopCard() {
  if (this -> isEmpty())
    throw invalid_deck_operation("No Cards In Pile");
  else
    return cards.back();
}

void Pile::shuffle() {
  std::random_device rd;
  std::shuffle(std::begin(cards), std::end(cards), rd);
}
