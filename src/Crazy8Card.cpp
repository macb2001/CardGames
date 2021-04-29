#include "Crazy8Card.h"

bool Crazy8Card::matches(Card* c) {
  if (c -> getFace() == this -> getFace()
    || c -> getSuit() == this -> getSuit()
    || c -> getFace() == 8
    || this -> getFace() == 8) {
    return true;
  } else {
    return false;
  }
}
