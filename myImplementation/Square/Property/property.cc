#include "property.h"
#include <string>
#include <vector>
#include <iostream>
#include "board.h"
#include "player.h"
#include "textdisplay.h"

void Property::auction(){
	Player *highestBidder;
	int highestBid=0;
	int numBidders = theBoard->numPlayers-1;
	std::vector<Player *> bidders;
	bool atleastOneBid = false;
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
			atleastOneBid = true;
			if (bid > highestBid){
				highestBidder = currentBidder;
				highestBid = bid;
			}
			++i;
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
		std::cout << "Sold to " << highestBidder->getName() << "for " << highestBid << " dollars!" << std::endl;
		owner = highestBidder;
		highestBidder->transaction(-highestBid, NULL);
	}
}

void Property::buy(){
	Player *buyer = theBoard->getNextPlayer(0);
	if (buyer->canAfford(price)){
		owner = buyer;
		buyer->transaction(-price, NULL);
	}
	else{
		std::cout << "YOU ARE TOO POOR MUHAHA" << std::endl;
	}
}

void Property::mortgage(){
    isMortgaged = true;
    owner->transaction(price/2);
}

void Property::unMortgage(){
	if (isMortgaged){
		if (owner->canAfford(price*1.1/2)){
			isMortgaged = false;
			owner->transaction(price*1.1/2);
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