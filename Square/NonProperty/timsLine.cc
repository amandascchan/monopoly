#include "timsLine.h"
void TimsLine::action(){}

TimsLine::TimsLine(Board *theBoard, Square *prevSquare, Square *nextSquare):
					theBoard(theBoard), prevSquare(prevSquare),
					nextSquare(nextSquare), name("DC Tims Line"){}