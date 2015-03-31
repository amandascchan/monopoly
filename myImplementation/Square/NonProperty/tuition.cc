#include "tuition.h"
#include "board.h"	
#include <iostream>	

void Tuition::action(){
	Player *currentPlayer = theBoard->getNextPLayer(0);
	int totalWorth = currentPlayer->totalWorth();
	std::cout << 'pay 1. $300 or 2. 10% of your total worth? enter 1 or 2.' << std::endl;
	std::string command;
	std::cin >> command;
	if (command == "1"){
		currentPlayer->transaction(-300, NULL);
	}
	if (command == "2"){
		currentPlayer->transaction(-0.1*totalWorth, NULL);
	}
}

Tuition::Tuition(Board *theBoard, TextDisplay *td):
					Square(theBoard, td), name("Tuition"){}