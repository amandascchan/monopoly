#include "tcup.h"
#include "../Player/player.h"
using namespace std;
TCUP::TCUP():numCups(4){}
void TCUP::giveCup(Player *p) {
    if(numCups >= 1) {
        p->cups++;
        numCups--;
    }else {
        cout << "all 4 cups are out on the board" << endl;
    }
}
void TCUP::returnCup(Player *p) {
    numCups++;
    p->cups--;
}
