#include "coopFee.h"
#include "board.h"	
#include <iostream>	

void CoopFee::action(){
	Player *currentPlayer = theboard->getNextPLayer(0);
	currentPlayer->debt += 150;
	currentPlayer->payDebt();
}

CoopFee::CoopFee(Board *theBoard, TextDisplay *td):
		Square(theBoard, td), name("Co-op Fee"){}