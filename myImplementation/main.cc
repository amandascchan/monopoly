#include "textdisplay.h"
#include "square.h"
#include "board.h" 
#include "player.h"
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]){
	bool testing = false;
	string loadFile = "";
	srand(time());
	for (int i = 1; i < argc; ++i){
		if (argv[i] == "-testing"){
			testing = true;
		}
		if ((argv[i] == "-load")&&(i + 1 < argv)){
			loadFile = argv[i + 1];
		}
	}

	Board theBoard;
	if (loadFile != ""){
		theBoard.loadBoard(loadFile);
	}
	else {
		cout << "enter player names: make sure they match the ones on the spec, type q to finish entering players" << endl;
		string command;
		while(true) {
        	cin >> command;
        	if(command == "q") break;
        	else board.addPlayer(command);
    	}
	}
	board.startGame()
	cout << board;
	bool beginTurn = true;
	while(!theBoard.winner()){
		if (beginTurn){
			cout << board.getNextPlayer(0)->getName() << "'s turn" << endl;
			beginTurn = false;
		}
        string line, command;
        getline(cin,line);
        stringstream commandStream(line);
        commandStream >> command;
		if (command == "roll"){
			int r1, r2;
			if (testing&&(ss >> d1 >> d2)){
				int r1, r2;
				cin >> r1 >> r2
				board.roll(r1, r2);
			}
		}
		else if (command == "next"){
			board.next();
			beginTurn = true;
		}
		else if (command == "trade"){
			string counterParty, give, recieve;
			commandStream >> counterParty >> give >> recieve;
			theBoard.trade(counterParty, give, recieve);
		}
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
			theBoard.mortgage(propertyName);
		}
		else if (command == "bankrupt"){
			theBoard.getNextPlayer(0)->bankrupt();
		}
		else if (command == "assets"){
			theBoard.getNextPlayer(0)->printAssets();
		}
		else if (command == "save"){
			string saveFile;
			commandStream >> saveFile;
			theBoard.save(saveFile);
		}
	}
	cout << theBoard.getNextPlayer(0)->getName() << " Wins!" << endl;
}