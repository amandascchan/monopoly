#ifndef __CARD_H__
#define __CARD_H__
#include <string>

class Board;

class Card{
protected:
	Board *theBoard;
	std::string name;
public:
	Card(Board *theBoard, std::string name): theBoard(theBoard), name(name){}
	virtual void action()=0;
    virtual ~Card() {};
};

#endif
