#ifndef __CARD_H__
#define __CARD_H__

class Board;

class Card{
protected:
	Board *theBoard;
public:
	Card(Board *theBoard): theBoard(theBoard){}
	virtual void action()=0;
};

#endif