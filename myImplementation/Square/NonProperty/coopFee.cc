#include "coopFee.h"
#include "board.h"	
#include <iostream>	

void CoopFee::action(){
	Player *currentPlayer = theboard->getNextPLayer(0);
	currentPlayer->debt += 150;
	currentPlayer->payDebt();
}

CoopFee::CoopFee(Board *theBoard, Square *prevSquare, Square *nextSquare):
		theBoard(theBoard), prevSquare(prevSquare), nextSquare(nextSquare), name("Co-op Fee"){}