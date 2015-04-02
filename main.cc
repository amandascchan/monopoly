#include "Board/board.h" 
#include "TextDisplay/textdisplay.h"
#include "Square/square.h"
#include "Player/player.h"
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]){
	bool testing = false;
	string loadFile = "";
	srand(time(0));
	for (int i = 1; i < argc; ++i){
		if (strcmp(argv[i], "-testing") == 0){
			testing = true;
		}
		if ((argv[i] == "-load")&&(i + 1 < argc)){
			loadFile = argv[i + 1];
		}
	}

	Board theBoard;
	if (loadFile != ""){
		//theBoard.loadBoard(loadFile);
	}
	else {
		cout << "enter player names: make sure they match the ones on the spec, type q to finish entering players" << endl;
		string command;
		while(true) {
        	cin >> command;
        	if(command == "q") break;
        	else theBoard.addPlayer(command);
    	}
	}
	theBoard.startGame();
	cout << theBoard;
	bool beginTurn = true;
	Player *currentPlayer;
	bool hasRolled = false;
	while(!theBoard.winner()){
		if (beginTurn){
			currentPlayer = theBoard.getNextPlayer(0);
			cout << currentPlayer->getName() << "'s turn" << endl;
			beginTurn = false;
		}
        string line, command;
        getline(cin,line);
        stringstream commandStream(line);
        commandStream >> command;
		if (command == "roll"){
			if (!hasRolled){
				int r1, r2;
				if (testing&&(commandStream >> r1)){
					if (!(commandStream >> r2))r2 = 0;
				}
				else {
					r1 = rand() % 6 + 1;
					r2 = rand() % 6 + 1;
				}
				theBoard.Roll(r1 + r2);
				hasRolled = true;
			}
			else {
				cout << "You have already rolled this turn." << endl;
			}
		}
		else if (command == "next"){
			if (currentPlayer->canAfford(0)){
                cout << theBoard;
				theBoard.next();
				beginTurn = true;
				hasRolled = false;
			}
			else {
				cout << "You can not end your turn until you have paid your debt." << endl;
			}
		}
		/*else if (command == "trade"){
			string counterParty, give, recieve;
			commandStream >> counterParty >> give >> recieve;
			theBoard.trade(counterParty, give, recieve);
		}*/
		else if (command == "improve"){
			string propertyName, buyOrSell;
			commandStream >> propertyName >> buyOrSell;
			theBoard.improve(propertyName, buyOrSell);
		}		
		else if (command == "mortgage"){
			string propertyName;
			commandStream >> propertyName;
			theBoard.mortgage(propertyName);
		}
		else if (command == "unmortgage"){
			string propertyName;
			commandStream >> propertyName;
			theBoard.unmortgage(propertyName);
		}
		else if (command == "bankrupt"){
			theBoard.getNextPlayer(0)->Bankrupt();
		}
		else if (command == "assets"){
			theBoard.getNextPlayer(0)->displayAssets();
		}
	/*	else if (command == "save"){
			string saveFile;
			commandStream >> saveFile;
			theBoard.save(saveFile);
		}*/
	}
	cout << theBoard.getNextPlayer(0)->getName() << " Wins!" << endl;
}