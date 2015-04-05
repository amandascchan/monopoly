#pragma once
#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "../all.h.gch"
class TCUP;
class Board;
class Property;
class Square;
class TextDisplay;
class Player {
    friend class Board;
    friend class TCUP;
  std::string name;
  Square *location;
  std::vector<Property*> properties;
  Board *theBoard;
  TextDisplay *td;
  int cups;
  char avatar;
  int savings;
  int row, column;
  int lIndex;
  int turnsInTimLine;
  bool bankrupt;
  Player *creditor;
  int debt;
  bool isInLine;
  
 public:
  std::string getName();
  Player(std::string name, TextDisplay *t, Board *b, Square *l, int lDex);
  ~Player();  
  void movePlayer(int r, int c); 
  void setCoords(int row, int column);
  Board* getBoard();
  void endTurn();
  void displayAssets();
  bool isBankrupt();
  bool ownsBlock(std::string name);
  int getSavings();
  int numRez();
  bool canAfford(int number);
  bool ownsProperty(Property *p);
  void addProperty(Property *p);
  int totalWorth();
  void payDebt();
  bool isInTLine();
  void setTLine(bool);
};

#endif
