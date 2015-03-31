#include "board.h"
#include "textdisplay.h"
#include "gym.h"
#include <string>
#include <iostream>


Gym::Gym(Board *theBoard, TextDisplay *td): Square(theBoard, td),
											price(150), block("Gym"){}

void Gym::action(){
	int r1 = rand() % 6 + 1;
	int r2 = rand() % 6 + 1;
	int fee;
	if (owner->ownsBlock(block)) fee = 10*(r1 + r2);
	else fee = 4*(r1 + r2);
	theBoard->getCurrentPlayer(0)->transaction(-fee, owner);
}