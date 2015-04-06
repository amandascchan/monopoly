#include "gooseNest.h"	
#include "../../Player/player.h"
#include "../../TextDisplay/textdisplay.h"
#include "../../Board/board.h"
#include <map>

GooseNest::GooseNest(Board *theBoard, TextDisplay *td):
		NonProperty(theBoard, td){
			name = "Goose Nest";
		}
void GooseNest::action(){
	std::cout << "goose NEsT" << std::endl;
	if (theBoard->theGoose != NULL){
		std::cout << "the goose is real" << std::endl;
		theBoard->giveDebt(theBoard->theGoose, theBoard->theGoose->getSavings(), theBoard->getNextPlayer(0));
		if (theBoard->modeMap.count("richGoose")){theBoard->giveMoney(theBoard->theGoose, 500);}
	}
}