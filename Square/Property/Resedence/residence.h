#ifndef __RESIDENCE_H__
#define __RESIDENCE_H__
#include <string>
#include "property.h"

class TextDisplay;
class Player;

class Residence: public Property {
  std::string block;
  std::string desc;
public:
  Residence(Board *, TextDisplay *);
  void action();
};
#endif