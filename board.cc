#include <iostream>
#include "board.h"
#include "textdisplay.h"
#include "square.h"
#include <string>

using namespace std;

Board::Board():td(NULL), theBoard(NULL),numPlayers(0), squares(NULL), mode("") {
  td = new TextDisplay();
  //remember to set num players later
  theBoard = new Square*[11*11];

  for(int i = 0; i < 11*11; i++) {
    theBoard[i] = new Square;
    theBoard[i]->setCoords(this->row(i), this->column(i));
    theBoard[i]->setDisplay(td);
  }
  //set up left and right later
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
  for(int i = 0; i< 11*11;i++) {
    delete theBoard[i];
  }
  delete [] theBoard;
  delete td;
}

/*void Board::init(int r, int c, int state) {
  if(r >= gridSize || c >= gridSize || r < 0 || c < 0) return;
  else {
    theBoard[r*gridSize+c]->setState(state);
  }
}

void Board::change(const int & state) {
  theBoard[0]->notify(state);
}*/
ostream &operator<<(std::ostream &out, const Board &g){
  out << *(g.td);
  return out;
}
