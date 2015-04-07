#ifndef __GRANDOPERANIGHT_H__
#define __GRANDOPERANIGHT_H__


#include <string>
#include "../card.h"

class Board;

class GrandOperaNightCard: public Card{
	std::string name;
public:
	GrandOperaNightCard(Board *, std::string);
	void action();
};

#endif