#include "player.h"
#include "board.h"

void GoToTimsLine::action(){
	theBoard->movePlayer("DC Tims Line");
	theBoard->getNextPlayer(0)->giveJailTime();
}

GoToTimsLine::GoToTimsLine(Board *theBoard, TextDisplay *td):
		Square(theBoard, td), name("Go to Tims Line"){}