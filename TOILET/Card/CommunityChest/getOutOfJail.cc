#include "getOutOfJail.h"
#include "../../Player/player.h"
#include "../../Board/board.h"

GetOutOfJailCard::GetOutOfJailCard(Board *theBoard, std::string name): Card(theBoard, name){}

void GetOutOfJailCard::action(){
	std::cout << "Community Chest: GET OUT OF JAIL FREE CARD" << std::endl;
	theBoard->giveTCup();
}