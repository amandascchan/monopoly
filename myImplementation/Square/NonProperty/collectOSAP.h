#ifndef __COLLECTOSAP_H__
#define __COLLECTOSAP_H__

#include "nonproperty.h"

class Board;
class TextDisplay;

class CollectOSAP: public NonProperty{
public:
	CollectOSAP(Board *theBoard, TextDisplay *);
	void action();
};

#endif
