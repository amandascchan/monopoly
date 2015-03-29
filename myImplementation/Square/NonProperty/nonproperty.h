#ifndef __NONPROPERTY_H__
#define __NONPROPERTY_H__
class Player;

class NonProperty: public Square{
	virtual void action()=0;
	virtual ~NonProperty();
};

#endif

