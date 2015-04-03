#pragma once
#ifndef __BOARD_H__
#define __BOARD_H__

#include <string>
#include <vector>
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
  void printError(std::string name);
 public:
  std::string mode;
  Square *getSquare(int i);
  void movePlayer(int numMoves);
  void movePlayer(std::string location);
  Player* getNextPlayer(int n);
  Player* getAPlayer();
  Player* getPlayer(std::string n);
  Square* getSquare(std::string name);
  void next();
  void addPlayer(std::string name);
  void addPlayer(std::string name, char a, int money, int nT, int pos);
  void Buy();
  void printPlayers();
  void Roll(int num);
  void transfer(Player *p, int amount);
  void addProperty(std::string name, std::string owner, int imp);
  void improve(std::string name, std::string buyOrSell);
  void mortgage(std::string name);
  void unmortgage(std::string name);
  bool startGame();
  bool winner();
  int getNumPlayers() { return players.size(); }
  void bankrupt();
  void trade(std::string, std::string, std::string);
  void transfer(Player *, std::string, std::string);
  void save(std::string name);
  
  Board();
  ~Board();  
  friend std::ostream &operator<<(std::ostream &out, const Board &g);
};

#endif
