#include "collectOSAP.h"
#include "../../Player/player.h"
#include "../../TextDisplay/textdisplay.h"
#include "../../Board/board.h"
#include <iostream>	

void CollectOSAP::action(){
	Player *currentPlayer = theBoard->getNextPlayer(0);
	int money = 200;
	if (theBoard->modeMap.count("doubleOSAP")) money *=2;
	theBoard->giveMoney(currentPlayer, money);
}


CollectOSAP::CollectOSAP(Board *theBoard, TextDisplay *td):
		NonProperty(theBoard, td){
			name = "Collect OSAP";
		}