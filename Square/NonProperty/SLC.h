#ifndef __SLC_H__
#define __SLC_H__

#include "nonproperty.h"
#include <vector>
class Card;
class Board;
class TextDisplay;

class SLC: public NonProperty{
	std::vector<Card *> deck;
public:
	void action();
	SLC(Board *, TextDisplay *);
	~SLC();
};

#endif