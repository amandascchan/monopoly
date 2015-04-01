#ifndef __NEEDLESHALL_H__
#define __NEEDLESHALL_H__

#include "nonproperty.h"
#include <vector>

class Player;
class Card;
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