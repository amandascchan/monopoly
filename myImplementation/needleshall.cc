#include <string>
#include <cstdlib>
#include <ctime>



void NeedlesHall::action(){
	deck[rand() % deck.size()]->action();
}



NeedlesHall::NeedlesHall(){
	deckBuilder myBuilder;
	std::string config = "18 NHCard -200 1 -100 2 -50 3 25 6 50 3 100 2 200 1"
	deck = deckBuilder->buildDeck(config);
}

NeedlesHall::~NeedlesHall(Board *theBoard, Square *prevSquare, Square *nextSquare):	theBoard(theBoard), prevSquare(prevSquare), nextSquare(nextSquare){
	for (std::vector<Card *>::iterator i = deck.begin(); i != deck.end(); ++i){
		delete *i;
	}
}