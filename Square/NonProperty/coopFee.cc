#include "coopFee.h"
#include "../../Player/player.h"
#include "../../TextDisplay/textdisplay.h"
#include "../../Board/board.h"
#include <iostream>	

void CoopFee::action(){
	theboard->getNextPlayer(0)->transation(150, NULL);
}

CoopFee::CoopFee(Board *theBoard, TextDisplay *td):
		Square(theBoard, td), name("Co-op Fee"){}