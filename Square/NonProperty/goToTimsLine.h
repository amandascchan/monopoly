#ifndef __GOTOTIMSLINE_H__
#define __GOTOTIMSLINE_H__

#include "nonproperty.h"

class Board;
class TextDisplay;

class GoToTimsLine: public NonProperty{
public:
	GoToTimsLine(Board *, TextDisplay *);
	void action();
};

#endif