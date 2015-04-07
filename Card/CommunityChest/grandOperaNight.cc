#include "grandOperaNight.h"
#include "../../Player/player.h"
#include "../../Board/board.h"
#include <vector>

GrandOperaNightCard::GrandOperaNightCard(Board *theBoard, std::string name): Card(theBoard, name){}

void GrandOperaNightCard::action(){
	std::cout << "Grand Opera Night! Tickets are 50 dollars." << std::endl;
	for (int i = 1; i < theBoard->getNumPlayers(); ++i){
		theBoard->giveDebt(theBoard->getNextPlayer(i), 50, theBoard->getNextPlayer(0));
	}
}