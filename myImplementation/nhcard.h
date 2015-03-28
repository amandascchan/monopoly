#ifndef __NHCARD_H__
#define __NHCARD_H__
#include <player.h>
#include <card.h>

class NHCard: public Card{
	int transAmt;
	action(Player *);
};

#endif
