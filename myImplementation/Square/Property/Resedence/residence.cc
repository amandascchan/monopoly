#include "board.h"
#include "textdisplay.h"
#include "player.h"
#include "square.h"
#include <string>
#include <iostream>


Residence::Residence(Board *theBoard, TextDisplay *td): Square(theBoard, td),
											price(200), block("Residence"){}

void Residence::action(){
	int numOwned = owner->numRez();
	int fee;
	if (numOwned == 1) fee = 25;
	if (numOwned == 2) fee = 50;
	if (numOwned == 3) fee = 100;
	if (numOwned == 4) fee = 200;
	theBoard->getCurrentPlayer(0)->transaction(-fee, owner);
}