#ifndef __TUITION_H__
#define __TUITION_H__


#include "nonproperty.h"

class Board;
class TextDisplay;

class Tuition: public NonProperty{
public:
	Tuition::Tuition(Board *, TextDisplay *);
	void action();
};

#endif