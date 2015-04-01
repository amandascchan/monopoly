#include "../Card/card.h"
#include "../Card/slccard.h"
#include "../Card/nhcard.h"
#include "deckbuilder.h"
#include <sstream>
#include <iostream>

deckBuilder::deckBuilder(Board *theBoard): theBoard(theBoard){}

std::vector<Card *> deckBuilder::buildDeck(std::string config){
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
				if (cardType == "NHCard"){
					myCardP = new NHCard(theBoard, calibNum);
				}
				for (int i = 0; i < numCards; ++i){
					retVec.push_back(myCardP);
				}
			}
		configStream.clear();
	}	
	return retVec;
}
