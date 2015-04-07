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
#include <ncurses.h>
using namespace std;

Player::Player(string name, TextDisplay *t, Board *b, Square *l, int lDex): 
    name(name), location(l), theBoard(b), td(t), cups(0), avatar(playerOptions[name].avatar), savings(0), row (0), column(0), lIndex(lDex), turnsInTimLine(2), bankrupt(false), creditor(NULL), debt(0), isInLine(false){}


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
	return (savings - number >= 0);
}

bool Player::hasDebt(){
	return (debt > 0);
}

bool Player::payingTuition(){
	bool retVal = false;
	Academic *acadP = dynamic_cast<Academic *>(location);
	if (hasDebt()){
	if (acadP != NULL){
		retVal = true;
	}
	else if (location->name == "Tuition"){
		retVal = true;
	}
}
	return retVal;
}

void Player::payDebt() {
  int payment = debt;
  Player *tmp = creditor;
  if(savings < debt) {payment = savings;}
  else {creditor = NULL;}
  debt = debt - payment;
  savings = savings - payment;
  theBoard->giveMoney(tmp, payment);

}

void Player::addProperty(Property *p) {
  properties.push_back(p);
}
bool Player::ownsProperty(Property *p) {
    for(vector<Property *>::iterator it=properties.begin(); it!=properties.end();it++) {
#ifdef toilet
        //#ifndef cout << (*it)->name << endl; #endif
#endif
        if((*it)->name == p->getName()) return true;
    }
    return false;

}
void Player::displayAssets() {
#ifdef toilet
    cout << "Your avatar: " << avatar << endl; 
#endif
#ifdef toilet
    cout << "Your savings: " << savings << endl; 
#endif
  if (debt > 0){
#ifdef toilet
      cout << "Your debt: " << debt << endl; 
#endif
#ifdef toilet
      cout << "Your creditor: ";
#endif
    if (creditor == NULL){
#ifdef toilet
        cout << "BANK";
#endif
    }
    else {
#ifdef toilet
        cout << creditor->getName();
#endif
    }
#ifdef toilet
        cout << endl; 
#endif
  }
#ifdef toilet
    cout << "Your location: " << location->getName() << endl; 
#endif
#ifdef toilet
    cout << "Number of Tim's Cups you have: " << cups << endl; 
#endif
    if (properties.size() != 0)  
#ifdef toilet
        cout << "Your Properties: " << endl;
#endif
	for(vector<Property*>::iterator it = properties.begin(); it != properties.end(); ++it) {
#ifdef toilet
        cout << (*it)->getName() << endl; 
#endif
		/*#ifndef cout << "Block: " << (*it)->getBlock() << endl; #endif
#endif
#ifdef toilet
		#ifndef cout << "Cost: " << (*it)->getCost() << endl; #endif
#endif
#ifdef toilet
        #ifndef cout << "Tuition for other players: ";
#endif
        if (dynamic_cast<Gym *>(*it) != NULL){
#ifdef toilet
        #ifndef cout << dynamic_cast<Gym *>(*it)->getMult() << " times the sum of the roll of two dice" << endl; #endif
#endif
        }
        else {
#ifdef toilet
            #ifndef cout << (*it)->getRent() << endl; #endif
#endif
        }
		if (dynamic_cast<Academic *>(*it) != NULL){
#ifdef toilet
			#ifndef cout << "Improvement Cost: " << dynamic_cast<Academic *>(*it)->getImCost() << endl; #endif
#endif
#ifdef toilet
			#ifndef cout << "Possible improvements" << endl; #endif
#endif
			for(int k = 0; k < 6; k++) {
#ifdef toilet
				#ifndef cout << k << " " << dynamic_cast<Academic *>(*it)->getIm(k) << endl; #endif        
#endif
			}
		}*/
	}
}

void Player::displayAssetsN() {
    addstr( "Your avatar: " +avatar);
    addch('\n');
    addstr("Your savings: " + savings);
    addch('\n');
    addstr("Your Properties: \n");
    string x = "Your location: " + location->getName();
    printw(x.c_str());
    addch('\n');
  //  addstr("Number of Tim's Cups you have: " +cups); 
  //  addch('\n');
  /*  for(vector<Square*>::iterator it = properties.begin(); it != properties.end(); ++it) {
        string n = "Name: " + (*it)->getName();
        string c = "Cost: " + (*it)->getCost();
        addstr(n.c_str());
        addch('\n');
        addstr(c.c_str()); 
        addch('\n');
        addstr("Tuition for other players: " +(*it)->getRent());
        addch('\n');
        addstr("Improvement Cost: " + (*it)->getImCost());
        addch('\n');
        addstr("Property possible improvements");
        addch('\n');
        for(int i = 0; i < 6; i++) {
            addch(i + '0');
            addch(':');
            char k = (*it)->getIm(i) + '0';
            addch(k);         
            addch('\n');
        }
    }*/
}
bool Player::isInTLine() {
    return isInLine;
}
void Player::setTLine(bool yesno) {
    isInLine = yesno;
}
