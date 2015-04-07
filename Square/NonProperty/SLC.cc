#include <string>
#include <cstdlib>
#include <ctime>
#include "SLC.h"
#include "../../Card/card.h"
#include "../../Player/player.h"
#include "../../TextDisplay/textdisplay.h"
#include "../../Board/board.h"
#include "../../DeckBuilder/deckbuilder.h"
#include "../../Card/slccard.h"




void SLC::action(){
    int rNumber = rand() % 100;
    if (theBoard->modeMap.count("chance")){std::cout << "Chance: ";}
    if(rNumber == 1) {
        theBoard->giveTCup();
    }
    else deck[rand() % deck.size()]->action();
}



SLC::SLC(Board *theBoard, TextDisplay *td):
	NonProperty(theBoard, td){
	name = "SLC";
	deckBuilder myBuilder(theBoard);
	std::string config = "24 SLCCard -4 1 -3 3 -2 4 -1 4 1 3 2 4 3 4 4 1";
	string name = "Chance";
	if (theBoard->modeMap.count("chance")){config = "5 AdvanceToGoCard 0 1 GetOutOfJailCard 0 1 GoToJailCard 0 1 GrandOperaNightCard 0 1 StreetRepairsCard 0 1";}
	this->deck = myBuilder.buildDeck(config, "Chance");
}

SLC::~SLC(){
	Card *justDeleted = NULL;
	for (std::vector<Card *>::iterator it = deck.begin(); it != deck.end(); ++it){
		if (*it != justDeleted){
			justDeleted = *it;
			delete *it;
		}
	}
}
