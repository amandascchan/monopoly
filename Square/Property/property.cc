#include "property.h"

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
		std::cout << currentBidder->name << "'s turn to bid/withdraw" << std::endl;
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
		std::cout << "Sold to " << *i->name << "for " << highestBid << " dollars!" << std::endl;
		owner = *i;
		highestBidder->savings -= highestBid;
	}
}

void Property::buy(){
	if (theBoard->getNextPlayer(0)->savings >= price){
		owner = theBoard->getNextPlayer(0);
		theBoard->getNextPlayer(0)->savings -= price;
	}
	else{
		std::cout << "YOU ARE TOO POOR MUHAHA" << std::endl;
	}
}

void Property::unMortgage(){
	if (isMortgaged){
		if (theBoard->getNextPlayer(0)->savings >= price*1.1){
			isMortgaged = false;
			theBoard->getNextPlayer(0)->savings -= price*1.1;
		}
		else{
			std::cout << "YOU ARE TOO POOR MUHAHA" << std::endl;
		}
	}
	else{
		std::cout << "No mortgage to remove." << std::endl;
	}
}

Property::~Property(){}