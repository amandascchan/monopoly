#include <string>
#include <cstdlib>
#include <ctime>
#include "SLC.h"
#include "../../Card/card.h"
#include "../../Player/player.h"
#include "../../TextDisplay/textdisplay.h"
#include "../../Board/board.h"
#include "../../DeckBuilder/deckbuilder.h"



void SLC::action(){
	deck[rand() % deck.size()]->action();
}



SLC::SLC(Board *theBoard, TextDisplay *td):
		NonProperty(theBoard, td){
	name = "SLC";
	deckBuilder myBuilder(theBoard);
	std::string config = "24 SLCCard -4 1 -3 3 -2 4 -1 4 1 3 2 4 3 4 4 1";
	this->deck = myBuilder.buildDeck(config);
}

SLC::~SLC(){
	for (std::vector<Card *>::iterator i = this->deck.begin(); i != deck.end(); ++i){
		delete *i;
	}
}