#include "GoFish.h"
#include "Pile.h"
#include "Card.h"
#include "GoFishCard.h"
#include "GoFishPlayer.h"
#include "PileFactory.h"
#include <iostream>
#include <string>
#include <random>
#include <cctype>

void GoFish::run() {
  help();
  initialize();
  round(); // maybe make this a bool function for looping
}

void GoFish::initialize() {
  // Create go fish deck from pile factory
  std::string name;
  std::cout << "\nSetting up players ...\nPlease enter your name: ";
  std::cin >> name;

  //Adding user player.
  players.push_back(new GoFishPlayer(name, true));

  //Adding CPU Players
  int CPUPlayers;

  while (CPUPlayers < 1 || CPUPlayers > 4) {
    std::cout << "\nHow many CPU players would you like? [1-4] : ";
    std::cin >> CPUPlayers;

    // Feedback to user that they gave an invalid input
    if (CPUPlayers < 1 || CPUPlayers > 4) {
      std::cout << "Invalid Number of CPU Players Inputted! Please Try Again!"
      << std::endl;
    }
  }
  //Adding CPU Players to game
  setPlayerNum(CPUPlayers);

  //Creating Piles
  std::cout << "\nCreating Piles ..." << std::endl;
  PileFactory factory;
  drawPile = factory.createPile(PileFactory::GOFISH);

  // Shuffle draw pile
  drawPile->shuffle();

  // Create discard pile
  discardPile = new Pile();

  std::cout << "Dealing Hands ..." << std::endl;
  // Deal cards (changes depending on number of players)
  if (getNumOfPlayers() > 3) {
    deal(5);
  } else {
    deal(7);
  }
}

void GoFish::round() {
  // Restore piles for round and shuffle them
  while (discardPile->getSize() > 0) {
    drawPile->takeCard(discardPile, discardPile->getTopCard());
  }
  drawPile->shuffle();

  // Start turn loop
  isWinner = false;
  while (!isWinner) {
    takeTurn(players[getTurn()]);
  }

  // Tally up the remaining player pairs
  static_cast<GoFishPlayer*>(players[0])->makeAllPairs(getDiscardPile());

  // Display user scores
  GoFishPlayer* winner = static_cast<GoFishPlayer*>(players[0]);
  for (Player* pIter : players) {
    GoFishPlayer* p = static_cast<GoFishPlayer*>(pIter);
    std::cout << p->getName() << ": " << p->getPairs() << std::endl;
    if (p->getPairs() > winner->getPairs()) {
      winner = p;
    }
  }
  std::cout << "\n------------------" << std::endl
    << "Winner: " << winner->getName() << std::endl;
}

void GoFish::takeTurn(Player* p) {
  GoFishPlayer* p1 = static_cast<GoFishPlayer*>(p);
  // Distinguish between human and non human
  std::cout << "\n" << p1 -> getName() << "'s Turn! : " << p1 -> getPairs()
    << " pairs" << std::endl;
  if (p1->getIsHuman()) {
    playerInput(p1);
  } else {
    cpuInput(p1);
  }

  // --End of turn-- //
  // Check for pairs

  if (getDrawPile()->isEmpty()) {
    isWinner = true;
  }
  p1 = nullptr;
  nextTurn();
}

void GoFish::help() {
  std::cout
    << "====Welcome to GoFish!===="
    << "\n====Object===="
    << "\nTo have the most pairs at the end of the game."
    << "\n====How to play===="
    << "\nThe game uses a standard, 52-card deck with each players receiving"
    << "\n7 cards (if 2-3 players) or 5 cards (if 4-5 players)"
    << "\nPairs are any two cards in a player's hand that have the same rank"
    << "\nPairs are taken out of the player's hand and set aside when made."
    << "\nPlayers immedietely attempt to pair any cards in their hand"
    << "\nPlayers then take turns asking one another for a card of a rank they"
    << "\nhope to make a pair with."
    << "\nIf a player has the requested rank in their hand, they must give it"
    << "\nto the player."
    << "\nIf a player does not have the requested rank in their hand, the"
    << "\nthe player making the request must 'GoFish' and take a card from the"
    << "\ndraw pile."
    << "\nThe game ends when the draw pile becomes empty."
    << "\nEach player's amount of pairs is calculated, revealing the winner."
    << "\nThese are the available commands:"
    << "\n1. help : returns this menu"
    << "\n2. status : returns all the players, their number of pairs, your hand"
    << "\n, and your number of pairs"
    << "\n3. pair : identifies and collects pairs in your hand (make sure to do"
    << "\nthis command when starting to identify all initial pairs)."
    << "\n4. ask : ask another player for a card."
  << std::endl;
}

void GoFish::playerInput(Player* player) {
  // Display hand at the start of a player's turn
  std::cout << "\n====Your hand====\n"
    << player->getHand()->displayHand() << std::endl;

  GoFishPlayer* p = static_cast<GoFishPlayer*>(player);
  bool validCommand = false;
  while (!validCommand) {
    // prompt user for input
    std::cout << "\nYour turn: ";
    std::string userInput;
    std::cin >> userInput;

    // --Execute commands-- //

    if (userInput == "help") {
      help();

    } else if (userInput == "status") {
        for (auto p2 : players) {
          GoFishPlayer* p3 = static_cast<GoFishPlayer*>(p2);
          std::cout << p3 -> getName() << " : " << p3 -> getPairs() << " pairs"
            << std::endl;
          p3 = nullptr;
        }
        std::cout << "\n====Your Hand====\n" << p->getHand()->displayHand()
          << std::endl;

    } else if (userInput == "pair") {
      p->makeAllPairs(getDiscardPile());

    } else if (userInput == "ask") {
      std::cout << "which player would you like to take from? ["
        << displayPlayers() << "] : ";
      std::cin >> userInput;
      for (Player* x : players) {
        GoFishPlayer* opponent = static_cast<GoFishPlayer*>(x);
        if (opponent->getName() == userInput) {
          std::cout << "what rank of card would you like? : ";
          std::cin.ignore();
          std::cin >> userInput;

          if (userInput.length() != 1 && userInput != "10") {
            std::cout << "Congrats, you just lost a turn." << std::endl
            << "Next time, only enter the face of a card you want." << std::endl
            << std::endl;

            continue;
          }


        if (isalpha(userInput[0])) {
          userInput = tolower(userInput[0]);
          // Fix for letter inputs
          if (userInput == "j") {
            userInput = "11";
          } else if (userInput == "q") {
            userInput = "12";
          } else if (userInput == "k") {
            userInput = "13";
          } else if (userInput == "a") {
            userInput = "1";
          } else {
            std::cout << "Congrats, you just lost a turn. " << std::endl
            << userInput << " isn't a real face, silly." << std::endl
            << std::endl;

            continue;
          }
        }

          int targetFaceVal = std::stoi(userInput);
          if (!opponent->hasCard(targetFaceVal)) {
            // Go fish logic, make p draw card.
            std::cout << "go fish." << std::endl;
            p->drawCard(getDrawPile());
          } else {
            std::cout << "yeah, here..." << std::endl;
            p->getHand()->takeCard(
              opponent->getHand(),
              opponent->getHand()->findFace(targetFaceVal));
          }
        }
        opponent = nullptr;
      }
      validCommand = true;

    } else {
      std::cout << "=== Invalid command ===" << std::endl;
    }
  }
  p = nullptr;
}

void GoFish::cpuInput(Player* p) {
  // Initialize necessary perimeters
  GoFishPlayer* tPlayer = static_cast<GoFishPlayer*>(getRandPlayer());
  GoFishPlayer* bPlayer = static_cast<GoFishPlayer*>(p);

  bool takeOutTheTrash = false;

  Card* targetCard;
  // Make sure the hand isn't empty
  if (!p->getHand()->isEmpty()) {
    targetCard = bPlayer->getHand()->getRandomCard();

  } else {
    // Spoof a card if there's nothing else
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 13);

    targetCard = new PlayingCard(dist(mt), 's');
    takeOutTheTrash = true;
  }

  int targetFaceVal = targetCard->getFace();
  int targetFaceName = targetCard->getFace();

  std::cout << bPlayer->getName() << "> " << tPlayer->getName()
    << " do you have any "
    << targetCard->getFaceStr() << "s?" << std::endl;

  // Determine whether has card or not
  std::cout << tPlayer->getName() << "> ";
  if (!tPlayer->hasCard(targetFaceVal)) {
    // Go fish logic, make p draw card.
    std::cout << "\nToo Bad! Go Fish!\n" << std::endl;
    bPlayer->drawCard(getDrawPile());
  } else {
    std::cout << "\nLucky!\n" << std::endl;
    bPlayer->getHand()->takeCard(
        tPlayer->getHand(), tPlayer->getHand()->findFace(targetFaceVal));
  }

  // Check for garbadge
  if (takeOutTheTrash) {
    delete targetCard;
  }

  // Pair up all the pairs they have
  int previousPairs = bPlayer->getPairs();
  bPlayer->makeAllPairs(getDiscardPile());
  if (bPlayer->getPairs() > previousPairs) {
    std::cout << "[" << bPlayer->getName() << " got +"
      << (bPlayer->getPairs() - previousPairs)
      << " pairs, now totalling: " << bPlayer->getPairs() << "]" << std::endl;
  }
}

void GoFish::setPlayerNum(int p) {
  for (int i = 0; i < p; i++) {
    players.push_back(
      new GoFishPlayer("CPU" + std::to_string(i + 1), false));
  }
}
