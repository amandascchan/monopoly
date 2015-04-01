#include "player.h"
#include "board.h"

void GoToTimsLine::action(){
	theBoard->movePlayer("DC Tims Line");
	theBoard->getNextPlayer(0)->giveJailTime();
}

GoToTimsLine::GoToTimsLine(Board *theBoard, Square *prevSquare, Square *nextSquare):
		theBoard(theBoard), prevSquare(prevSquare),
		nextSquare(nextSquare), name("Go to Tims Line"){}