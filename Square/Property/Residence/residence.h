#ifndef __RESIDENCE_H__
#define __RESIDENCE_H__
#include <string>
#include "../../square.h"
#include "../property.h"

class TextDisplay;
class Player;
class Board;

class Residence: public Property {
	friend class Board; 
  std::string desc;
public:
  Residence(Board *, TextDisplay *);
  void action();
  int getRent();
};
#endif