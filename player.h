#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <iostream>
#include "textdisplay.h"
#include <vector>
#include <string> 
#include "board.h"
#include "square.h"


class Player {
  string name;
  int cups;
  Square *location;
  char avatar;
  Board *board;
  int Savings;
  TextDisplay *td;
  
 public:

  Board();
  ~Board();  

};

#endif
