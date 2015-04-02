#include "../../../Board/board.h"
#include "../../../Player/player.h"
#include "../../../TextDisplay/textdisplay.h"
#include "gym.h"
#include <string>
#include <cstdlib>
#include <iostream>


Gym::Gym(Board *theBoard, TextDisplay *td): Property(theBoard, td){
	price = 150;
	block = "Gym";
	owner = NULL;
	isMortgaged = NULL;
}

int Gym::getRent(){
	if (owner->ownsBlock(block)) return 10;
	else return 4;
}

void Gym::action(){
	if (owner == NULL){
		buy();
	}
	else {
		int r1 = rand() % 6 + 1;
		int r2 = rand() % 6 + 1;
		theBoard->getNextPlayer(0)->transaction(-getRent()*(r1+r2), owner);
	}
}