#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>

class illegal_card_error: public std::runtime_error {
 public:
  explicit illegal_card_error(const char* errMessage) :
  std::runtime_error(errMessage) {
  }
};

class invalid_deck_operation: public std::runtime_error {
 public:
  explicit invalid_deck_operation(const char* errMessage) :
  std::runtime_error(errMessage) {
  }
};

#endif  // EXCEPTIONS_H
