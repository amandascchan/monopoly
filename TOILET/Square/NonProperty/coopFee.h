#ifndef __COOPFEE_H__
#define __COOPFEE_H__

#include "nonproperty.h"

class Board;
class TextDisplay;

class CoopFee: public NonProperty{
public:
	CoopFee(Board *theBoard, TextDisplay *);
	void action();
};

#endif
