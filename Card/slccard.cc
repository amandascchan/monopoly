#include "slccard.h"
#include "player.h"

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

SLCCard::SLCCard(Board *theBoard, int move): theBoard(theBoard), move(move){}
