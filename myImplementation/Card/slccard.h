#ifndef __SLCCARD_H__
#define __SLCCARD_H__
#include "card.h"

class Board;

class SLCCard: public Card{
	int move;
public:
	SLCCard(Board *, int);
	void action();
};

#endif