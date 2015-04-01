#include <string>
#include <cstdlib>
#include <ctime>
#include "SLC.h"
#include "card.h"



void SLC::action(){
	deck[rand() % deck.size()]->action();
}



SLC::SLC(Board *theBoard, Square *prevSquare, Square *nextSquare):
		theBoard(theBoard), prevSquare(prevSquare), nextSquare(nextSquare), name("SLC"){
	deckBuilder myBuilder;
	std::string config = "24 SLCCard -4 1 -3 3 -2 4 -1 4 1 3 2 4 3 4 4 1";
	deck = deckBuilder->buildDeck(config);
}

SLC::~SLC(){
	for (std::vector<Card *>::iterator i = deck.begin(); i != deck.end(); ++i){
		delete *i;
	}
}
