#include "slccard.h"
#include "../Player/player.h"
#include "../Board/board.h"

void SLCCard::action( ){
	if ((move<=3)&&(-3<=move)){
		theBoard->movePlayer(move);
	}
	else if (move > 3){
		theBoard->movePlayer("Go To Tims");
	}
	else if (move < -3){
		theBoard->movePlayer("Collect OSAP");
	}
}

SLCCard::SLCCard(Board *theBoard, int move): Card(theBoard), move(move){}
