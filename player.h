#pragma once
#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "all.h.gch"
class Board;
class Square;

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
  Player(std::string name, TextDisplay *t, Board *b, Square *l, int lDex);
  ~Player();  
  void movePlayer(int r, int c); 
  void setCoords(int row, int column);
  Board* getBoard();
  void Bankrupt();
  void endTurn();
  void displayAssets();
  bool isBankrupt();
  bool ownsBlock(std::string name);
  int getSavings();
  int numRez();

};

#endif
