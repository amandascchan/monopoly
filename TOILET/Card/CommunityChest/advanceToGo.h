#ifndef __ADVANCETOGO_H__
#define __ADVANCETOGO_H__

#include "../card.h"
#include <string>

class Board;

class AdvanceToGoCard: public Card{
public:
	AdvanceToGoCard(Board *, std::string);
	void action();
};

#endif
