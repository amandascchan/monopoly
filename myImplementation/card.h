#ifndef __CARD_H__
#define __CARD_H__
#include "player.h"

class Card{
	int numCards;
	virtual action(Player *)=0;
};

#endif
