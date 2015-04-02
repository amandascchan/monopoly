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

Player::Player(string name, TextDisplay *t, Board *b, Square *l, int lDex): creditor(NULL),lIndex(0), name(name), cups(0), location(NULL), theBoard(NULL), savings(1500), td(NULL), row(0), column(0), turnsInTimLine(0), bankrupt(false) {
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
void Player::Bankrupt() {
  bankrupt = true;
  if (creditor == NULL){

  }
  else {

  }

}
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
  return (savings - number >= 0);
}
void Player::transaction(int amount, Player *p) {
  int result  = savings + amount;
  if(p && p != this) {
    if(result < 0) {
      creditor = p;
      savings = 0;
      debt = result;
    }
    else {
      theBoard->transfer(p, -1*amount);
      savings = result;
    }
  }
  else if(p == NULL) {
      savings = result;
    }
}
void Player::addProperty(Property *p) {
  properties.push_back(p);
}
void Player::displayAssets() {
	cout << "Your avatar: " << avatar << endl;
	cout << "Your savings: " << savings << endl;
	cout << "Your location: " << location->getName() << endl;
	cout << "Number of Tim's Cups you have: " << cups << endl;
    if (properties.size() != 0) cout << "Your Properties: " << endl;
	for(vector<Property*>::iterator it = properties.begin(); it != properties.end(); ++it) {
		cout << "Name: " << (*it)->getName() << endl;
		cout << "Block: " << (*it)->getBlock() << endl;
		cout << "Cost: " << (*it)->getCost() << endl;
        cout << "Tuition for other players: ";
        if (dynamic_cast<Gym *>(*it) != NULL){
        cout << dynamic_cast<Gym *>(*it)->getRent() << " times the sum of the roll of two dice" << endl;
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
