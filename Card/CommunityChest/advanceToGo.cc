#include "advanceToGo.h"
#include "../../Player/player.h"
#include "../../Board/board.h"

AdvanceToGoCard::AdvanceToGoCard(Board *theBoard, std::string name): Card(theBoard, name){}

void AdvanceToGoCard::action(){
	std::cout << name << ": ADVANCE TO GO" << std::endl;
	theBoard->movePlayer("Collect OSAP");
}