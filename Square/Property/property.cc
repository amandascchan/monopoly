#include "property.h"
#include <string>
#include <vector>
#include <iostream>
#include "../../Board/board.h"
#include "../../Player/player.h"
#include "../../TextDisplay/textdisplay.h"

Property::Property(Board *theBoard, TextDisplay *td):Square(theBoard, td), isMortgaged(false), owner(NULL){}

int Property::getCost(){
	return price;
}

bool Property::getIsMortgaged(){
	return isMortgaged;
}

void Property::auction(){
	isMortgaged = false;
	std::cout << "Auction time!" << std::endl;
	//Player *highestBidder;
	int highestBid=0;
	int numBidders = theBoard->getNumPlayers()-1;
	std::vector<Player *> bidders;
	//bool atleastOneBid = false;
	for (int i = 1; i <= numBidders; ++i){
		bidders.push_back(theBoard->getNextPlayer(i));
	}
	std::vector<Player *>::iterator i = bidders.begin();
	while (numBidders > 1){
		int bid;
		string command;
		Player *currentBidder = *i;
		std::cout << currentBidder->getName() << "'s turn to bid/withdraw" << std::endl;
		if (std::cin >> bid){
	//		atleastOneBid = true;
			if (bid > highestBid){
			//	highestBidder = currentBidder;
				highestBid = bid;
				++i;
			}
			else {
				bidders.erase(i);
				--numBidders;
				std::cout << currentBidder->getName() << " is disqualified for not raising the bid." << std::endl;
			}
			if (i == bidders.end()){
				i = bidders.begin();
			}
		}
		else{
			std::cin.clear();
			std::cin >> command;
			if (command == "withdraw"){
				bidders.erase(i);
				--numBidders;
			}
			if (i == bidders.end()){
				i = bidders.begin();
			}
		}
	}
	if (numBidders == 1){
		std::cout << "Sold to " << (*i)->getName() << " for " << highestBid << " dollars!" << std::endl;
		owner = *i;
		(*i)->transaction(-highestBid, NULL);
		owner->addProperty(this);
	}
}

std::string Property::getBlock(){
	return block;
}

void Property::buy(){
	cout << "Would you like to buy this property named " << name  << " for $" << price << "? (yes/no)" << endl;
    string answer;
    while (cin >> answer){
    	if ((answer == "yes")||(answer == "no"))break;
    }
    if (answer == "yes"){
		Player *buyer = theBoard->getNextPlayer(0);
		if (buyer->canAfford(price)){
			owner = buyer;
			owner->addProperty(this);
			buyer->transaction(-price, NULL);
		}
		else{
			std::cout << "YOU ARE TOO POOR MUHAHA" << std::endl;
		}
    }
    else if (answer == "no") auction();
}

void Property::mortgage(){
    isMortgaged = true;
    owner->transaction(price/2, NULL);
}

void Property::unMortgage(){
	if (isMortgaged){
		int fee = (price*1.1)/2;
		if (owner->canAfford(fee)){
			isMortgaged = false;
			owner->transaction(-fee, NULL);
		}
		else {
			std::cout << "YOU ARE TOO POOR MUHAHA" << std::endl;
		}
	}
	else {
		std::cout << "No mortgage to remove." << std::endl;
	}
}

Property::~Property(){}
