#include "all.h.gch"
#include "square.h"
#include "player.h"
#include "textdisplay.h"
#include "data/squaredata.h"
#include "data/playerdata.h"
#include "data/npdata.h"
#include <string>
#include <algorithm>
#include <stdlib.h>
#include "board.h"
using namespace std;

Board::Board():td(NULL), theBoard(NULL),numPlayers(0), mode("") {
  td = new TextDisplay();
  //remember to set num players later
  fillLoop();
  srand(time(0));
  theBoard = new Square*[40];
  for(int i = 0; i < 40; i++) {
      theBoard[i] = new Square;
      if(aInfo.count(cNames[i])) {
          if(aInfo[cNames[i]].type == "A") {
              Square *n = new Academic(this, td);
              n->name = aInfo[cNames[i]].name;
              n->block = aInfo[cNames[i]].block;
              n->impCost = aInfo[cNames[i]].imCost;
              n->price = aInfo[cNames[i]].pCost;
              for(int j = 0; j <6; j++) {
                  n->tuition[j] = aInfo[cNames[j]].imp[j];
              }
          }
          else if(aInfo[cNames[i]].type == "R") {
              Square *n = new Residence(this, td);
          }
          else if(aInfo[cNames[i]].type == "G") {
              Gym *n = new Gym(this, td);
          }
          else {
              

          }
      }
      else {
          theBoard[i]->setCost(npInfo[cNames[i]].pCost);
          theBoard[i]->setDesc(npInfo[cNames[i]].desc);
      }
      theBoard[i]->setCoords(spots[i][0], spots[i][1]);
  }

}
void Board::printPlayers() {
    for(int i = 0; i < players.size(); i++) {
        cout << players[i]->name << endl;
    }
}
void Board::addPlayer(string name) {
    addPlayer(name, 'c', 0, 0, 0); 
}
void Board::addPlayer(string name, char avatar, int money, int nT, int pos) {
    if(playerOptions.count(name) == 0) {
            cerr << "This player isn't valid" << endl;
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
    theBoard[i]->setBlock(aInfo[n].block);
    if(aInfo[n].type == "A") {
        theBoard[i]->setImCost(aInfo[n].imCost);
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
   cout << "The next player is now: " << activePlayer->name << endl;
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
        cerr << "We need at least one player to start the game!" << endl;
        return false;
    }
    printPlayers();
    return true;
}
void Board::Roll(){
    int x = rand()%11+2;
    cout << "Number rolled: " << x << endl;
    movePlayer(x);
   cout << "You are at: " << activePlayer->location->getName() << endl;
   cout << "Description of location: " << activePlayer->location->getDesc() << endl;
   if(aInfo.count(activePlayer->location->getName())) Buy();
}
void Board::Roll(int num) {
    movePlayer(num);
    if(aInfo.count(activePlayer->location->getName())) Buy();
}
void Board::Buy() {
    //ALL OF THIS WILL BE REPLACED BY TRAVIS CODE. THIS IS FOR DEMO PURPOSES ONLY.
    cout << "Would you like to buy this property (yes/no)" << endl;
    string answer;
    cin >> answer;
    if(answer == "yes") {
        activePlayer->savings = activePlayer->savings - activePlayer->location->getCost();
        activePlayer->location->setOwner(activePlayer);
        activePlayer->properties.push_back(activePlayer->location);
        if(activePlayer->savings <= 0) cout << "LOL you're in debt" << endl;
        activePlayer->displayAssets();
    }
}
bool Board::winner() {
  if(players.size() == 1) return true;
  return false;
}
/*void Board::mortage(string name) {
  if(aInfo.count(name)) {
    Property *p = dynamiccaast<Property *>(getSquare(name));
    p->mortgage();
    return;
  }
  printError(name);
}
void Board::unmortgage(string name) {
  if(aInfo.count(name)) {
    Property *p = dynamiccast<Property *>(getSquare(name));
    p->unmortgage();
    return;
  }
  printError(name);
}
void Board::improve(string name, string buyOrSell) {
  if(aInfo.count(name)) {
    if(aInfo[name].type == "A") {
      Academic *p = dynamiccast<Academic *>(getSquare(name));
      p->improve(buyOrSell);
      return;
    }
    cout << name << " cannot be improved" << endl;
  }
  printError(name);
}*/

void Board::printError(string name) {
  cout << name << " does not exist" << endl;
  return;
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
ostream &operator<<(std::ostream &out, const Board &g){
  out << *(g.td);
  return out;
}