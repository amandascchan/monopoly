#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "academic.h"

class TextDisplay {
  char **theDisplay;          //the n x n display 
  std::vector<char>players;
  void drawBox(int row, int column, std::string name, bool property);
  void init();
 public:
  TextDisplay(); //one arg constructor where the parameter is the gridSize
  void addPlayer(char player);

  void notify(int r, int c, char ch);  

	
  ~TextDisplay(); //dtor

  friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
