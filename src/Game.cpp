#include "Game.h"
#include "Player.h"
#include "Pile.h"
#include <string>
#include <vector>
#include <random>

Game::~Game() {
  for (Player* p : players) {
    delete p;
    p = nullptr;
  }

  delete drawPile;
  delete discardPile;
}

void Game::deal(int n) {
  for (auto p : players)
    p -> drawCard(drawPile, n);
}

void Game::nextTurn() {
  // Increments the turn depending on turn order
  if (!reversedTurnOrder) {
    turn += 1;
  } else {
    turn -= 1;
  }
  // Trying to get math mod
  turn = ((turn) % getNumOfPlayers() + getNumOfPlayers()) % getNumOfPlayers();
}


int Game::getNumOfPlayers() {
  return players.size();
}

Player* Game::getRandPlayer() {
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist(0, getNumOfPlayers() - 1);
  int randInt = dist(mt);

  // Makes sure not to return the player who's turn it is
  if (randInt < getTurn()) {
    return players[randInt];
  } else {
    return players[randInt + 1];
  }
  return players[randInt];
}

Pile* Game::getDrawPile() {
  return drawPile;
}

Pile* Game::getDiscardPile() {
  return discardPile;
}

int Game::getTurn() {
  return turn;
}

std::string Game::displayPlayers() {
    std::string output = "|";
    for (int i = 0; i < players.size(); i++) {
        output += players[i]->getName();
        output += "|";
    }

    return output;
}

std::vector<Player*> Game::getPlayers() {
  return players;
}
