#ifndef __GOOSENEST_H__
#define __GOOSENEST_H__

#include "nonproperty.h"

class Board;
class TextDisplay;

class GooseNest: public NonProperty{
public:
	GooseNest(Board *theBoard, TextDisplay *);
	void action();
};

#endif
