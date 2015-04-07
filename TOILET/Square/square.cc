#include "square.h"
#include "../TextDisplay/textdisplay.h"
#include "../Board/board.h"
using namespace std;
Square::~Square(){}

Square::Square(Board *theBoard, TextDisplay *td): theBoard(theBoard), td(td){ index = 0;}

void Square::setPosition(int r, int c){
	row = r;
	column = c;
}

string Square::getBlock() {return "block";}

string Square::getName() {
    return name;
}
int Square::getIm(int i) {
    return 0;
}
int Square::getRent() { return 0;}
string Square::getDesc() { return "hello";}
int Square::getCost() {return 0;}
int Square::getImCost() {return 0;}
