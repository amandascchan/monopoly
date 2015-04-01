#include "coopFee.h"
#include "../../Player/player.h"
#include "../../TextDisplay/textdisplay.h"
#include "../../Board/board.h"
#include <iostream>	

void CoopFee::action(){
	theBoard->getNextPlayer(0)->transaction(150, NULL);
}

CoopFee::CoopFee(Board *theBoard, TextDisplay *td):
		NonProperty(theBoard, td){
			name = "Co-op Fee";
		}