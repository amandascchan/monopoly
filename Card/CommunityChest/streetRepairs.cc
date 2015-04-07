#include "streetRepairs.h"
#include "../../Player/player.h"
#include "../../Board/board.h"
#include <vector>
#include "../../Square/Property/property.h"
#include "../../Square/Property/Academic/academic.h"

StreetRepairsCard::StreetRepairsCard(Board *theBoard, std::string name): Card(theBoard, name){}

void StreetRepairsCard::action(){
	std::cout << "Street repairs! 40 dollars per property and 30 dollars per improvement." << std::endl;
	Player *currentPlayer = theBoard->getNextPlayer(0);
	for (std::vector<Property *>::iterator it = currentPlayer->properties.begin(); it != currentPlayer->properties.end(); ++it){
		theBoard->giveDebt(currentPlayer, 40, NULL);
		Academic *acadP = dynamic_cast<Academic *>(*it);
		if (acadP != NULL){
			theBoard->giveDebt(currentPlayer, acadP->getNumImp()*30, NULL);
		}
	}
}