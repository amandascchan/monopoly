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

void Gym::action(){
	if (owner == NULL){
		buy();
	}
	else {
		int r1 = rand() % 6 + 1;
		int r2 = rand() % 6 + 1;
		int fee;
		if (owner->ownsBlock(block)) fee = 10*(r1 + r2);
		else fee = 4*(r1 + r2);
		theBoard->getNextPlayer(0)->transaction(-fee, owner);
	}
}