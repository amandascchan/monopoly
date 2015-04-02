#ifndef __PROPERTY_H__
#define __PROPERTY_H__
#include "../square.h"
#include <string>

class Player;
class Board;
class TextDisplay;

class Property: public Square{
	friend class Board;
protected:
	bool isMortgaged;
	Player *owner;
	int price;
	std::string block;
	void auction();
	void buy();
	void unMortgage();
	Property(Board *, TextDisplay *);
	virtual void mortgage();
	virtual void action()=0;
	virtual ~Property();
public:
	std::string getBlock();
	int getCost();
	virtual int getRent()=0;
	bool getIsMortgaged();
};

#endif

