#include "textdisplay.h"
#include <stdlib.h>
#include "square.h"
#include "board.h" 
#include "player.h"
using namespace std;

int main() {
    Board board= Board();
    cout << "enter player names: make sure they match the ones on the spec, type q to finish entering players" << endl;    
    while(true) {
        string command;
        cin >> command;
        if(command == "q") break;
        board.addPlayer(command);
    }
    board.printPlayers();
    cout << board << endl;
    for(int i = 0; i < 40; i++) {
        cout << "square name: " << board.getSquare(i)->getName() << endl;
        cout << "square cost: " << board.getSquare(i)->getCost() << endl;
    }
    cout << board;
    cout << "you can roll, or type next for next player, or type q to quit" << endl;
    while(true) {
        string command;
        cin >> command;
        if(command == "q") break;
        else if(command == "roll") 
        {
            board.Roll();
        }
        else if(command == "next") 
        {
            board.next();
            cout << board;
        }
        else if(command == "q") break;
       
    }
}
