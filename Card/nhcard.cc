#include "nhcard.h"
#include "../Player/player.h"
#include "../Board/board.h"
//#include "../TextDisplay/textdisplay.h"


void NHCard::action(){
	theBoard->transfer(theBoard->getNextPlayer(0), transAmt);
}


NHCard::NHCard(Board *theBoard, int transAmt): Card(theBoard), transAmt(transAmt){}
NHCard::~NHCard() {}
