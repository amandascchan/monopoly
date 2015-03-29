#ifndef __GOTOTIMSLINE_H__
#define __GOTOTIMSLINE_H__

class GoToTimsLine: public NonProperty{
public:
	GoToTimsLine(Board *theBoard, Square *prevSquare, Square *nextSquare);
	void action();
};

#endif