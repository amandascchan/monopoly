#include "collectOSAP.h"
#include "../../Player/player.h"
#include "../../TextDisplay/textdisplay.h"
#include "../../Board/board.h"
#include <iostream>	

void CollectOSAP::action(){
	Player *currentPlayer = theBoard->getNextPlayer(0);
	currentPlayer->transaction(200, NULL);
}

CollectOSAP::CollectOSAP(Board *theBoard, TextDisplay *td):
		NonProperty(theBoard, td){
			name = "Collect OSAP";
		}