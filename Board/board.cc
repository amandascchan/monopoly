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
#include "../TCUP/tcup.h"
#include <string>
#include <sstream>
#include <algorithm>
#include <stdlib.h>
#include "board.h"
#include <fstream>
#include <cstdlib>
#include <stdexcept>
using namespace std;

Board *Board::daBoard =NULL;

Board::Board(map<string, bool> modeMap):numPlayers(0), theGoose(NULL), td(NULL), theBoard(NULL), modeMap(modeMap){
  td = new TextDisplay();
 cupD = new TCUP(); 
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
      if (modeMap.count("goose")) theGoose = new Player("Goose", NULL, this, NULL, 0);
      n->name = cNames[i];
      n->setPosition(spots[i][0], spots[i][1]);
      n->index = i;
      theBoard[i] = n;
  }
}

void Board::cleanUp(){
  delete daBoard;
}


Board *Board::getDaBoard(std::map<std::string, bool> modeMap){
  if (daBoard == NULL){
    daBoard = new Board(modeMap);
    atexit(cleanUp);
  }
  return daBoard;
}


void Board::printPlayers() {
    for(unsigned int i = 0; i < players.size(); i++) {
        cout << players[i]->name << endl;
        cout << players[i]->location->name << endl;
    }
}

void Board::loadBoard(std::string loadFile){
  fstream loadStream(loadFile.c_str());
  string line;
  stringstream lineStream;
  loadStream >> numPlayers;
  getline(loadStream, line);
  for (int i = 0; i < numPlayers; ++i){
    getline(loadStream, line);
    stringstream lineStream(line);
    string namePart;
    lineStream >> namePart;
    string name = namePart;
    char avatar;
    int money;
    int timsCups;
    int pos;
    int jailTime = 2;
    lineStream >> namePart;
    while (namePart.length() != 1){
      name += " " + namePart;
      lineStream >> namePart;
    }
    avatar = namePart[0];
    lineStream >> timsCups >> money >> pos;
    bool inLine = false;
    if(lineStream >> inLine) lineStream >> jailTime;
   // cout << name << avatar << timsCups << money << pos << jailTime << endl;
    addPlayer(name, avatar, money, timsCups, pos, inLine, jailTime);
  }
  
  while (getline(loadStream, line)){
    string propName;
    int numImp;
    stringstream lineStream(line);
    lineStream >> propName;
    string namePart;
    lineStream >> namePart;
    string name = namePart;
    while (!(lineStream >> numImp)){
      lineStream.clear();
      lineStream >> namePart;
      name += " " + namePart;
    }
    cout << name << propName << numImp << endl;
    giveProperty(propName, name, numImp);
  }
}

void Board::giveProperty(string propName, string playerName, int numImp){
  Player *player = getPlayer(playerName);
  Property *prop = dynamic_cast<Property *>(getSquare(propName));
  if ((prop != NULL)&&(player != NULL)){
    if (numImp == -1){prop->isMortgaged = true;}
      Academic *acadP = dynamic_cast<Academic *>(prop);
      if (acadP != NULL){
        if (numImp != -1){
          acadP->numImp = numImp;
          td->addImprov(acadP->row, acadP->column, numImp);
        }
      }
      prop->owner = player;
      player->addProperty(prop);
  }
}
void Board::setAvatar(string name, char avatar) {
 for(map<string, PlayerData>::iterator it = playerOptions.begin(); it!=playerOptions.end();++it) {
     if(it->second.avatar == avatar) {
         playerOptions[it->first].name = name;
         PlayerData newNode = {playerOptions[it->first].name, avatar, playerOptions[it->first].row, playerOptions[it->first].column};
         playerOptions.erase(it);
         playerOptions[name] = newNode;
         return;
     }
 }
 throw invalid_argument("avatar not found");
}
void Board::addPlayer(string name, char avatar) {
  int money = 1500;
  if ((modeMap.count("Bruce Wayne"))&&(name == "Bruce Wayne")){money *=10;}
  addPlayer(name, avatar, money, 0, 0, false, 2);
  if (money != 1500){
    giveProperty("MC", "Bruce Wayne", 0);
    giveProperty("DC", "Bruce Wayne", 0);
  }
}
void Board::addPlayer(string name, char avatar, int money, int nT, int pos,bool inLine, int jailTime) {
    setAvatar(name, avatar);
    Player *p = new Player(name, td, this, theBoard[pos], pos);
    (players.size() >= 4)? p->setCoords(players.size()/4+3, (players.size()+1)%4+2) : p->setCoords(players.size()/4+3,players.size()%4+2);
    p->savings = money;
    for(int i  = 0; i < nT; i++) {
        cupD->giveCup(p);
    }
    p->isInLine = inLine;
    p->turnsInTimLine = jailTime;
    players.push_back(p);
    td->addPlayer(playerOptions[name].avatar, p->location->row+p->row, p->location->column+p->column);
    playerOptions[name].row = p->row;
    playerOptions[name].column = p->column;
    if(players.size() == 1) activePlayer = players[0];
}

void Board::trade(string counterPartyName, string offer, string recieve, bool outPut){
  Player *counterParty = getPlayer(counterPartyName);
  if (counterParty == activePlayer){
    cout << "You cant trade with your self" << endl;
    return;}
  if (counterParty == NULL){
    if (outPut){
      cout << "Invalid trade." << endl;
    }
    return;
  }
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
    while(recieveIt != counterParty->properties.end()){
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
    Property *offerProperty;
    Property *recieveProperty;
    if (!recieveIsMoney){recieveProperty = *recieveIt;}
    if (!offerIsMoney){offerProperty = *offerIt;}
    if (offerIsMoney){giveDebt(activePlayer, offerMoney, counterParty);}
    else {
     // cout << (*offerIt)->name << endl;
      (*offerIt)->owner = counterParty;
      // MIGHT CAUSE BUGGGG!!!
      activePlayer->properties.erase(offerIt);
    }
    if (recieveIsMoney){giveDebt(counterParty, recieveMoney, activePlayer);}
    else {
    //  cout << "why" << endl;
      (*recieveIt)->owner = activePlayer;
      // MIGHT CAUSE BUGGGG!!!
      counterParty->properties.erase(recieveIt);
    }
  if (!(offerIsMoney)){counterParty->addProperty(offerProperty);}
  if (!(recieveIsMoney)){activePlayer->addProperty(recieveProperty);}
  }
  else if (outPut) {
    cout << "Invalid trade." << endl;
  }
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
      Property *theProperty = *it;
      theProperty->owner = activePlayer->creditor;
      activePlayer->creditor->addProperty(theProperty);
      if (theProperty->isMortgaged){
        cout << activePlayer->creditor->name << " is inheriting a mortgaged property named " << theProperty->name << " you must immediatly either unmortgage it, or pay 10 percent of the principle (unmortgage/pay)" << endl;
        string response;
        while (cin >> response){
          if (response == "unmortgage"){
            theProperty->unMortgage();
            break;
          } else if (response == "pay") {
              int fee = (1.1*theProperty->getCost())/2;
              giveDebt(activePlayer->creditor, fee, NULL);
              break;
          }
        }
      }
    }
 }
  Player *p = getNextPlayer(-1);
  int pos = find(players.begin(), players.end(), activePlayer) - players.begin();
  td->removePlayer(activePlayer->name, activePlayer->location->row, activePlayer->location->column);
  players.erase(players.begin()+pos);
  delete activePlayer;
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
    if(((numMoves + activePlayer->lIndex > 40)||(numMoves + activePlayer->lIndex < 0))&&(activePlayer->lIndex !=0)) getSquare(0)->action();
    int n = mod(activePlayer->lIndex+numMoves, 40);
  //  cout << activePlayer->lIndex << "lol" << numMoves << endl;
    td->movePlayer(activePlayer->lIndex, n, activePlayer->name);
    activePlayer->location = theBoard[n];
    activePlayer->lIndex = n;
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
    if(nI == 39) {
        cout << "Error, wrong name" << endl;
        return;
    }
    td->movePlayer(activePlayer->lIndex, nI, activePlayer->name);
    activePlayer->location = theBoard[nI];
    activePlayer->lIndex = nI;
    activePlayer->location->action();
   // activePlayer->displayAssets();
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
  delete theGoose;
  for(int i = 0; i< 40 ;i++) {
    delete theBoard[i];
  }
  for(unsigned int i = 0; i < players.size(); i++) {
      delete players[i];
  }
  delete [] theBoard;
  delete td;
  delete cupD;
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
    return NULL;
}
ostream &operator<<(std::ostream &out, const Board *g){
  out << *(g->td);
  return out;
}
void Board::giveMoney(Player *p, int amount) {
  if(p){
    p->savings += amount;
    if (p->debt){
      p->payDebt();
    }
  }
}

void Board::giveDebt(Player *p, int amount, Player *c) {
  if (p != NULL){
    if (amount > 0){
      p->debt = amount;
      if(c) p->creditor = c;
      p->payDebt();
    }
  }
}

void Board::save(string name) {
    ofstream outFile(name.c_str());
    outFile << players.size()  << "\n";
    int pos = find(players.begin(), players.end(), activePlayer) - players.begin();
    int k = 0;
    for(unsigned int i = pos; i< pos + players.size(); i++) {
        if(i >= players.size()) k = players.size();
        Player *curr = players[i-k];
        outFile << players[i - k]->name << " " << players[i-k]->avatar << " " << players[i-k]->cups << " " << players[i-k]->savings <<" " << players[i-k]->location->index;
        if(curr->location->index != 10) {
            outFile <<  "\n";
        }
        else {
            if(!curr->isInLine) {
                outFile <<" "  << 0 << endl; 
            }
            else if(curr->isInLine) {
                outFile << " " << 1 << " " << curr->turnsInTimLine << endl;
            }
        }
    }
    for(unsigned int i = 0; i < 40; i++) {
        if(npInfo.count(cNames[i]) == 0) {
            string own = (dynamic_cast<Property*>(theBoard[i]) && dynamic_cast<Property*>(theBoard[i])->owner)? dynamic_cast<Property *>(theBoard[i])->owner->name : "BANK";
            int numI = (dynamic_cast<Property*>(theBoard[i]))? (dynamic_cast<Property*>(theBoard[i])->isMortgaged)? -1 : (dynamic_cast<Academic *>(theBoard[i]))? dynamic_cast<Academic *>(theBoard[i])->numImp : 0 : 0;
            outFile << theBoard[i]->getName() << " " << own << " " << numI << "\n";
        }
    }
    outFile.close();
    return;
}
void Board::giveJailTime() {
  activePlayer->isInLine = true;
  activePlayer->turnsInTimLine--;
  cout << "turns in T Line: " << activePlayer->turnsInTimLine << endl;
}

void Board::giveTCup() {
    cupD->giveCup(activePlayer);
    return;
}
bool Board::returnTCup() {
    if(activePlayer->cups == 0) return false;
    else {
        cupD->returnCup(activePlayer);
        return true;
    }
}
void Board::inTLine(int r1, int r2) {
    if(r1 == r2) {
		cout << "Congrats, you are out of the DC Tims Line!" << endl;
        activePlayer->isInLine = false;
        activePlayer->turnsInTimLine = 2;
        movePlayer(r1 + r2);
    }
    else {
        bool force = false;
        if(activePlayer->turnsInTimLine > 0) {
            cout << "Would you like to use a roll up the rim cup or pay $50 to get out of jail? (cup/pay/no)" << endl;
        }
        else if(activePlayer->turnsInTimLine == 0) {
            cout << "You must either use a roll up the rim cup or pay $50 (cup/pay)" << endl;
            force = true;
        }
        string response;
        while(cin >> response) {
            if(response == "pay") {
                   giveDebt(activePlayer, 50, theGoose); 
                   break;
            }
            else if (response == "cup") {
                if(returnTCup()) break;
                cout << "You don't have enough Tim's cups!" << endl;
            }
            else if(!force && response == "no") {
                giveJailTime();
                return;
            }
        }
            cout << "Congrats, you are out of the DC Tims Line!" << endl;
            activePlayer->isInLine = false;
            activePlayer->turnsInTimLine = 2;
            movePlayer(r1+r2);
    }
}
