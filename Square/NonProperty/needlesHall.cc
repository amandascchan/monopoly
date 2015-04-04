#include <string>
#include <cstdlib>
#include <ctime>
#include "needlesHall.h"
#include "../../Card/card.h"
#include "../../Player/player.h"
#include "../../TextDisplay/textdisplay.h"
#include "../../Board/board.h"
#include "../../DeckBuilder/deckbuilder.h"

void NeedlesHall::action(){
    int rNumber = rand() % 100;
    if(rNumber == 1) {
        theBoard->giveTCup();
    }
    else deck[rand() % deck.size()]->action();
}



NeedlesHall::NeedlesHall(Board *theBoard, TextDisplay *td):
	NonProperty(theBoard, td){
	name = "Needles Hall";
	deckBuilder myBuilder(theBoard);
	std::string config = "18 NHCard -200 1 -100 2 -50 3 25 6 50 3 100 2 200 1";
	deck = myBuilder.buildDeck(config);
}

NeedlesHall::~NeedlesHall(){
	for (std::vector<Card *>::iterator it = deck.begin(); it != deck.end(); ++it){
		delete *it;
	}
}
