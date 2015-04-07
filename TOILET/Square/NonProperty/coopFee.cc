#include "coopFee.h"
#include "../../Player/player.h"
#include "../../TextDisplay/textdisplay.h"
#include "../../Board/board.h"
#include <iostream>	

void CoopFee::action(){
	Player *currentPlayer = theBoard->getNextPlayer(0);
	theBoard->giveDebt(currentPlayer, 150, theBoard->theGoose);
}

CoopFee::CoopFee(Board *theBoard, TextDisplay *td):
		NonProperty(theBoard, td){
			name = "Co-op Fee";
		}