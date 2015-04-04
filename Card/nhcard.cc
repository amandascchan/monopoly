#include "nhcard.h"
#include "../Player/player.h"
#include "../Board/board.h"
//#include "../TextDisplay/textdisplay.h"


void NHCard::action(){
	Player *currentPlayer = theBoard->getNextPlayer(0);
	if (transAmt >= 0){
		theBoard->giveMoney(currentPlayer, transAmt);
	}
	else {
		theBoard->giveDebt(currentPlayer, -transAmt, NULL);
	}
}

NHCard::NHCard(Board *theBoard, int transAmt): Card(theBoard), transAmt(transAmt){}
NHCard::~NHCard() {}
