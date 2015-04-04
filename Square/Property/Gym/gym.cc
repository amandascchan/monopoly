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
	int r1 = rand() % 6 + 1;
	int r2 = rand() % 6 + 1;
	int mult = 4;
	if (owner->ownsBlock(block)) mult = 10;
	return mult*(r1 + r2);
}