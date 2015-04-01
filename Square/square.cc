#include "square.h"
#include "textdisplay.h"
#include "board.h"
Square::~Square(){}

Square::Square(Board *theBoard, TextDisplay *td): theBoard(theBoard), td(td){}

void Square::setPosition(int r, int c){
	row = r;
	column = c;
}