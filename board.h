#ifndef __BOARD_H__
#define __BOARD_H__
#include <iostream>
#include "textdisplay.h"
#include <vector>
#include <string> 
#include "square.h"

class Board {
  int numPlayers;                    // Number of players
  TextDisplay *td;                  // The text display.
  Square **theBoard; 

  // Add private members, if necessary.
  int row(int i);
  int column(int i);
  void makeProperty(int i);


 public:
  std::string mode;
  Square *getSquare(int i);

  Board();
  ~Board();  

  friend std::ostream &operator<<(std::ostream &out, const Board &g);
};

#endif
