#include <iostream>
#include "textdisplay.h"
#include <string>
#include "academic.h"
#include <map>
#include "player.h"
#include "playerdata.h"
using namespace std;


Board::Board():td(NULL), theBoard(NULL),numPlayers(), mode("") {
  td = new TextDisplay();
  //remember to set num players later
  theBoard = new Square*[40];
  
  for(int i = 0; i < 40; i++) {
      if(prop[i]) {
          theBoard[i] = new Square;
          makeProperty(i);
      }
      else theBoard[i] = new Square;
      theBoard[i]->setName(names[i]); 
      theBoard[i]->setCoords(this->column(i)*5, this->row(i)*8);
      theBoard[i]->setDisplay(td);
  }
  addPlayer("Goose");
  addPlayer("GRT Bus");
  addPlayer("Tim Hortons Doughnut");
  addPlayer("Professor");
  addPlayer("Student");
  addPlayer("Money");
  addPlayer("Laptop");
  addPlayer("Pink tie");
}

void Board::addPlayer(string name) {
    Player *p = new Player(name);
    p->setDisplay(td);
    if(players.size()>=4) p->setCoords(5*10+players.size()/4+3, 8*10+(players.size()+1)%4+2);
    else p->setCoords(5*10+players.size()/4+3, 8*10+players.size()%4+2);
    players.push_back(p);
    td->addPlayer(playerOptions[name], p->row, p->column);
}
void Board::makeProperty(int i){
    string n = names[i];
    if(aInfo.count(n)) {
        theBoard[i]->setCost(aInfo[n].pCost);
        if(aInfo[n].type == "A") {
            theBoard[i]->setImCost(aInfo[n].imCost);
            theBoard[i]->setBlock(aInfo[n].block);
            for(int j = 0; j < 6; j++) theBoard[i]->setIm(j, aInfo[n].imp[j]);
        }
    }
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
