#ifndef __ACADEMIC_H__
#define __ACADEMIC_H__
#include <string>
#include "property.h"

class TextDisplay;
class Player;

class Academic: public Property {
  std::string block;
  int impCost;
  int numImp;
  int tuition[6];
  std::string desc;
public:
  Academic(Board *, TextDisplay *);
  void action();
  void improve(std::string);
  void mortgate();
};
#endif