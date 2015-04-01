#include "nhcard.h"
#include "../Player/player.h"
#include "../Board/board.h"

void NHCard::action(){
	theBoard->getNextPlayer(0)->transaction(transAmt, NULL);
}


NHCard::NHCard(Board *theBoard, int transAmt): theBoard(theBoard), transAmt(transAmt){}