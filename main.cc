#include "Board/board.h" 
#include "TextDisplay/textdisplay.h"
#include "Square/square.h"
#include "Player/player.h"
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <stdexcept>

using namespace std;
void printError(string name) {
    if(name == "a") cout << "Open yo eyes and look accurately at the avatar selections" << endl;
    else if(name == "p") cout << "Not valid name of property: Spelling of properties are as listed on board" << endl;

}

int main(int argc, char *argv[]){
	bool testing = false;
	string loadFile = "";
	srand(time(0));
	for (int i = 1; i < argc; ++i){
		if (strcmp(argv[i], "-testing") == 0){
			testing = true;
		}
		if ((strcmp(argv[i],"-load") == 0)&&(i + 1 < argc)){
			loadFile = argv[i + 1];
		}
	}

	Board theBoard;
	if (loadFile != ""){
		theBoard.loadBoard(loadFile);
	}
	else {
		cout << "enter player names on seperate lines: make sure they match the ones on the spec, type q to finish entering players" << endl;
		string line;
		while(true) {
        	getline(cin,line);
        	if(line == "q") break;
        	else {
                try {
                    theBoard.addPlayer(line.substr(0, line.size()-1), line[line.length()-1]);
                } catch(invalid_argument& e) {
                    printError("a");
                }
            }
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
		else if (command == "trade"){
			string counterParty, give, recieve, response;
			commandStream >> counterParty >> give >> recieve;
			theBoard.trade(counterParty, give, recieve, true);
		}
		else if (command == "improve"){
			string propertyName, buyOrSell;
			commandStream >> propertyName >> buyOrSell;
			theBoard.improve(propertyName, buyOrSell);
		}		
		else if (command == "mortgage"){
			string propertyName;
            commandStream >> ws;
			getline(commandStream, propertyName);
            try {
			    theBoard.mortgage(propertyName);
            } catch(...) {
                printError("p");
            }
		}
		else if (command == "unmortgage"){
			string propertyName;
            commandStream >> ws;
			commandStream >> propertyName;
            getline(commandStream, propertyName);
            try {
            theBoard.unmortgage(propertyName);
            } catch(...) {
                printError("p");
            }
		}
		else if (command == "bankrupt"){
			theBoard.bankrupt();
		}
		else if (command == "assets"){
			theBoard.getNextPlayer(0)->displayAssets();
		}
		else if (command == "save"){
			string saveFile;
			commandStream >> saveFile;
			theBoard.save(saveFile);
		}
	}
	cout << theBoard.getNextPlayer(0)->getName() << " Wins!" << endl;
}
