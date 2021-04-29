//Header file for PlayingCardFactory class.
#ifndef PLAYINGCARDFACTORY_H
#define PLAYINGCARDFACTORY_H

#include "Pile.h"

class PileFactory {
 public:
  PileFactory() {}
  virtual ~PileFactory() {}

  enum TYPE {GOFISH, CRAZY8, UNO};
/*
* @param t The type of Cards to build our Pile from
* @returns a Pile of Cards relevant to the type given
*/
  Pile* createPile(PileFactory::TYPE t);
};

#endif // PLAYINGCARDFACTORY_H
