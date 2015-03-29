#include "textdisplay.h"
#include <stdlib.h>
#include <unistd.h>
#include "square.h"
#include "board.h" 
#include "player.h"
#include "academic.h"
using namespace std;

int main(void) {
    Board board= Board();
    for(int i = 0; i < 40; i++) {
        cout << board.getSquare(i)->getCost() <<endl;
    }
    board.printPlayers();
    for(int i = 0; i < 40;i++) {
        board.Roll();
    }
    board.movePlayer("DC Tims Line");
    cout << board;

    cout << "get square method" << endl;
    cout << board.getSquare("ML")->getName() << endl;
    cout << board.getSquare("fdsfsds")->getName()<< endl;
}
