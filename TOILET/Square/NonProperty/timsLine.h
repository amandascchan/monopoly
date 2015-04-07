#ifndef __TIMSLINE_H__
#define __TIMSLINE_H__

#include "nonproperty.h"

class Board;
class TextDisplay;

class TimsLine: public NonProperty{
public:
	TimsLine(Board *, TextDisplay *);
	void action();
};

#endif
