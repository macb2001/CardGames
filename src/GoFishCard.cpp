#include "GoFishCard.h"

bool GoFishCard::matches(Card* c) {
  if (c->getFace() == getFace()) {
    return true;
  } else {
    return false;
  }
}
