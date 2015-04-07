#ifndef __STREETREPAIRS_H__
#define __STREETREPAIRS_H__

#include "../card.h"

#include <string>

class Board;

class StreetRepairsCard: public Card{
public:
	StreetRepairsCard(Board *, std::string);
	void action();
};

#endif