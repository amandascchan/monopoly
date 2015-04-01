#include "gooseNest.h"	
#include "../../Player/player.h"
#include "../../TextDisplay/textdisplay.h"
#include "../../Board/board.h"

GooseNest::GooseNest(Board *theBoard, TextDisplay *td):
		NonProperty(theBoard, td){
			name = "Goose Nest";
		}
void GooseNest::action(){}