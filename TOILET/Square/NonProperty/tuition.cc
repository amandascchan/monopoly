#include "tuition.h"
#include "../../Player/player.h"
#include "../../TextDisplay/textdisplay.h"
#include "../../Board/board.h"
#include <iostream>	

void Tuition::action(){
	Player *currentPlayer = theBoard->getNextPlayer(0);
	std::cout << "pay 1. $300 or 2. 10 percent of your total worth? enter 1 or 2." << std::endl;
	std::string command;
	while (cin >> command){
		if (command == "1"){
			theBoard->giveDebt(currentPlayer, 300, theBoard->theGoose);
			break;
		}
		else if (command == "2"){
			theBoard->giveDebt(currentPlayer, 0.1*currentPlayer->totalWorth(), theBoard->theGoose);
			break;
		}
	}
}

Tuition::Tuition(Board *theBoard, TextDisplay *td):
					NonProperty(theBoard, td){
						name = "Tuition";
					}