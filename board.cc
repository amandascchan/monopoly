#include <iostream>
#include "textdisplay.h"
#include <algorithm>
#include <string>
#include "academic.h"
#include "npdata.h"
#include <map>
#include "player.h"
#include "playerdata.h"
using namespace std;


Board::Board():td(NULL), theBoard(NULL),numPlayers(), mode("") {
  td = new TextDisplay();
  //remember to set num players later
  fillLoop();
  theBoard = new Square*[40];
  for(int i = 0; i < 40; i++) {
      theBoard[i] = new Square;
      theBoard[i]->setName(cNames[i]);
      if(aInfo.count(cNames[i])) {
          makeProperty(i);
      }
      else {
      }
      theBoard[i]->setDisplay(td);
      theBoard[i]->setCoords(spots[i][0], spots[i][1]);
  }

  addPlayer("Goose");
  addPlayer("GRT Bus");
  addPlayer("Tim Hortons Doughnut");
  addPlayer("Professor");
  addPlayer("Student");
  addPlayer("Money");
  addPlayer("Laptop");
  addPlayer("Pink tie");
  activePlayer = players[0];
}
void Board::printPlayers() {
    for(int i = 0; i < players.size(); i++) {
        cout << players[i]->name << endl;
    }
}
void Board::addPlayer(string name) {
    Player *p = new Player(name);
    p->setDisplay(td);
    p->setCoords(players.size()/4+3, players.size()%4+2);
    p->location = theBoard[0];
    if(players.size()>=4) p->setCoords(players.size()/4+3, (players.size()+1)%4+2);
    players.push_back(p);
    td->addPlayer(playerOptions[name].avatar, p->row, p->column);
    playerOptions[name].row = p->row;
    playerOptions[name].column = p->column;
}
void Board::makeProperty(int i){
    string n = cNames[i];
    theBoard[i]->setCost(aInfo[n].pCost);
    if(aInfo[n].type == "A") {
        theBoard[i]->setImCost(aInfo[n].imCost);
        theBoard[i]->setBlock(aInfo[n].block);
        for(int j = 0; j < 6; j++) theBoard[i]->setIm(j, aInfo[n].imp[j]);
    }
}
Player* Board::getNextPlayer(int n) {
    int pos = find(players.begin(), players.end(), activePlayer) - players.begin();
    Player *nP = players.at((pos+n)%players.size());
    return nP;

}
void Board::movePlayer(int numMoves) {
    int n = (activePlayer->lIndex+numMoves)%40;
    td->movePlayer(activePlayer->lIndex, n, activePlayer->name);
    activePlayer->location = theBoard[n];
    activePlayer->lIndex = n;
}    
void Board::movePlayer(string name) {
    int nI = 0;
    for(int i = 0; i < 40; i++) {
        if(theBoard[i]->getName() == name) {
            nI = i;
            break;
        }
    }
    td->movePlayer(activePlayer->lIndex, nI, activePlayer->name);
    activePlayer->location = theBoard[nI];
    activePlayer->lIndex = nI;
}
int Board::row(int i) {
  int xCoord = i/11;
  return xCoord;
}

int Board::column(int i) {
  int yCoord = i%11;
  return yCoord;
}

Board::~Board() {
  for(int i = 0; i< 40 ;i++) {
    delete theBoard[i];
  }
  for(int i = 0; i < players.size(); i++) {
      delete players[i];
  }
  delete [] theBoard;
  delete td;
}
Square * Board::getSquare(int i) {
    return theBoard[i];
}
ostream &operator<<(std::ostream &out, const Board &g){
  out << *(g.td);
  return out;
}
