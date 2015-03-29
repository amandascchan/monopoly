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
    board.movePlayer(4);
    board.movePlayer(10);
    board.movePlayer(1);
    board.movePlayer(1);
    board.movePlayer(12);
    board.movePlayer(11);
    board.movePlayer(-22);
    board.movePlayer("ML");
    board.movePlayer("COLLECT OSAP");
    board.movePlayer("SLC");
    board.movePlayer("DC Tims Line");
    board.movePlayer("TUITION");
    board.movePlayer("DC");
    board.movePlayer(-9);
    cout << "Next players" << endl;
    cout << board.getNextPlayer(1)->getName() << endl;
    cout << board.getNextPlayer(2)->getName() << endl;
    cout << board.getNextPlayer(9)->getName() << endl;
    cout << board << endl;
}
