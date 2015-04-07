#include "goToJail.h"
#include "../../Player/player.h"
#include "../../Board/board.h"

GoToJailCard::GoToJailCard(Board *theBoard, std::string name): Card(theBoard, name){}

void GoToJailCard::action(){
	std::cout << name << ": GO TO JAIL" << std::endl;
	theBoard->movePlayer("GO TO TIMS");
}