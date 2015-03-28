#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <iostream>
#include "textdisplay.h"
#include <vector>
#include <string> 
#include "board.h"
#include "square.h"

class Board;

class Player {
    friend class Board;
    std::string name;
  int cups;
  Square *location;
  char avatar;
  Board *theBoard;
  int savings;
  TextDisplay *td;
  int row, column;
  
 public:
  std::string getName();
  Player(std::string name);
  ~Player();  
  void movePlayer(int r, int c); 
  void setCoords(int row, int column);
  void setDisplay(TextDisplay *t);

};

#endif
