#include "slccard.h"

SLCCard::action(Player *player){
	if ((move<=3)&&(-3<=move)){
		player->board->movePlayer(move);
	}
	else if (move > 3){
		player->board->movePlayer("DC Tims Line");
	}
	else if (move < -3){
		player->board->movePlayer("Collect OSAP");
	}
}

SLCCard::SLCCard(int move): move(move){}