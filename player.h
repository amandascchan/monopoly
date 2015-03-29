#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <iostream>
#include "textdisplay.h"
#include <vector>
#include <string> 
#include "board.h"
#include "square.h"
#include <map>
class Board;

class Player {
    friend class Board;
  std::string name;
  Square *location;
  std::vector<Square*> properties;
  Board *theBoard;
  TextDisplay *td;
  int cups;
  char avatar;
  int savings;
  int row, column;
  int lIndex;
  std::map<std::string, int>owings;
  int turnsInTimLine;
  bool bankrupt;
  
 public:
  std::string getName();
  Player(std::string name);
  ~Player();  
  void movePlayer(int r, int c); 
  void setCoords(int row, int column);
  void setDisplay(TextDisplay *t);
  Board* getBoard();
  void Bankrupt();
  int getSavings();
  void endTurn();
  bool isBankrupt();

};

#endif
