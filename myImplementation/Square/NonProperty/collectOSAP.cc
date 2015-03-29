#include "collectOSAP.h"
#include "board.h"	
#include <iostream>	

void CollectOSAP::action(){
	Player *currentPlayer = theboard->getNextPLayer(0);
	currentPlayer->savings += 200;
}

CollectOSAP::CollectOSAP(Board *theBoard, Square *prevSquare, Square *nextSquare):
		theBoard(theBoard), prevSquare(prevSquare),
		nextSquare(nextSquare), name("Collect OSAP"){}