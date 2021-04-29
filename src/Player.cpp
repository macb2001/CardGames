#include "Player.h"

#include "Deck.h"
#include "Pile.h"
#include "Hand.h"
#include <string>

Player::Player(std::string name_, bool isHuman_) {
  name = name_;
  isHuman = isHuman_;

  hand = new Hand();
}

Player::~Player() {
  delete hand;
}

void Player::drawCard(Pile* d) {
  this -> getHand() -> takeCard(d, d->getTopCard());
}

void Player::drawCard(Pile* d, int numb) {
  while (numb > 0) {
    this -> drawCard(d);
    numb--;
  }
}

Hand* Player::getHand() {
  return hand;
}

int Player::getNumOfCards() {
  return getHand()->getSize();
}

std::string Player::getName() {
  return name;
}

bool Player::getIsHuman() {
  return isHuman;
}
