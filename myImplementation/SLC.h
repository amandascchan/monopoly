#ifndef __SLC_H__
#define __SLC_H__

class Card;

class SLC: public NonProperty{
	std::vector<Card *> deck;
	void action();
	SLC(Board *theBoard, Square *prevSquare, Square *nextSquare);
	~SLC();
};

#endif