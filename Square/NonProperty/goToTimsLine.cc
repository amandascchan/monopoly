#include "goToTimsLine.h"
#include "../../Player/player.h"
#include "../../TextDisplay/textdisplay.h"
#include "../../Board/board.h"

void GoToTimsLine::action(){
    cout << "I GET HERE" << endl;
    theBoard->getNextPlayer(0)->setTLine(true);
}

GoToTimsLine::GoToTimsLine(Board *theBoard, TextDisplay *td):
		NonProperty(theBoard, td){
			name = "Go to Tims Line";
		}
