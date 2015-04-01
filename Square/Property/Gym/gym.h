#ifndef __GYM_H__
#define __GYM_H__
#include <string>
#include "property.h"

class TextDisplay;
class Player;
class Board;

class Gym: public Property {
  std::string desc;
public:
  Gym(Board *, TextDisplay *);
  void action();
};
#endif