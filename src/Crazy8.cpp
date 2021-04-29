#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "Crazy8.h"
#include "Pile.h"
#include "Card.h"
#include "Crazy8Card.h"
#include "Crazy8Player.h"
#include "Player.h"
#include "PileFactory.h"

void Crazy8::run() {
  help();
  std::cout << "\nSetting up game ..." << std::endl;

  std::string name;
  int cpuPlayers;
  std::cout << "\nWhat is your name?: ";
  std::cin >> name;
  players.push_back(new Crazy8Player(name, true));

  if (name == "John")
    std::cout << "Hello, Dr. Anvik" << std::endl;

  if (name == "Jannatul")
    std::cout << "Hello, Jannatul. "
    <<"We've been expecting you. I hope that doesn't sound too creepy."
    << std::endl;

  do {
    std::cout << "\nHow many CPU players would you like? (1 to 4): ";
    std::cin >> cpuPlayers;

    if (cpuPlayers < 1 || cpuPlayers > 4) {
      std::cout << "Invalid number of CPU getPlayers() inputted!"
        << "Please try again!" << std::endl;
    }
  } while (cpuPlayers < 1 || cpuPlayers > 4);

  setPlayerNum(cpuPlayers);

  std::cout << "Players created ..." << std::endl;

  createPiles();

  std::cout << "Created and shuffled deck ..." << std::endl;

  deal(5);

  std::cout << "Hands dealt ..." << std::endl;

  std::cout << getDrawPile() -> getSize() << std::endl;

  std::cout << "\n====Starting Game====" << std::endl;
  getDiscardPile() -> takeCard(getDrawPile(), getDrawPile() -> getTopCard());

  do {
    round();
  } while (!(isWinner));
  std::cout << "\nThe Game Has Ended!\nThanks for playing!" << std::endl;
}

void Crazy8::round() {
  for (auto p : getPlayers()) {
    std::cout << "\n\n====" << p -> getName() << "'s turn!====\n"
      << p -> getNumOfCards() << " cards left\nDiscard Pile Card: "
      << getDiscardPile() -> getTopCard() -> getName() << std::endl;

    takeTurn(p);

    if (p -> getNumOfCards() == 0) {
      isWinner = true;
      std::cout << "\n" << p -> getName() << " has won!" << std::endl;
      break;
    }
  }
}

void Crazy8::takeTurn(Player *p) {
  if (p -> getIsHuman()) {
      humanTurn(p);
  } else {
      CPUTurn(p);
    }
}

void Crazy8::CPUTurn(Player* p) {
  bool playedCard = false;
  for (auto c : p -> getHand() -> getCards()) {
    if (getDiscardPile() -> getTopCard() -> matches(c)) {
      p -> getHand() -> placeCard(getDiscardPile(), c);
      std::cout << p -> getName() << " played " << c -> getName();
      playedCard = true;
      break;
    }
  }
  if (!(playedCard))
    drawCards(p);
}

void Crazy8::humanTurn(Player *p) {
  char cardSuit;
  std::string input;
  int cardRank;
  bool played = false;
  bool cardInHand = false;
  bool cardPlayable = false;
  do {
    std::cout << "====Your Hand====\n" << p -> getHand() -> displayHand()
      << "\nInput a card to play (as displayed) or input 'draw': ";
    std::cin >> input;
    input += " ";

    if (input == "draw ") {
      played = true;
      cardInHand = true;
      cardPlayable = true;
      drawCards(p);
    } else if (input.length() != 3) {
      std::cout << "Invalid entry. Please enter a card as displayed."
      << std::endl;
      continue;
    } else {
      cardSuit = input[0];
      cardRank = returnCardRank(input.substr(1, 2));

      if (p -> getHand() -> findCard(cardRank, cardSuit) == nullptr) {
        std::cout << "Card not found in hand! Please try again!"
        << std::endl;
      } else {
        cardInHand = true;
        Crazy8Card* selectedCard = static_cast<Crazy8Card*>(p -> getHand()
          -> findCard(cardRank, cardSuit));

        if (!(getDiscardPile() -> getTopCard() -> matches(selectedCard))) {
          cardPlayable = false;
          std::cout << "Card unable to be played! Please try again!"
            << std::endl;
        } else {
          cardPlayable = true;
          p -> getHand()
            -> placeCard(getDiscardPile(), selectedCard);
          std::cout << p -> getName() << " played "
            << selectedCard -> getName() << std::endl;
          played = true;
          selectedCard = nullptr;
        }
      }
    }
  } while (!(cardPlayable)
      || played == false
      || !(cardInHand));
}

int Crazy8::returnCardRank(std::string s) {
  if (s == "k ")
    return 13;
  else if (s == "q ")
    return 12;
  else if (s == "j ")
    return 11;
  else if (s == "a ")
    return 1;
  else
    return std::stoi(s);
}

void Crazy8::recyclePiles() {
  while (!(getDiscardPile() -> isEmpty())) {
    getDrawPile()
      -> takeCard(getDiscardPile(), getDiscardPile() -> getTopCard());
  }
  getDrawPile() -> shuffle();
}

void Crazy8::drawCards(Player* p) {
  bool playedCard = false;
  for (int i = 0; i < 3; i++) {
    Crazy8Card* topCard;
    topCard = static_cast<Crazy8Card*>(getDrawPile() -> getTopCard());
    std::cout << "\nDrew a " << topCard -> getName() << std::endl;
    p -> drawCard(getDrawPile());
    if (getDrawPile() -> isEmpty())
      recyclePiles();

    if (topCard -> matches(getDiscardPile() -> getTopCard())) {
      p -> getHand() -> placeCard(getDiscardPile(), topCard);
      std::cout << "Played the " << topCard -> getName() << std::endl;
      playedCard = true;
      break;
    } else {
      std::cout << "Unable to play drawn card!" << std::endl;
      if (i < 2)
        std::cout << "Drawing Another!" << std::endl;
    }
    topCard = nullptr;
  }
  if (!(playedCard))
    std::cout << "Unable to play any drawn cards! Skipping Turn!" << std::endl;
}

void Crazy8::createPiles() {
  PileFactory* factory = nullptr;
  drawPile = factory -> createPile(PileFactory::CRAZY8);
  discardPile = new Pile();
  getDrawPile() -> shuffle();
}

void Crazy8::setPlayerNum(int p) {
  for (int i = 0; i < p; i++) {
    players.push_back(
      new Crazy8Player("CPU" + std::to_string(i + 1), false));
  }
}

void Crazy8::deal(int numOfCards) {
  for (auto p : getPlayers())
    p -> drawCard(getDrawPile(), numOfCards);
}

void Crazy8::help() {
  std::cout
    << "====Welcome to Crazy Eights!===="
    << "\n====Object===="
    << "\nBe the first player to run out of cards in your hand."
    << "\n====How to play===="
    << "\nThe game uses a standard 52-card deck. Each player is dealt 5 cards."
    << "\nplayers take turns playing one card on the discard pile."
    << "\nCards with the same rank, suit, or that are 8s can be played on"
    << "\none another."
    << "\nIf a player cannot play a card, they draw up to 3 cards from the"
    << "\ndraw pile in an attempt to find one they can then play."
    << "\nIf a player is unsuccessful after drawing 3 cards, it is the next"
    << "\nplayer's turn." << std::endl;
}
