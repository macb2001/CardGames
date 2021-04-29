#include <vector>
#include "Deck.h"
#include "Card.h"
#include "Exceptions.h"

Deck::~Deck() {
  if (!cards.empty()) {
    for (int i = 0; i < cards.size(); i++)
      delete cards[i];

    cards.clear();
  }
}

void Deck::addCard(Card* c) {
  cards.push_back(c);
}

void Deck::removeCard(Card* c) {
  // Check if card is actually in the deck before removing it
  bool exists = false;
  for (int i = 0; i < cards.size(); i++) {
    if (cards[i] == c) {
      exists = true;
      cards.erase(cards.begin() + i);
      break;
    }
  }
  if (exists == false)
    throw invalid_deck_operation("Card not in deck");
}

void Deck::takeCard(Deck* d, Card* c) {
  d -> removeCard(c);
  this -> addCard(c);
}

int Deck::getSize() {
  return cards.size();
}

std::vector<Card*> Deck::getCards() {
  return cards;
}

bool Deck::isEmpty() {
  return cards.empty();
}
