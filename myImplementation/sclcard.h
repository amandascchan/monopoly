#ifndef __SLCCARD_H__
#define __SLCCARD_H__
#include "player.h"
#include "card.h"

class SLCCard: public Card{
	int move;
	action(Player *);
};

#endif
