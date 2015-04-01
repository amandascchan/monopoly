#ifndef __NHCARD_H__
#define __NHCARD_H__

#include "card.h"

class Board;

class NHCard: public Card{
	int transAmt;
public:
	NHCard(Board *,int);
	void action();
};

#endif
