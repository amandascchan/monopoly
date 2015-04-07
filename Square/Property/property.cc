#include "property.h"
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include "../../Board/board.h"
#include "../../Player/player.h"
#include "../../TextDisplay/textdisplay.h"
#include <ncurses.h>

Property::Property(Board *theBoard, TextDisplay *td):Square(theBoard, td), isMortgaged(false), owner(NULL){}

int Property::getCost(){
	return price;
}

bool Property::getIsMortgaged(){
	return isMortgaged;
}

void Property::auction(){
	isMortgaged = false;
#ifndef toilet
	std::cout << "Auction time!" << std::endl;
#endif
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
#ifndef toilet
		std::cout << currentBidder->getName() << "'s turn to bid/withdraw" << std::endl;
#endif
		while (true){
			if (std::cin >> bid){
			if (!currentBidder->canAfford(bid)){
#ifndef toilet
				cout << "YOU ARE TOO POOR MUHAHA" << endl;
#endif
				continue;
			}
			//atleastOneBid = true;
			if (bid > highestBid){
			//	highestBidder = currentBidder;
				highestBid = bid;
				++i;
			}
			else {
				bidders.erase(i);
				--numBidders;
#ifndef toilet
				std::cout << currentBidder->getName() << " is disqualified for not raising the bid." << std::endl;
#endif
			}
			if (i == bidders.end()){
				i = bidders.begin();
			}
			break;
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
			break;
		}
	}
	}
	if (numBidders == 1){
#ifndef toilet
		std::cout << "Sold to " << (*i)->getName() << " for " << highestBid << " dollars!" << std::endl;
#endif
		owner = *i;
		theBoard->giveDebt(owner, highestBid, NULL);
		owner->addProperty(this);
	}
}

std::string Property::getBlock(){
	return block;
}

void Property::buy(){
string answer;
#ifndef toilet
	cout << "Would you like to buy this property named " << name  << " for $" << price << "? (yes/no)" << endl;
#endif

#ifdef toilet
    string temp =  "Would you like to buy this property named " + name +"? (yes/no)";
    addstr(temp.c_str());
    refresh();
        char line[10000];
        getstr(line);
        doupdate();
        int x,y;
        getyx(stdscr, y,x);
        move(y,0);
        clrtoeol();
        move(y,x);
        stringstream ss(line);
#endif
    #ifndef toilet
    while (cin >> answer){
    #endif
    #ifdef toilet
    while(ss >> answer) {
    #endif
    	if ((answer == "yes")||(answer == "no"))break;

    }
    if (answer == "yes"){
		Player *buyer = theBoard->getNextPlayer(0);
		if (buyer->canAfford(price)){
			owner = buyer;
			owner->addProperty(this);
			theBoard->giveDebt(buyer, price, NULL);
		}
		else{
#ifndef toilet
			std::cout << "YOU ARE TOO POOR MUHAHA" << std::endl;
#endif
		}
    }
    else if (answer == "no") auction();
}

void Property::mortgage(){
#ifndef toilet
   // cout << "why" << endl;
#endif
	if (!isMortgaged){
		isMortgaged = true;
    	theBoard->giveMoney(owner, price/2);

	}
	else {
#ifndef toilet
		std::cout << "Already mortgaged." << std::endl;
#endif
	}
}

void Property::action(){
  if (owner == NULL){
    buy();
  }
  else {
    if (!isMortgaged){
      Player *currentPlayer = theBoard->getNextPlayer(0);
      if (currentPlayer != owner){
        theBoard->giveDebt(currentPlayer,getRent(), owner);
      }
    }
  }
}

void Property::unMortgage(){
	if (isMortgaged){
		int fee = (price*1.1)/2;
		if (owner->canAfford(fee)){
			isMortgaged = false;
			theBoard->giveDebt(owner, fee, NULL);
		}
		else {
#ifndef toilet
			std::cout << "YOU ARE TOO POOR MUHAHA" << std::endl;
#endif
		}
	}
	else {
#ifndef toilet
		std::cout << "No mortgage to remove." << std::endl;
#endif
	}
}

Property::~Property(){}
