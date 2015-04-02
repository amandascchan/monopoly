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
#include <sstream>
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
	Square *n;
      if(npInfo.count(cNames[i]) == 0) {
//cout << "????? " << cNames[i] << aInfo[cNames[i]].type << endl;
          if(aInfo[cNames[i]].type == "A") {
             Academic *m = new Academic(this, td);
              m->block = aInfo[cNames[i]].block;
              m->impCost = aInfo[cNames[i]].imCost;
              for(int j = 0; j <6; j++) {
                  m->tuition[j] = aInfo[cNames[i]].imp[j];
                  //cout << m->tuition[j] << endl;
              }
		m->price = aInfo[cNames[i]].pCost;
		n = dynamic_cast<Square *>(m);
          }
          else if(aInfo[cNames[i]].type == "R") {
		n = new Residence(this,td);
          }
          else if(aInfo[cNames[i]].type == "G") {
              n = new Gym(this, td);
          }
      }
      else {
//cout << "ewrewjir" << i << endl;
          if(cNames[i] == "SLC") {
	//   cout << "SLC CODE " << i << cNames[i] << endl;
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
//	cout << theBoard[i]->name << i << endl;
  }

}
void Board::printPlayers() {
    for(int i = 0; i < players.size(); i++) {
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

void Board::transfer(Player *counterParty, string offer, string recieve, bool outPut){
  int money;
  bool success = true;
  stringstream offerStream(offer);
  stringstream recieveStream(recieve);
  bool offerIsMoney = false;
  bool recieveIsMoney = false;
  int offerMoney;
  int recieveMoney;
  vector<Property *>::iterator offerIt = activePlayer->properties.begin();
  vector<Property *>::iterator recieveIt = counterParty->properties.begin();

  if (offerStream >> offerMoney){
    offerIsMoney = true;
    if (!(activePlayer->canAfford(offerMoney))) success = false;
  }
  else {
    bool found = false;
    while (offerIt != activePlayer->properties.end()){
      if (offer == (*offerIt)->name){
        found = true;
        break;
      }
      ++offerIt;
    }
    if (!found) success = false;
  }

  if (recieveStream >> recieveMoney){
      recieveIsMoney = true;
    if (!(counterParty->canAfford(recieveMoney))) success = false;
  }
  else {
    bool found = false;
    while(recieveIt != activePlayer->properties.end()){
      if (recieve == (*recieveIt)->name){
        found = true;
        break;
      }
      ++recieveIt;
    }
    if (!found) success = false;
  }

  if (success){
    if (outPut){
      string response;
      cout << activePlayer->name << " is offering to trade " << offer << " for " << recieve << " with " << counterParty->name << " (accept/decline)." << endl;
      while (cin >> response){
        if (response == "accept"){break;}
        else if (response == "decline"){return;}
      }
    }
    if (offerIsMoney){activePlayer->transaction(-offerMoney, counterParty);}
    else {
      (*offerIt)->owner = counterParty;
      counterParty->addProperty(*offerIt);
      // MIGHT CAUSE BUGGGG!!!
      activePlayer->properties.erase(offerIt);
    }
    if (recieveIsMoney){counterParty->transaction(-recieveMoney, activePlayer);}
    else {
      (*recieveIt)->owner = activePlayer;
      activePlayer->addProperty(*recieveIt);
      // MIGHT CAUSE BUGGGG!!!
      counterParty->properties.erase(recieveIt);
    }
  }
  else if (outPut) {
    cout << "Invalid trade." << endl;
  }
}

void Board::trade(string counterPartyName, string offer, string recieve){
  Player *counterParty = getPlayer(counterPartyName);
  transfer(counterParty, offer, recieve, true);
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
}


void Board::addProperty(string name, string owner, int imp) {
 /*   getSquare(name)->setOwner(getPlayer(owner));
    getPlayer(owner)->properties.push_back(getSquare(name));
    getSquare(name)->impDatShit(imp);*/

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
int mod(int a, int b) {
    return (a%b+b)%b;
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
  if(aInfo.count(name)) {
    Property *p = dynamic_cast<Property *>(getSquare(name));
    if (name == p->name){
      p->mortgage();
    }
    else {
      cout << name << " " << p->owner->name << endl;
      cout << "You can not mortgage that which you do not own." << endl;
    }
    return;
  }
  printError(name);
}

void Board::unmortgage(string name) {
  if(aInfo.count(name)) {
    Property *p = dynamic_cast<Property *>(getSquare(name));
    if (name == p->name){
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
  if(aInfo.count(name)) {
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
void Board::transfer(Player *p, int amount) {
  p->savings += amount;
}
