#include "../all.h.gch"
#include "../Board/board.h"
#include "../Square/square.h"
#include "../Square/Property/property.h"
#include "../Square/Property/Residence/residence.h"
#include "../Square/Property/Gym/gym.h"
#include "../Square/Property/Academic/academic.h"
#include <string> 
#include "../data/squaredata.h"
#include "../data/playerdata.h"
#include "player.h"
#include <algorithm>
using namespace std;

Player::Player(string name, TextDisplay *t, Board *b, Square *l, int lDex): creditor(NULL),lIndex(0), name(name), cups(0), location(NULL), theBoard(NULL), savings(0), td(NULL), row(0), column(0), turnsInTimLine(0), bankrupt(false) {
    avatar = playerOptions[name].avatar;
    td = t;
    theBoard = b;
    location = l;
    lIndex = lDex;
    debt = 0;
}
void Player::setCoords(int row, int column) {
    this->row = row;
    this->column = column;
}
string Player::getName() {return name;}
int Player::getSavings() {return savings;}
void Player::Bankrupt() {bankrupt = true;}
Board* Player::getBoard() { return theBoard;}
void Player::endTurn() {theBoard->next();}
bool Player::isBankrupt() {return bankrupt;}
Player::~Player() {}
bool Player::ownsBlock(string name) {
    for(map<string, Academic>::iterator it = aInfo.begin(); it!= aInfo.end(); ++it) {
      if(it->second.block == name) {
        bool present = (find(properties.begin(), properties.end(), theBoard->getSquare(it->second.name)) != properties.end());
        if(!present) return false;
      }
    }
    return true;
    
}
int Player::numRez() {
  int count = 0;
  for(vector<Square *>::iterator it = properties.begin(); it != properties.end(); ++it) {
    if((*it)->getBlock() == "Residence") count++;
  }
  return count;
}
bool Player::canAfford(int number) {
  return (savings - number >= 0);
}
void Player::transaction(int amount, Player *p) {
  int result  = savings + amount;
  if(p != this) {
    if(result < 0) {
      (p)? creditor = p : NULL;
      savings = 0;
      debt = result;
    }
    else {
      savings = result;
      creditor->savings += amount;
    }
  }
}
void Player::displayAssets() {
    cout << "Your avatar: " << avatar << endl;
    cout << "Your savings: " << savings << endl;
    cout << "Your Properties: " << endl;
    cout << "Your location: " << location->getName() << endl;
    cout << "Number of Tim's Cups you have: " << cups << endl;
    for(vector<Square*>::iterator it = properties.begin(); it != properties.end(); ++it) {
        cout << "Name: " << (*it)->getName() << endl;
        cout << "Block: " << (*it)->getBlock() << endl;
        cout << "Cost: " << (*it)->getCost() << endl;
        cout << "Tuition for other players: " << (*it)->getRent() << endl;
        cout << "Improvement Cost: " << (*it)->getImCost() << endl;
        cout << "Property possible improvements" << endl;
        for(int i = 0; i < 6; i++) {
            cout << i << " " << (*it)->getIm(i) << endl;        
        }
    }
}
