#ifndef __PROPERTY_H__
#define __PROPERTY_H__
class Player;

class Property: public Square{
	bool isMortgaged;
	Player *owner;
	int price;
	void auction();
	void buy();
	void unMortgage();
	virtual void mortgage()=0;
	virtual void action()=0;
	virtual ~Property();
};

#endif

