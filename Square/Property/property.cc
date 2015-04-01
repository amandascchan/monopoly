#include "property.h"
#include <string>
#include <vector>
#include <iostream>
#include "../../Board/board.h"
#include "../../Player/player.h"
#include "../../TextDisplay/textdisplay.h"

Property::Property(Board *theBoard, TextDisplay *td): Square(theBoard, td),
					owner(NULL), isMortgaged(false){}

void Property::auction(){
	std::cout << "Auction time!" << std::endl;
	Player *highestBidder;
	int highestBid=0;
	int numBidders = theBoard->getNumPlayers()-1;
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

std::string Property::getBlock(){
	return block;
}

void Property::buy(){
	cout << "Would you like to buy this property (yes/no)" << endl;
    string answer;
    cin >> answer;
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
		if (owner->canAfford(price*1.1/2)){
			isMortgaged = false;
			owner->transaction(price*1.1/2, NULL);
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