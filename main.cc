#include "textdisplay.h"
#include "square.h"
#include "board.h" 
#include "player.h"
using namespace std;

int main() {
    Board board= Board();
    for(int i = 0; i < 40; i++) {
        cout << board.getSquare(i)->getName() << endl;
        cout << board.getSquare(i)->getCost() <<endl;
    }

    cout << board;
}
