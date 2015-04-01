#include "timsLine.h"
#include "../../Player/player.h"
#include "../../TextDisplay/textdisplay.h"
#include "../../Board/board.h"

void TimsLine::action(){}

TimsLine::TimsLine(Board *theBoard, TextDisplay *td):
					Square(theBoard, td), name("DC Tims Line"){}