#include <string>
#include "PlayingCard.h"
#include "Exceptions.h"

PlayingCard::PlayingCard(int face, char suit) : Card(face, suit) {
  if (suit != 'c' && suit != 'd' && suit != 'h' && suit != 's')
    throw illegal_card_error("Invalid Suit Value!");
  else if (face > 13 || face < 1)
    throw illegal_card_error("Invalid Face Value!");
}

std::string PlayingCard::getSuitStr() {
  std::string suit;
  switch (getSuit()) {
    case 'c':
      suit = "clubs";
      break;
    case 'h':
      suit = "hearts";
      break;
    case 'd':
      suit = "diamonds";
      break;
    case 's':
      suit = "spades";
      break;
    default:
      throw illegal_card_error("Something somewhere went wrong.");
      break;
  }
  return suit;
}

std::string PlayingCard::getFaceStr() {
  std::string face;
  switch (getFace()) {
    case 1:
      face = "ace";
      break;
    case 2:
      face = "two";
      break;
    case 3:
      face = "three";
      break;
    case 4:
      face = "four";
      break;
    case 5:
      face = "five";
      break;
    case 6:
      face = "six";
      break;
    case 7:
      face = "seven";
      break;
    case 8:
      face = "eight";
      break;
    case 9:
      face = "nine";
      break;
    case 10:
      face = "ten";
      break;
    case 11:
      face = "jack";
      break;
    case 12:
      face = "queen";
      break;
    case 13:
      face = "king";
      break;
    default:
      throw illegal_card_error("Something somewhere went wrong.");
      break;
  }
  return face;
}

std::string PlayingCard::getName() {
  return (getFaceStr() + " of " + getSuitStr());
}

std::string PlayingCard::getSimpleName() {
  std::string output;
  output += getSuit();

  switch (getFace()) {
    case 1:
      output += 'a';
      break;
    case 11:
      output += 'j';
      break;
    case 12:
      output += 'q';
      break;
    case 13:
      output += 'k';
      break;
    default:
      output += std::to_string(getFace());
  }
  return output;
}
