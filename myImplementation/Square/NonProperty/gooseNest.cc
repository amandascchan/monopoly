#include "gooseNest.h"	

GooseNest::GooseNest(Board *theBoard, Square *prevSquare, Square *nextSquare):
		theBoard(theBoard), prevSquare(prevSquare),
		nextSquare(nextSquare), name("Goose Nest"){}
void GooseNest::action(){}