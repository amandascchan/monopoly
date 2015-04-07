#include "slccard.h"
#include "../Player/player.h"
#include "../Board/board.h"

void SLCCard::action( ){
	std::cout << "SLC moved you."<< std::endl;
	if ((move<=3)&&(-3<=move)){
		theBoard->movePlayer(move);
	}
	else if (move > 3){
		theBoard->movePlayer("GO TO TIMS");
	}
	else if (move < -3){
		theBoard->movePlayer("Collect OSAP");
	}
}

SLCCard::SLCCard(Board *theBoard, int move): Card(theBoard, "SLC Card"), move(move){}
SLCCard::~SLCCard(){}
