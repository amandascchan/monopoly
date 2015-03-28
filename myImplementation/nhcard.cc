#include "nhcard.h"

NHCard::action(Player *player){
	player->savings += transAmt;
}

NHCard::NHCard(int transAmt): transAmt(transAmt){}