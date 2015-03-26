#ifndef __BOARD_H__
#define __BOARD_H__
#include <iostream>
#include "textdisplay.h"
#include <vector>
#include <string> 

class Board {
  Board **theBoard; // The actual n x n grid. 
//  Square **squares;
//  Player *currentActivePlayer;
  int numPlayers;                    // Number of players
//  Vector <Player> **players;
  TextDisplay *td;                  // The text display.
 // Vector <std::String> saveArray;
  

  // Add private members, if necessary.
  int row(int i);
  int column(int i);


 public:
  std::string mode;

  Board();
  ~Board();  

  friend std::ostream &operator<<(std::ostream &out, const Board &g);
};

#endif
