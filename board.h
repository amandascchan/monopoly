#pragma once
#ifndef __BOARD_H__
#define __BOARD_H__

class Square;
class Player;
class TextDisplay;
class Board {
  int numPlayers;                    // Number of players
  TextDisplay *td;                  // The text display.
  Square **theBoard; 
  std::vector<Player*> players;
  Player *activePlayer;
  int row(int i);
  int column(int i);
  void makeProperty(int i);
 public:
  std::string mode;
  Square *getSquare(int i);
  void movePlayer(int numMoves);
  void movePlayer(std::string location);
  Player* getNextPlayer(int n);
  void next();
  Player* getAPlayer();
  Square* getSquare(std::string name);
  void addPlayer(std::string name);
  void Buy();
  void printPlayers();
  void Roll();

  Board();
  ~Board();  
  friend std::ostream &operator<<(std::ostream &out, const Board &g);
};

#endif
