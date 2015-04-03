#include "../all.h.gch"
#include "../Square/square.h"
#include "../Square/NonProperty/collectOSAP.h"
#include "../Square/NonProperty/coopFee.h"
#include "../Square/NonProperty/needlesHall.h"
#include "../Square/NonProperty/goToTimsLine.h"
#include "../Square/NonProperty/tuition.h"
#include "../Square/NonProperty/nonproperty.h"
#include "../Square/NonProperty/gooseNest.h"
#include "../Square/NonProperty/SLC.h"
#include "../Square/NonProperty/timsLine.h"
#include "../Square/NonProperty/nonproperty.h"
#include "../Square/Property/property.h"
#include "../Square/Property/Gym/gym.h"
#include "../Square/Property/Academic/academic.h"
#include "../Square/Property/Residence/residence.h"
#include "../Player/player.h"
#include "../TextDisplay/textdisplay.h"
#include "../data/squaredata.h"
#include "../data/playerdata.h"
#include "../data/npdata.h"
#include <string>
#include <algorithm>
#include <stdlib.h>
#include "board.h"
#include <fstream>
using namespace std;

Board::Board():numPlayers(0), td(NULL), theBoard(NULL), mode("") {
  td = new TextDisplay();
  //remember to set num players later
  fillLoop();
  srand(time(0));
  theBoard = new Square*[40];
  for(int i = 0; i < 40; i++) {
      Square *n;
      if(npInfo.count(cNames[i]) == 0) {
          if(aInfo[cNames[i]].type == "A") {
              n = new Academic(this, td);
              dynamic_cast<Academic *>(n)->block = aInfo[cNames[i]].block;
              dynamic_cast<Academic *>(n)->impCost = aInfo[cNames[i]].imCost;
              for(int j = 0; j <6; j++) dynamic_cast<Academic *>(n)->tuition[j] = aInfo[cNames[i]].imp[j];
		     dynamic_cast<Academic *>(n)->price = aInfo[cNames[i]].pCost;
          }
          else if(aInfo[cNames[i]].type == "R") {
              n = new Residence(this,td);
          }
          else if(aInfo[cNames[i]].type == "G") {
              n = new Gym(this, td);
          }
      }
      else {
          if(cNames[i] == "SLC") {
              n = new SLC(this, td);
          }
          else if(cNames[i] == "NEEDLES HALL") {
              n = new NeedlesHall(this, td);
          }
          else if(cNames[i] == "GO TO TIMS") {
              n = new GoToTimsLine(this, td);
          }
          else if(cNames[i] == "DC Tims Line") {
              n = new TimsLine(this,td);
          }
          else if(cNames[i] == "TUITION") {
              n = new Tuition(this,td);
          }
          else if(cNames[i] == "Goose Nesting") {
              n = new GooseNest(this, td);
          }
          else if(cNames[i] == "COOP FEE") {
              n = new CoopFee(this, td);
          }
          else if(cNames[i] == "COLLECT OSAP") {
              n = new CollectOSAP(this, td);
          }
          //n->desc = npInfo[cNames[i]].desc;
      }
      n->name = cNames[i];
      n->setPosition(spots[i][0], spots[i][1]);
      theBoard[i] = n;
  }
}
void Board::printPlayers() {
    for(unsigned int i = 0; i < players.size(); i++) {
        cout << players[i]->name << endl;
        cout << players[i]->location->name << endl;
    }
}
void Board::addPlayer(string name) {
    addPlayer(name, 'c', 1500, 0, 0); 
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

void Board::transfer(Player *counterparty, string offer, string recieve){

}


void Board::trade(string counterparty, string offer, string recieve){


}

void Board::bankrupt() {
  activePlayer->bankrupt = true;
  if (activePlayer->creditor == NULL){
    for (vector<Property *>::iterator it = activePlayer->properties.begin(); it != activePlayer->properties.end(); ++it){
      (*it)->auction();
    }
  }
  else {
    for (vector<Property *>::iterator it = activePlayer->properties.begin(); it != activePlayer->properties.end(); ++it){
      if ((*it)->isMortgaged){
        transfer(activePlayer->creditor,(*it)->name, "0");
        cout << activePlayer->name << " is inheriting a mortgaged property named " << (*it)->name << "you must immediatly either unmortgage it, or pay 10 percent of the principle (unmortgage/pay)" << endl;
        string response;
        while (cin >> response){
          if (response == "unmortgage"){
            (*it)->unMortgage();
          } else if (response == "pay") {
              int fee = (1.1*(*it)->getCost())/2; 
              activePlayer->creditor->transaction(-fee, NULL);
          }
        }
      }
    }
 }
  Player *p = getNextPlayer(-1);
  int pos = find(players.begin(), players.end(), activePlayer) - players.begin();
  td->removePlayer(activePlayer->name, activePlayer->location->row, activePlayer->location->column);
  players.erase(players.begin()+pos);
  activePlayer = p;
  next();
}
int mod(int a, int b) {
    return (a%b+b)%b;
}
void Board::addProperty(string name, string owner, int imp) {
 /*   getSquare(name)->setOwner(getPlayer(owner));
    getPlayer(owner)->properties.push_back(getSquare(name));
    getSquare(name)->impDatShit(imp);*/

}
Player* Board::getNextPlayer(int n) {
    int pos = find(players.begin(), players.end(), activePlayer) - players.begin();
    Player *nP = players.at(mod((pos+n), players.size()));
    return nP;

}
void Board::next() {
   activePlayer = getNextPlayer(1);
   cout << "The next player is now: " << activePlayer->name << endl;
}
void Board::movePlayer(int numMoves) {
    int n = mod(activePlayer->lIndex+numMoves, 40);
cout << activePlayer->lIndex << "lol" << numMoves << endl;
    td->movePlayer(activePlayer->lIndex, n, activePlayer->name);
    activePlayer->location = theBoard[n];
    activePlayer->lIndex = n;
    activePlayer->displayAssets();
    activePlayer->location->action();
    activePlayer->displayAssets();
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
void Board::Roll(int num) {
   cout << "Number rolled: " << num << endl;
    movePlayer(num);
}
bool Board::winner() {
  if(players.size() == 1) return true;
  return false;
}
void Board::mortgage(string name) {
  if(npInfo.count(name) == 0) {
    Property *p = dynamic_cast<Property *>(getSquare(name));
    if (getAPlayer()->ownsProperty(p)){
      p->mortgage();
    }
    else {
      //cout << name << " " << p->owner->name << endl;
      cout << "You can not mortgage that which you do not own." << endl;
    }
    return;
  }
  printError(name);
}

void Board::unmortgage(string name) {
  if(npInfo.count(name) == 0) {
    Property *p = dynamic_cast<Property *>(getSquare(name));
    if (getAPlayer()->ownsProperty(p)){
      p->unMortgage();
    }
    else {
      cout << "You can not unmortgage that which you do not own." << endl;
    }
    return;
  }
  printError(name);
}

void Board::improve(string name, string buyOrSell) {
  if(npInfo.count(name) == 0) {
    if(aInfo[name].type == "A") {
      Academic *p = dynamic_cast<Academic *>(getSquare(name));
      if(p->owner == getAPlayer()) p->improve(buyOrSell);
      else cout << "Dis ain't yo property" << endl;
      return;
    }
    cout << name << " cannot be improved" << endl;
  }
  printError(name);
}

void Board::printError(string name) {
  cout << name << " does not exist or is not a Property" << endl;
  return;
}

Board::~Board() {
  for(int i = 0; i< 40 ;i++) {
    delete theBoard[i];
  }
  for(unsigned int i = 0; i < players.size(); i++) {
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
    throw;
}
ostream &operator<<(std::ostream &out, const Board &g){
  out << *(g.td);
  return out;
}
void Board::transfer(Player *p, int amount) {
  p->savings += amount;
}
void Board::save(string name) {
    ofstream outFile(name.c_str());
    outFile << players.size()  << "\n";
    int pos = find(players.begin(), players.end(), activePlayer) - players.begin();
    int k = 0;
    for(unsigned int i = pos; i< pos + players.size(); i++) {
        if(i >= players.size()) k = players.size();
        outFile << players[i - k]->name << " " << players[i-k]->avatar << " " << players[i-k]->savings << " " << players[i-k]->cups << " " << players[i-k]->location->getName() << "\n";
    }
    for(unsigned int i = 0; i < 40; i++) {
        string own = (dynamic_cast<Property*>(theBoard[i]) && dynamic_cast<Property*>(theBoard[i])->owner)? dynamic_cast<Property *>(theBoard[i])->owner->name : "BANK";
        int numI = (dynamic_cast<Academic*>(theBoard[i]))? (dynamic_cast<Property*>(theBoard[i])->isMortgaged)? -1 : dynamic_cast<Academic *>(theBoard[i])->numImp : 0;
        outFile << theBoard[i]->getName() << " " << own << " " << numI << "\n";
    }
    outFile.close();
    return;
}
