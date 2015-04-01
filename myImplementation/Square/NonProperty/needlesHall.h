#ifndef __NEEDLESHALL_H__
#define __NEEDLESHALL_H__

#include "nonproperty.h"

class Player;
class NHCard;
class Board;
class TextDisplay;

class NeedlesHall: public NonProperty{
	std::vector<Card *> deck;
public:
	void action();
	NeedlesHall(Board *, TextDisplay *);
	~NeedlesHall();
};

#endif