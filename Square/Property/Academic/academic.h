#ifndef __SQUARE_H__
#define __SQUARE_H__
#include <string>
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
  action();
  improve(std::string);
  mortgate();
};
#endif