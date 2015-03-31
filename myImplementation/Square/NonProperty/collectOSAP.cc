#include "collectOSAP.h"
#include "board.h"	
#include <iostream>	

void CollectOSAP::action(){
	Player *currentPlayer = theboard->getNextPLayer(0);
	currentPlayer->savings += 200;
}

CollectOSAP::CollectOSAP(Board *theBoard, TextDisplay *td):
		Square (theBoard, td), name("Collect OSAP"){}