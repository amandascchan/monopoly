#include "card.h"
#include "slccard.h"
#include "nhcard.h"
#include <string>
#include <vector>
#include "deckBuilder.h"
#include <sstream>
#include <iostream>

std::vector<SLCCard *> deckBuilder::buildDeck(std::string config){
	std::stringstream configStream(config);
	int totalCards;
	configStream >> totalCards;
	std::string cardType;
	std::vector<SLCCard *> retVec; 
	while (configStream >> cardType){
			int calibNum;
			int numCards;
			while (configStream >> calibNum){
				configStream >> numCards;
				SLCCard *myCardP;
				if (cardType == "SLCCard"){
					myCardP = new SLCCard(calibNum);
				}
				if (cardType == "NHCard"){
					myCardP = new NHCard(calibNum);
				}
				for (int i = 0; i < numCards; ++i){
					retVec.push_back(myCardP);
				}
			}
		configStream.clear();
	}	
	return retVec;
}
