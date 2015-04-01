#include "nhcard.h"
#include "../Player/player.h"
#include "../Board/board.h"
//#include "../TextDisplay/textdisplay.h"


void NHCard::action(){
	theBoard->getNextPlayer(0)->transaction(transAmt, NULL);
}


NHCard::NHCard(Board *theBoard, int transAmt): Card(theBoard), transAmt(transAmt){}