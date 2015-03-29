#include <string>
#include <vector>
#include <iostream>

int main(){
	std::string highestBidder;
	int highestBid=-1;
	int numBidders = 3;
	std::string name;
	std::vector<std::string> bidders;
	bool atleastOneBid = false;
	for (int i = 1; i <= numBidders; ++i){
		std::cout << "bidder name " << i << std::endl;
		std::cin >> name;
		bidders.push_back(name);
	}
	std::vector<std::string>::iterator i = bidders.begin();
	while (numBidders > 1){
		int bid;
		std::string command;
		std::string currentBidder = *i;
		std::cout << currentBidder << "'s turn to bid/withdraw" << std::endl;
		if (std::cin >> bid){
			atleastOneBid = true;
			if (bid > highestBid){
				highestBidder = currentBidder;
				highestBid = bid;
				std::cout << highestBid << std::endl;
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
	if (atleastOneBid){
		std::cout << "Sold to " << highestBidder << "!" << std::endl;
	}
	else{
		std::cout << "Not Sold!!!" << std::endl;
	}
}