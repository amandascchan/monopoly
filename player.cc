#include "all.h.gch"
#include "board.h"
#include "square.h"
#include <string> 
#include "data/playerdata.h"
#include "player.h"
using namespace std;

Player::Player(string name, TextDisplay *t, Board *b, Square *l, int lDex): lIndex(0), name(name), cups(0), location(NULL), theBoard(NULL), savings(0), td(NULL), row(0), column(0), turnsInTimLine(0), bankrupt(false) {
    avatar = playerOptions[name].avatar;
    td = t;
    theBoard = b;
    location = l;
    lIndex = lDex;
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
void Player::displayAssets() {
    cout << "Your avatar: " << avatar << endl;
    cout << "Your savings: " << savings << endl;
    cout << "Your Properties: " << endl;
    cout << "Your location: " << location->getName() << endl;
    cout << "Number of Tim's Cups you have: " << cups << endl;
    for(vector<Square*>::iterator it = properties.begin(); it != properties.end(); ++it) {
        cout << "Name: " << (*it)->getName() << endl;
        cout << "Cost: " << (*it)->getCost() << endl;
        cout << "Tuition for other players: " << (*it)->getRent() << endl;
        cout << "Improvement Cost: " << (*it)->getImCost() << endl;
        cout << "Property possible improvements" << endl;
        for(int i = 0; i < 6; i++) {
            cout << i << " " << (*it)->getIm(i) << endl;        
        }
    }
}
