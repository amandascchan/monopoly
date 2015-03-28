#include <iostream>
#include "textdisplay.h"
#include <vector>
#include <string> 
#include "board.h"
#include "square.h"
#include <map>
#include "playerdata.h"
#include "player.h"

using namespace std;

Player::Player(string name): name(name), cups(0), location(NULL), theBoard(NULL), savings(0), td(NULL), row(0), column(0) {
    avatar = playerOptions[name];
}
void Player::movePlayer(int r, int c) {
 //   td->movePlayer(r,c, avatar);
}
void Player::setDisplay(TextDisplay *t) {
    td = t;
}
void Player::setCoords(int row, int column) {
    this->row = row;
    this->column = column;
}
string Player::getName() {return name;}
Player::~Player() {}
