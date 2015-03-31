#ifndef __GOOSENEST_H__
#define __GOOSENEST_H__

class GooseNest: public NonProperty{
public:
	GooseNest(Board *theBoard, TextDisplay *);
	void action();
};

#endif