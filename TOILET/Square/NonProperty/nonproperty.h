#ifndef __NONPROPERTY_H__
#define __NONPROPERTY_H__

#include "../square.h"

class Player;
class TextDisplay;
class Board;

class NonProperty: public Square{
	virtual void action()=0;
protected:
	NonProperty(Board *, TextDisplay *);
};

#endif

