#include "nhcard.h"
#include "player.h"
#include "board.h"

void NHCard::action(){
	theBoard->getNextPlayer(0)->transaction(transAmt, NULL);
}


NHCard::NHCard(Board *theBoard, int transAmt): theBoard(theBoard), transAmt(transAmt){}
