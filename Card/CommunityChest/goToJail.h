#ifndef __GOTOJAIL_H__
#define __GOTOJAIL_H__

#include <string>
#include "../card.h"

class Board;

class GoToJailCard: public Card{
	std::string name;
public:
	GoToJailCard(Board *, std::string);
	void action();
};

#endif