#include "timsLine.h"
void TimsLine::action(){}

TimsLine::TimsLine(Board *theBoard, TextDisplay *td):
					Square(theBoard, td), name("DC Tims Line"){}