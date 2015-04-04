#include "goToTimsLine.h"
#include "../../Player/player.h"
#include "../../TextDisplay/textdisplay.h"
#include "../../Board/board.h"

void GoToTimsLine::action(){
	theBoard->movePlayer("DC Tims Line");
	theBoard->giveJailTime();
}

GoToTimsLine::GoToTimsLine(Board *theBoard, TextDisplay *td):
		NonProperty(theBoard, td){
			name = "Go to Tims Line";
		}
