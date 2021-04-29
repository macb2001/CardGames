#include <string>
#include <iostream>
#include "UnoCard.h"

UnoCard::UnoCard(int face, char suit) : Card(face, suit) {
  if (suit != 'r' && suit != 'b' && suit != 'g' && suit != 'y' && suit != 'w')
    throw illegal_card_error("Invalid Suit Value!");

  else if (face < 0 || face > 14)
    throw illegal_card_error("Invalid Rank Value!");

  else if ((suit == 'r' || suit == 'b' || suit == 'g' || suit == 'y')
  && face > 12)
    throw illegal_card_error("Invalid Non-Wild Card Value!");

  else if (suit == 'w' && (face != 13 && face != 14))
    throw illegal_card_error("Invalid Wild Card Value!");
}

std::string UnoCard::getSuitStr() {
  std::string colour;
  switch (getSuit()) {
    case 'g':
      colour = "green";
      break;
    case 'b':
      colour = "blue";
      break;
    case 'y':
      colour = "yellow";
      break;
    case 'r':
      colour = "red";
      break;
    case 'w':
      colour = "wild";
      break;
    default:
      throw illegal_card_error("Something somewhere went wrong.");
      break;
  }
  return colour;
}

std::string UnoCard::getFaceStr() {
  std::string face;
  switch (getFace()) {
    case 0:
      face = "zero";
      break;
    case 1:
      face = "one";
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
      face = "skip";
      break;
    case 11:
      face = "reverse";
      break;
    case 12:
      face = "plus two";
      break;
    case 13:
      face = "plus four";
      break;
    case 14:
      face = "change colour";
      break;
    default:
      throw illegal_card_error("Something somewhere went wrong.");
      break;
  }
  return face;
}

std::string UnoCard::getName() {
  return (getSuitStr() + " " + getFaceStr());
}

std::string UnoCard::getSimpleName() {
  std::string output;
  output += getSuit();

  switch (getFace()) {
    case 10:
      output += 's';
      break;
    case 11:
      output += 'r';
      break;
    case 12:
      output += "+2";
      break;
    case 13:
      output += "+4";
      break;
    case 14:
      output += "cc";
      break;
    default:
      output += std::to_string(getFace());
  }
  return output;
}

bool UnoCard::matches(Card* c) {
  if (c -> getFace() == this -> getFace()
    || c -> getSuit() == this -> getSuit()
    || c -> getSuit() == 'w'
    || this -> getSuit() == 'w') {
    return true;
  } else {
    return false;
  }
}
