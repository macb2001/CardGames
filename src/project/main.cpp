#include <iostream>
#include "Game.h"
#include "GoFish.h"
#include "Crazy8.h"
#include "Uno.h"

int main() {
  int gameChoice = 0;

  do {
    std::cout << "Shall we play a game?\n"
      << "1. Go Fish\n"
      << "2. Crazy 8's\n"
      << "3. Uno\n"
      << "4. Global Thermonuclear War\n"
      << "> ";
    std::cin >> gameChoice;

    if (gameChoice == 4) {
      std::cout << "Wouldn't you prefer a good"
       << " game of Go Fish?\n" << std::endl;
    }

    if (gameChoice > 4 || gameChoice < 1)
      std::cout << "Invalid Game Choice" << std::endl;
  } while (gameChoice > 3 || gameChoice < 1);

  Game* game = nullptr;
  switch (gameChoice) {
    case 1:
      game = new GoFish();
      break;
    case 2:
      game = new Crazy8();
      break;
    case 3:
      game = new Uno();
      break;
  }
  game->run();

  return 0;
}
