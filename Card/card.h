#ifndef __CARD_H__
#define __CARD_H__

class Board;

class Card{
	Board *theBoard;
public:
	virtual void action()=0;
};

#endif