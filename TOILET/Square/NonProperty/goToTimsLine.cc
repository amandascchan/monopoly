#include "goToTimsLine.h"
#include "../../Player/player.h"
#include "../../TextDisplay/textdisplay.h"
#include "../../Board/board.h"

void GoToTimsLine::action(){
    theBoard->getNextPlayer(0)->setTLine(true);
    theBoard->movePlayer("DC Tims Line");
}

GoToTimsLine::GoToTimsLine(Board *theBoard, TextDisplay *td):
		NonProperty(theBoard, td){
			name = "Go To Tims";
		}
