#include "tuition.h"
#include "board.h"	
#include <iostream>	

void Tuition::action(){
	Player *currentPlayer = theboard->getNextPLayer(0);
	int totalWorth = currentPlayer->totalWorth();
	std::cout << 'pay 1. $300 or 2. 10% of your total worth? enter 1 or 2.' << std::endl;
	std::string command;
	std::cin >> command;
	if (command == "1"){
		currentPlayer->debt += 300;
	}
	if (command == "2"){
		currentPlayer->debt += 0.1*totalWorth;
	}
	currentPlayer->payDebt();
}

Tuition::Tuition(Board *theBoard, Square *prevSquare, Square *nextSquare):
					theBoard(theBoard), prevSquare(prevSquare),
					nextSquare(nextSquare), name("Tuition"){}