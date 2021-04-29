#include <algorithm>
#include <string>
#include <random>
#include "Hand.h"
#include "Pile.h"
#include "Card.h"
#include "Exceptions.h"

bool lessThan(Card* a, Card* b) {
  if (a -> getSuit() > b -> getSuit())
    return false;
  else if (a -> getSuit() < b -> getSuit())
    return true;
  else
    return(a -> getFace() < b -> getFace());
}

std::string Hand::displayHand() {
  std::sort(cards.begin(), cards.end(), lessThan);
  std::string output;

  output += '|';
  for (auto c : cards)
    output += c -> getSimpleName() + '|';

  return output;
}

Card* Hand::findFace(int face) {
  for (int i = 0; i < cards.size(); i++) {
    if (cards[i]->getFace() == face)
      return cards[i];
  }
  // if nothing is found then return a null pointer.
  return nullptr;
}

Card* Hand::findSuit(char suit) {
  for (int i = 0; i < cards.size(); i++) {
    if (cards[i]->getSuit() == suit) {
      return cards[i];
    }
  }
  // if nothing is found then return a null pointer.
  return nullptr;
}

Card* Hand::findCard(int face, char suit) {
  for (int i = 0; i < cards.size(); i++) {
    if ((cards[i]->getFace() == face) && (cards[i]->getSuit() == suit))
      return cards[i];
  }
  // if nothing is found then return a null pointer.
  return nullptr;
}

Card* Hand::getRandomCard() {
  checkEmptyHand();

  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist(0, this -> getSize());
  int randInt = dist(mt);

  return cards[randInt];
}

void Hand::placeCard(Pile* p, Card* c) {
  checkEmptyHand();
  // Check that card is in hand first
  bool exists = false;
  for (auto card : cards) {
    if (card == c) {
      exists = true;
      break;
    }
  }
  if (!exists)
    throw invalid_deck_operation("Card does not exist in hand");

  p -> addCard(c);
  removeCard(c);
}

void Hand::checkEmptyHand() {
  if (this -> isEmpty())
    throw invalid_deck_operation("No Cards In Hand!");
}
