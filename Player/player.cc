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

Player::Player(string name, TextDisplay *t, Board *b, Square *l, int lDex): 
    name(name), location(l), theBoard(b), td(t), cups(0), avatar(playerOptions[name].avatar), savings(0), row (0), column(0), lIndex(lDex), turnsInTimLine(0), bankrupt(false), creditor(NULL), debt(0), isInLine(false){}

void Player::setCoords(int row, int column) {
    this->row = row;
    this->column = column;
}

int Player::totalWorth(){
  int worth = savings;
  for(vector<Property *>::iterator it = properties.begin(); it != properties.end(); ++it){
    worth += (*it)->getCost();
    Academic *acadP = dynamic_cast<Academic *>(*it);
    if (acadP != NULL){
        worth += (acadP->getImCost())*(acadP->getNumImp());
    }
  }
  return worth;
}
string Player::getName() {return name;}
int Player::getSavings() {return savings;}

Board* Player::getBoard() { return theBoard;}
void Player::endTurn() {theBoard->next();}
bool Player::isBankrupt() {return bankrupt;}
Player::~Player() {}
bool Player::ownsBlock(string name) {
    for(map<string, SquareData>::iterator it = aInfo.begin(); it!= aInfo.end(); ++it) {
      if(it->second.block == name) {
        bool present = (find(properties.begin(), properties.end(), theBoard->getSquare(it->second.name)) != properties.end());
        if(!present) return false;
      }
    }
    return true;
    
}
int Player::numRez() {
  int count = 0;
  for(vector<Property *>::iterator it = properties.begin(); it != properties.end(); ++it) {
    if((*it)->getBlock() == "Residence") count++;
  }
  return count;
}
bool Player::canAfford(int number) {
  if (debt > 0) {return false;}
  return (savings - number >= 0);
}

void Player::payDebt() {
  int payment = debt;
  if(savings < debt) payment = savings;
  theBoard->giveMoney(creditor, payment);
  debt = debt - payment;
  savings = savings - payment;
}

void Player::addProperty(Property *p) {
  properties.push_back(p);
}
bool Player::ownsProperty(Property *p) {
    for(vector<Property *>::iterator it=properties.begin(); it!=properties.end();it++) {
        //cout << (*it)->name << endl;
        if((*it)->name == p->getName()) return true;
    }
    return false;

}
void Player::displayAssets() {
	cout << "Your avatar: " << avatar << endl;
	cout << "Your savings: " << savings << endl;
  if (debt > 0){
    cout << "Your debt: " << debt << endl;
    cout << "Your creditor: ";
    if (creditor == NULL){cout << "BANK";}
    else {cout << creditor->getName();}
    cout << endl;
  }
	cout << "Your location: " << location->getName() << endl;
	cout << "Number of Tim's Cups you have: " << cups << endl;
    if (properties.size() != 0) cout << "Your Properties: " << endl;
	for(vector<Property*>::iterator it = properties.begin(); it != properties.end(); ++it) {
		cout << "Name: " << (*it)->getName() << endl;
		cout << "Block: " << (*it)->getBlock() << endl;
		cout << "Cost: " << (*it)->getCost() << endl;
        cout << "Tuition for other players: ";
        if (dynamic_cast<Gym *>(*it) != NULL){
        cout << dynamic_cast<Gym *>(*it)->getMult() << " times the sum of the roll of two dice" << endl;
        }
        else {
            cout << (*it)->getRent() << endl;
        }
		if (dynamic_cast<Academic *>(*it) != NULL){
			cout << "Improvement Cost: " << dynamic_cast<Academic *>(*it)->getImCost() << endl;
			cout << "Possible improvements" << endl;
			for(int k = 0; k < 6; k++) {
				cout << k << " " << dynamic_cast<Academic *>(*it)->getIm(k) << endl;        
			}
		}
	}
}
bool Player::isInTLine() {
    return isInLine;
}
