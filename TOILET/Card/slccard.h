#ifndef __SLCCARD_H__
#define __SLCCARD_H__

#include "card.h"
class Board;

class SLCCard: public Card{
public:
	int move;
	SLCCard(Board *, int);
	void action();
    ~SLCCard();
};

#endif
