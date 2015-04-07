#ifndef __GETOUTOFJAIL_H__
#define __GETOUTOFJAIL_H__

#include <string>
#include "../card.h"

class Board;

class GetOutOfJailCard: public Card{
	std::string name;
public:
	GetOutOfJailCard(Board *, std::string);
	void action();
};

#endif