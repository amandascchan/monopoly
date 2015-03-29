#ifndef __TIMSLINE_H__
#define __TIMSLINE_H__

class TimsLine: public NonProperty{
public:
	TimsLine(Board *theBoard, Square *prevSquare, Square *nextSquare);
	void action();
};

#endif