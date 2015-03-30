#include "all.h.gch"
#include "board.h"
#include "square.h"
#include <string> 
#include "data/playerdata.h"
#include "player.h"
#include <ncurses.h>
using namespace std;

Player::Player(string name, TextDisplay *t, Board *b, Square *l, int lDex): lIndex(0), name(name), cups(0), location(NULL), theBoard(NULL), savings(0), td(NULL), row(0), column(0), turnsInTimLine(0), bankrupt(false) {
    initscr();
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
    addstr( "Your avatar: " +avatar);
    addch('\n');
    addstr("Your savings: " + savings);
    addch('\n');
    addstr("Your Properties: \n");
    string x = "Your location: " + location->getName();
    printw(x.c_str());
    addch('\n');
    addstr("Number of Tim's Cups you have: " +cups); 
    addch('\n');
    for(vector<Square*>::iterator it = properties.begin(); it != properties.end(); ++it) {
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
    }
}
