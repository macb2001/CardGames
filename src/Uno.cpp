#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <random>
#include "Uno.h"
#include "Pile.h"
#include "Card.h"
#include "UnoCard.h"
#include "UnoPlayer.h"
#include "Player.h"
#include "PileFactory.h"

void Uno::run() {
  help();
  std::cout << "\nSetting up game ..." << std::endl;

  std::string name;
  int cpuPlayers;
  std::cout << "\nWhat is your name?: ";
  std::cin >> name;
  players.push_back(new UnoPlayer(name, true));

  do {
    std::cout << "\nHow many CPU players would you like? (1 to 6): ";
    std::cin >> cpuPlayers;

    if (cpuPlayers < 1 || cpuPlayers > 6) {
      std::cout << "Invalid number of CPU players inputted!"
        << "Please try again!" << std::endl;
    }
  } while (cpuPlayers < 1 || cpuPlayers > 6);

  setPlayerNum(cpuPlayers);

  std::cout << "Players created ..." << std::endl;

  createPiles();

  std::cout << "Created and shuffled deck ..." << std::endl;

  deal(7);

  std::cout << "Hands dealt ..." << std::endl;

  std::cout << "\n====Starting Game====" << std::endl;
  UnoCard* startingCard = static_cast<UnoCard*>(getDrawPile()->getTopCard());
  while (startingCard->getFace() == 10 || startingCard->getFace() == 10
      || startingCard->getFace() == 10 || startingCard->getFace() == 10) {
        getDrawPile()->shuffle();
      }
  getDiscardPile()->takeCard(getDrawPile(), startingCard);
  startingCard = nullptr;

  do {
    round();
  } while (isWinner == false);
  std::cout << "\nThe Game Has Ended!\nThanks for playing!" << std::endl;
}

void Uno::round() {
  while (true) {
    // Re-factored player loop with this to rely on turn order functions.
    Player* p = players[getTurn()];
    UnoPlayer* p1 = static_cast<UnoPlayer*>(p);

    std::string response;
    std::cout << "\n====" << p1->getName() << "'s turn!====\n"
    << p1->getNumOfCards()
    << " cards left\nDiscard Pile Card: "
    << getDiscardPile()->getTopCard()->getName();

    // Display wild card temp value
    if (getDiscardPile()->getTopCard()->getSuit() == 'w') {
      std::cout << " (";
      switch (getCurrentColour()) {
        case 'b' :
          std::cout << "blue";
          break;
        case 'g' :
          std::cout << "green";
          break;
        case 'r' :
          std::cout << "red";
          break;
        case 'y' :
          std::cout << "yellow";
          break;
      }
      std::cout << ")";
    }

    std::cout << std::endl;

    // New +2 card logic
    if (getStackTally() > 0) {
      forcedPickup(p1);
      nextTurn();
    } else {
      takeTurn(p1);
    }

    // Annoying question popup :p
    do {
      std::cout << "\nWould you like to call UNO! on a player? (enter 'n' or"
        << " the player you want to call it on: ";
      std::cin >> response;
      bool called = false;
      for (auto player : getPlayers()) {
        UnoPlayer* p3 = static_cast<UnoPlayer*>(player);
        if (response == p3->getName()) {
          if (p3->getSaidUNO() == false && p3->getNumOfCards() == 1) {
            p3->drawCard(getDrawPile(), 2);
            break;
          } else {
            std::cout << "Player said UNO or has more than 1 card!"
              << std::endl;
          }
          called = true;
        }
        p3 = nullptr;
      }
      if (response != "n" && called == false) {
        std::cout << "Invalid Input/Player not found! Please Try Again!"
          << std::endl;
        }
    } while (response != "n");
    p1 = nullptr;
    p = nullptr;
  }
}

int Uno::getStackTally() {
  return stackTally;
}

void Uno::setStackTally(int n) {
  stackTally = n;
}

void Uno::takeTurn(Player *p) {
  if (p->getIsHuman()) {
      humanTurn(p);
  } else {
      CPUTurn(p);
  }

  // increments the turn.
  nextTurn();
}

void Uno::forcedPickup(Player* p) {
  std::cout << "\nDrawing +" << getStackTally() << " cards." << std::endl;
  for (; getStackTally() > 0; setStackTally(getStackTally() - 1)) {
    p->drawCard(getDrawPile());
  }
}

void Uno::CPUTurn(Player* p) {
  UnoPlayer* p1 = static_cast<UnoPlayer*>(p);
  bool playedCard = false;
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist(0, 1);
  int randInt = dist(mt);


  if (randInt == 1) {
    bool currentPlayer = false;
    do {
      UnoPlayer* player = static_cast<UnoPlayer*>(getRandPlayer());
      if (player == p1) {
        currentPlayer = true;
      } else if (player->getNumOfCards() == 1
          && player->getSaidUNO() == false) {
        std::cout << "CPU Turn Flag 2.2" << std::endl;
        player->drawCard(getDrawPile(), 2);
      }
    } while (currentPlayer == true);
  }
  for (auto c : p1->getHand()->getCards()) {
    if (isPlayable(c)) {
      std::cout << p1->getName() << " played " << c->getName() << std::endl;
      playCard(c, p1);
      playedCard = true;
      if (randInt == 0 && p1->getNumOfCards() == 1) {
        p1->setSaidUNO(true);
      }
      break;
    }
  }

  if (playedCard == false) {
    drawCards(p1);
  }
  p1 = nullptr;
}

void Uno::humanTurn(Player *p) {
  UnoPlayer* p1 = static_cast<UnoPlayer*>(p);
  char cardSuit;
  std::string input;
  int cardRank;
  bool played = false;
  bool cardInHand = false;
  bool cardPlayable = false;
  do {
    std::cout << "====Your Hand====\n" << p1->getHand()->displayHand()
      << "\nInput a card to play (as displayed) or input 'draw': ";
    std::cin >> input;
    input += " ";

    if (input == "draw ") {
      played = true;
      cardInHand = true;
      cardPlayable = true;
      drawCards(p1);
    } else if (input.length() != 3) {
      std::cout << "Invalid entry. Please enter a card as displayed."
      << std::endl;
      continue;
    } else {
      cardSuit = input[0];
      cardRank = returnCardRank(input.substr(1, 2));

      if (p1->getHand()->findCard(cardRank, cardSuit) == nullptr) {
        std::cout << "Card not found in hand! Please try again!"
        << std::endl;
      } else {
        cardInHand = true;
        UnoCard* selectedCard = static_cast<UnoCard*>(p1->getHand()
         ->findCard(cardRank, cardSuit));

        if (isPlayable(selectedCard) == false) {
          cardPlayable = false;
          std::cout << "Card unable to be played! Please try again!"
            << std::endl;
        } else {
          cardPlayable = true;
          std::cout << p1->getName() << " played "
            << selectedCard->getName() << std::endl;
          playCard(selectedCard, p1);
          char input;
          do {
            std::cout << "Would you like to say 'UNO!'? [y, n]: ";
            std::cin >> input;
            if (input != 'y' && input != 'n')
              std::cout << "Invalid input! Please Try Again!" << std::endl;
          } while (input != 'y' && input != 'n');
          if (input == 'y' && p1->getNumOfCards() == 1) {
            if (p1->getNumOfCards() != 1) {
              std::cout << "You don't have one card left! Can't call UNO!"
                << std::endl;
            } else {
              std::cout << "UNO!" << std::endl;
              p1->setSaidUNO(true);
            }
          }

          played = true;
          selectedCard = nullptr;
        }
      }
    }
  } while (cardPlayable == false
      || played == false
      || cardInHand == false);
  p1 = nullptr;
}

bool Uno::isPlayable(Card *c) {
  if (c->getSuit() == 'w')
    return true;
  else if (getDiscardPile()->getTopCard()->getSuit() == 'w')
    return getCurrentColour() == c->getSuit();
  else
    return getDiscardPile()->getTopCard()->matches(c);
}

char Uno::getCurrentColour() {
  return currentColour;
}

void Uno::playCard(Card* c, Player* p) {
  UnoPlayer* p2 = static_cast<UnoPlayer*>(p);
  p2->getHand()->placeCard(getDiscardPile(), c);
  if (c->getFace() == 10) {
    swapTurnOrder();
  } else if (c->getFace() == 11) {
    nextTurn();
  } else if (c->getFace() == 12) {
    setStackTally(getStackTally() + 2);
  } else if (c->getFace() == 13) {
    setStackTally(getStackTally() + 4);
  } else if (c->getFace() == 14) {
    changeColour(p);
  }
  p2 = nullptr;
}

void Uno::changeColour(Player* p) {
  std::cout << "Change colour flag" << std::endl;
  if (p->getIsHuman()) {
    char colour;
    do {
      std::cout << "What colour would you like?[b, g, r, y]: ";
      std::cin >> colour;
      if (colour != 'b' && colour != 'g' && colour != 'r' && colour != 'y')
        std::cout << "Invalid colour entered! Please try again!" << std::endl;
    } while (colour != 'b' && colour != 'g' && colour != 'r' && colour != 'y');
    setCurrentColour(colour);
  } else {
    std::vector<char> suits = {'b', 'g', 'r', 'y'};
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, suits.size());
    int randInt = dist(mt);
    setCurrentColour(suits[randInt]);
  }
    std::cout << "Changed the colour to ";
    std::string suit;
    switch (getCurrentColour()) {
        case 'b' :
            std::cout << "blue." << std::endl;
            break;
        case 'g' :
            std::cout << "green." << std::endl;
            break;
        case 'r' :
            std::cout << "red." << std::endl;
            break;
        case 'y' :
            std::cout << "yellow." << std::endl;
            break;
    }
}

void Uno::setCurrentColour(char c) {
  currentColour = c;
}

int Uno::returnCardRank(std::string s) {
  if (s == "cc")
    return 14;
  else if (s == "+4")
    return 13;
  else if (s == "+2")
    return 12;
  else if (s == "r ")
    return 11;
  else if (s == "s ")
    return 10;
  else
    return std::stoi(s);
}

void Uno::drawCards(Player* p) {
  UnoCard* topCard;
  char input;
  bool playedCard = false;
  topCard = static_cast<UnoCard*>(getDrawPile()->getTopCard());

  std::cout << "\nDrawing Cards ..." << std::endl;

  if (p->getIsHuman())
    std::cout << "\nDrew a " << topCard->getName() << std::endl;

  p->drawCard(getDrawPile());

  if (getDrawPile()->isEmpty())
    recyclePiles();

  if (isPlayable(topCard)) {
    if (p->getIsHuman()) {
      std::cout << "Would you like to play the card now? [y, n] : ";
      std::cin >> input;
      std::cout << std::endl;

      if (input == 'y') {
        playCard(topCard, p);
        std::cout << "Played the " << topCard->getName() << std::endl;
        playedCard = true;
      }
    } else {
      playCard(topCard, p);
      std::cout << "Played the " << topCard->getName() << std::endl;
      playedCard = true;
    }
  } else {
    if (p->getIsHuman())
      std::cout << "Unable to play drawn card!" << std::endl;
    }
  topCard = nullptr;

  if (playedCard == false)
    std::cout << "Didn't/Couldn't play drawn card! Skipping Turn!" << std::endl;
}

void Uno::createPiles() {
  PileFactory* factory = nullptr;
  drawPile = factory->createPile(PileFactory::UNO);
  discardPile = new Pile();
  getDrawPile()->shuffle();
}

void Uno::swapTurnOrder() {
  reversedTurnOrder = !reversedTurnOrder;
}

void Uno::help() {
  std::cout
    << "====Welcome to Uno!===="
    << "\n====Object===="
    << "\nBe the first player to run out of cards in your hand."
    << "\n====How to play===="
    << "\nPlayers take turns playing one card on the discard pile."
    << "\nCards with the same face, colour, or that are wild can be played on"
    << "\none another."
    << "\nIf a player cannot play a card, they draw one from the draw pile and"
    << "\nmay play it immediately if possible."
    << "\nPlayers must be sure to say 'UNO!' to avoid a 2-card penalty when"
    << "\nthey only have one card left as other player's can call it on them."
    << "\n====Special Cards===="
    << "\nReverse:"
    << "\nReverses the direction of play (play starts clockwise)."
    << "\nSkip:"
    << "\nSkips the player's turn that is next to play."
    << "\nPlus Two:"
    << "\nMakes the player next to play draw 2 cards and also skips their turn."
    << "\nPlus Four:"
    << "\nMakes the player next to play draw 4 cards, skips their turn, and"
    << "\nallows the player who played it to set a different colour of play."
    << "\nChange Colour:"
    << "\nAllows the player to set a different colour of play." << std::endl;
}
