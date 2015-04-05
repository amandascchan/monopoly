#include "timsLine.h"
#include "../../Player/player.h"
#include "../../TextDisplay/textdisplay.h"
#include "../../Board/board.h"

void TimsLine::action(){
    theBoard->getNextPlayer(0)->setTLine(true);
}

TimsLine::TimsLine(Board *theBoard, TextDisplay *td):
					NonProperty(theBoard, td){
						name = "DC Tims Line";
					}
