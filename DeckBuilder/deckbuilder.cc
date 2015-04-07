#include "../Card/card.h"
#include "../Card/slccard.h"
#include "../Card/nhcard.h"
#include "../Card/CommunityChest/advanceToGo.h"
#include "../Card/CommunityChest/getOutOfJail.h"
#include "../Card/CommunityChest/goToJail.h"
#include "../Card/CommunityChest/streetRepairs.h"
#include "../Card/CommunityChest/grandOperaNight.h"
#include "deckbuilder.h"
#include <sstream>
#include <iostream>

deckBuilder::deckBuilder(Board *theBoard): theBoard(theBoard){}

std::vector<Card *> deckBuilder::buildDeck(std::string config, std::string name){
	std::stringstream configStream(config);
	int totalCards;
	configStream >> totalCards;
	std::string cardType;
	std::vector<Card *> retVec; 
	while (configStream >> cardType){
			int calibNum;
			int numCards;
			while (configStream >> calibNum){
				configStream >> numCards;
				Card *myCardP;
				if (cardType == "SLCCard"){
					myCardP = new SLCCard(theBoard ,calibNum);
				}
				else if (cardType == "NHCard"){
					myCardP = new NHCard(theBoard, calibNum);
				}
				else if (cardType == "AdvanceToGoCard"){
					myCardP = new AdvanceToGoCard(theBoard, name);
				}
				else if (cardType == "GetOutOfJailCard"){
					myCardP = new GetOutOfJailCard(theBoard, name);
					//std::cout << myCardP->name << std::endl;
					//std::cout << name << std::endl;
				}
				else if (cardType == "GoToJailCard"){
					myCardP = new GoToJailCard(theBoard, name);
				}
				else if (cardType == "GrandOperaNightCard"){
					myCardP = new GrandOperaNightCard(theBoard, name);
				}
				else if (cardType == "StreetRepairsCard"){
					myCardP = new StreetRepairsCard(theBoard, name);
				}
				for (int i = 0; i < numCards; ++i){
					retVec.push_back(myCardP);
				}
			}
		configStream.clear();
	}	
	return retVec;
}
