#include "all.h.gch"
#include <sstream>
#include "square.h"
#include "player.h"
#include "textdisplay.h"
#include "data/academic.h"
#include "data/playerdata.h"
#include "data/npdata.h"
#include <string>
#include <algorithm>
#include <stdlib.h>
#include "board.h"
#include <ncurses.h>
using namespace std;

Board::Board():td(NULL), theBoard(NULL),numPlayers(0), mode("") {
  td = new TextDisplay();
  //remember to set num players later
  fillLoop();
  srand(time(0));
  theBoard = new Square*[40];
  for(int i = 0; i < 40; i++) {
      theBoard[i] = new Square;
      theBoard[i]->setName(cNames[i]);
      if(aInfo.count(cNames[i])) {
          makeProperty(i);
      }
      else {
          theBoard[i]->setCost(npInfo[cNames[i]].pCost);
          theBoard[i]->setDesc(npInfo[cNames[i]].desc);
      }
      theBoard[i]->setDisplay(td);
      theBoard[i]->setCoords(spots[i][0], spots[i][1]);
  }

}
void Board::printPlayers() {
    for(int i = 0; i < players.size(); i++) {
        addstr( players[i]->name.c_str() );
    }
}
void Board::addPlayer(string name) {
    addPlayer(name, 'c', 0, 0, 0); 
}
void Board::addPlayer(string name, char avatar, int money, int nT, int pos) {
    if(playerOptions.count(name) == 0) {
            addstr("This player isn't valid");
            return;
    }
    Player *p = new Player(name, td, this, theBoard[pos], pos);
    (players.size() >= 4)? p->setCoords(players.size()/4+3, (players.size()+1)%4+2) : p->setCoords(players.size()/4+3,players.size()%4+2);
    p->savings = money;
    p->cups = nT;
    players.push_back(p);
    td->addPlayer(playerOptions[name].avatar, p->location->row+p->row, p->location->column+p->column);
    playerOptions[name].row = p->row;
    playerOptions[name].column = p->column;
    if(players.size() == 1) activePlayer = players[0];
}
void Board::addProperty(string name, string owner, int imp) {
    getSquare(name)->setOwner(getPlayer(owner));
    getPlayer(owner)->properties.push_back(getSquare(name));
    getSquare(name)->impDatShit(imp);

}
void Board::makeProperty(int i){
    string n = cNames[i];
    theBoard[i]->setCost(aInfo[n].pCost);
    if(aInfo[n].type == "A") {
        theBoard[i]->setImCost(aInfo[n].imCost);
        theBoard[i]->setBlock(aInfo[n].block);
        for(int j = 0; j < 6; j++) theBoard[i]->setIm(j, aInfo[n].imp[j]);
    }
    theBoard[i]->setDesc("This is a property");
}
Player* Board::getNextPlayer(int n) {
    int pos = find(players.begin(), players.end(), activePlayer) - players.begin();
    Player *nP = players.at((pos+n)%players.size());
    return nP;

}
void Board::next() {
   activePlayer = getNextPlayer(1);
   string k = "The next player is now: " +activePlayer->name;
   addstr(k.c_str());
   addch('\n');
}
void Board::movePlayer(int numMoves) {
    int n = (activePlayer->lIndex+numMoves)%40;
    td->movePlayer(activePlayer->lIndex, n, activePlayer->name);
    activePlayer->location = theBoard[n];
    activePlayer->lIndex = n;
}    
Player* Board::getAPlayer() {
    return activePlayer;
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
bool Board::startGame() {
    if(players.size() == 0) {
        addstr("We need at least one player to start the game!" );
        addch('\n');
        return false;
    }
    printPlayers();
    return true;
}
void Board::Roll(){
    int x = rand()%11+2;
//    addstr( "Number rolled: "  x );
    movePlayer(x);
    string l =  "You are at: " +activePlayer->location->getName(); 
    string k =  "Description of location: " +activePlayer->location->getDesc();
   addstr(l.c_str());
   addch('\n');
   addstr(k.c_str());
   addch('\n');
   if(aInfo.count(activePlayer->location->getName())) Buy();
}
void Board::Roll(int num) {
    movePlayer(num);
    refresh();
    if(aInfo.count(activePlayer->location->getName())) Buy();
}
void Board::Buy() {
    //ALL OF THIS WILL BE REPLACED BY TRAVIS CODE. THIS IS FOR DEMO PURPOSES ONLY.
    addstr( "Would you like to buy this property (yes/no)\n" );
    char line[10000];
    string answer;
    getstr(line);
    stringstream ss(line);
    refresh();
    ss >> answer;
    if(answer == "yes") {
        activePlayer->savings = activePlayer->savings - activePlayer->location->getCost();
        activePlayer->location->setOwner(activePlayer);
        activePlayer->properties.push_back(activePlayer->location);
        if(activePlayer->savings <= 0) addstr( "LOL you're in debt\n");
        activePlayer->displayAssets();
    }
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
Square* Board::getSquare(int i) {
    if(theBoard[i]) return theBoard[i];
    throw i;
}
Square* Board::getSquare(string name) {
    for(int i = 0; i < 40; i++) {
        if(name == theBoard[i]->getName()) return theBoard[i];
    }
    throw name;
}
Player* Board::getPlayer(string n) {
    for(vector<Player *>::iterator it=players.begin(); it!=players.end();it++) {
        if((*it)->name == n) return *it;
    }
}
void Board::printBoard() {
    td->printBoard();
}
ostream &operator<<(std::ostream &out, const Board &g){
  out << *(g.td);
  return out;
}