#pragma once
#ifndef __BOARD_H__
#define __BOARD_H__

#include <cstdlib>
#include <string>
#include <vector>
#include <map>
class Square;
class Player;
class TextDisplay;
class TCUP;
class Board {
  int numPlayers;                    // Number of players
  TextDisplay *td; 
  static Board *daBoard;
  Square **theBoard; 
  std::vector<Player*> players;
  Player *activePlayer;
  int row(int i);
  int column(int i);
  void printError(std::string name);
  void setAvatar(std::string name, char avatar);
  TCUP *cupD;
  Board(std::map<std::string, bool> );
  static void cleanUp();
 public:
  Player *theGoose;
  std::map<std::string, bool> modeMap;
  Square *getSquare(int i);
  void movePlayer(int numMoves);
  void movePlayer(std::string location);
  Player* getNextPlayer(int n);
  Player* getAPlayer();
  Player* getPlayer(std::string n);
  Square* getSquare(std::string name);
  void next();
  void addPlayer(std::string name, char avatar);
  void addPlayer(std::string name, char a, int money, int nT, int pos, bool inLine, int jailTime);
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
  void trade(std::string, std::string, std::string, bool);
  void save(std::string name);
  void loadBoard(std::string loadFile);
  void giveProperty(std::string propName, std::string playerName, int numImp);
  void giveJailTime();
  void giveTCup();
  bool returnTCup();
  void giveMoney(Player *p, int amount);
  void giveDebt(Player *p, int amount, Player *c);
  void inTLine(int r1, int r2);
  static Board *getDaBoard(std::map<std::string, bool> modeMap);
  ~Board();  
  friend std::ostream &operator<<(std::ostream &out, const Board *g);
};

#endif
