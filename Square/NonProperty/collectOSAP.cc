#include "collectOSAP.h"
#include "../../Player/player.h"
#include "../../TextDisplay/textdisplay.h"
#include "../../Board/board.h"
#include <iostream>	

void CollectOSAP::action(){
	Player *currentPlayer = theBoard->getNextPlayer(0);
	theBoard->transfer(currentPlayer, 200);
}


CollectOSAP::CollectOSAP(Board *theBoard, TextDisplay *td):
		NonProperty(theBoard, td){
			name = "Collect OSAP";
		}