#include "textdisplay.h"
#include "square.h"
#include <string>

using namespace std;

Square::Square(): desc(""), cost(0), imCost(0), row(0), column(0), td(NULL), owner(NULL) {
    for(int i = 0; i < 6; i ++) {
        im[i] = 0;
    }
}
void Square::setBlock(string name) {this->block = name;}
string Square::getBlock() {return block;}
void Square::setName(string name) {
    this->name = name;
}
string Square::getName() {
    return name;
}
void Square::setCoords(const int r, const int c) {
  this->row = r;
  this->column = c;
}
void Square::setDisplay(TextDisplay * t) {
  td = t;
}

int Square::getIm(int i) {
    return im[i];
}
void Square::setIm(int i, int cost) {
    im[i] = cost;
}
void Square::setDesc(string desc) {
    this->desc = desc;
}
string Square::getDesc() { return this->desc;}
void Square::setCost(int cost) {this->cost = cost;}
int Square::getCost() {return this->cost;}
void Square::setImCost(int cost) {imCost = cost;}
int Square::getImCost() {return this->imCost;}
void Square::setOwner(Player *p) {owner = p;}
