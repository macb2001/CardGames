//Implementation file for Card class.

#include "Card.h"
#include <iostream>

Card::Card(int face, char suit) : face{face}, suit{suit} {}

char Card::getSuit() const {
  return suit;
}

int Card::getFace() const {
  return face;
}
