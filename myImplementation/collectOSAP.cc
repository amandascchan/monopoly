#include "collectOSAP.h"
#include "board.h"	
#include <iostream>	

void CoopFee::action(){
	Player *currentPlayer = theboard->getNextPLayer(0);
	currentPlayer->savings += 200;
}