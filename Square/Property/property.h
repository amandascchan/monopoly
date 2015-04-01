#ifndef __PROPERTY_H__
#define __PROPERTY_H__
#include "../square.h"

class Player;

class Property: public Square{
	bool isMortgaged;
	Player *owner;
	int price;
	string block;
	void auction();
	void buy();
	void unMortgage();
	virtual void mortgage();
	virtual void action()=0;
	virtual ~Property();
};

#endif

