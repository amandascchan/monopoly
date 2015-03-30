#include "textdisplay.h"
#include "square.h"
#include "board.h" 
#include "player.h"
#include <cstring>
#include <sstream>
#include <ncurses.h>
using namespace std;

int main(int argc, char *argv[]) {
    initscr();

    bool autoRoll = false;
    if(argc > 1) autoRoll = (strcmp(argv[1],"-testing")==0)? true : false;
    Board board= Board();
     board.printBoard();
     char mesg[] = "enter player names: make sure they match the ones on the spec, type q to finish entering players\n";
     addstr(mesg);
     refresh();
     while(true) {
        string command;
        char line[10000];
        //getline(cin,line);
        getstr(line);
        int x,y;
        getyx(stdscr, y,x);
        move(y,0);
        clrtoeol();
        move(y,x);
        stringstream ss(line);
        ss >> command;
        if(command == "q") break;
        else if(command == "Goose") {
            //Travis!! Please read these comments!!
            //This is an example for loading a game, adding players,
            //when the player name is Goose
            char m;
            int mm;
            int TC;
            int pos;
            ss >> m >> mm >> TC >> pos;
            board.addPlayer("Goose", m, mm, TC, pos);
            board.getAPlayer()->displayAssets();

        }
        else board.addPlayer(command);
    }
    //Hey Travis, this startGame function lets you know if there is at least one player 
    //to start the game with
   // (board.startGame())? cout << board : false;

    //Here we are printing out all the squares and their associaed costs

    /* Hey Travis, feel free to test these out:
     * the board.movePlayer(number) moves the active player number moves from where they are, even
     * negative.
     * the board.movePlayer(string) moves them to the specific location, if > 1 exists, it moves them to the first one on the board
     * the board.getNextPlayer(number) gets a pointer to the player number turns away, even negative.
     * */
    clear();
    board.printBoard();
    addstr("you can roll, or type next for next player, or type q to quit\n");
    printw(mesg);
    refresh();
    while(true) {
        string command;
        char line[1000];
        getstr(line);
        stringstream ss(line);
        ss >> command;
        if(command == "q") break;
        else if(command == "roll") 
        {
            int d1, d2;
            if(autoRoll && (ss >> d1 >> d2)) {
                board.Roll(d1+d2);
                continue;
            }
           board.Roll();
        }
        else if(command == "next") 
        {
            clear();
            board.next();
            board.printBoard();
        }
        else if(command == "q") break;
        else if(command == "AL") {
            string o1;
            int n;
            ss >> o1 >> n;
            //example for loading a game adding properties
            board.addProperty("AL", "Goose", 3);
            board.getPlayer("Goose")->displayAssets();
        }
    }
}
