#include "player.h"
#include "slccard.h"
#include "nhcard.h"
#include <string.h>
#include <vector.h>
#include "deckBuilder.h"
#include <sstream.h>

vector<Card *> deckBuilder::buildDeck(String config){
	std::StringStream configStream(config);
	int totalCards;
	configStream >> totalCards;
	String cardType;
	vector<Card *> retVec; 
	while (configStream >> cardType){
			int calibNum;
			int numCards;
			while (configStream >> moves){
				configStream >> numCards;
				Card *myCardP;
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
	}	
	return retVec;
}