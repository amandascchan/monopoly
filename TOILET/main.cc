#include "Board/board.h" 
#include "TextDisplay/textdisplay.h"
#include "Square/square.h"
#include "Player/player.h"
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <map>
#include <stdexcept>
#include <ncurses.h>
#include <list>
using namespace std;

class snake {
  private:
    int x, y;
  public:
    snake(int a, int b) {
      x = a;
      y = b;
    }
    int getX() { return x; }
    int getY() { return y; }
};  


void printError(string name) {
	if(name == "a") {
        #ifdef toilet
        addstr( "Open yo eyes and look accurately at the avatar selections" );
        addch('\n');
        #endif
        #ifndef toilet
        cout << "Open yo eyes and look accurately at the avatar selections" << endl;
        #endif
    }
	else if(name == "p") {
        #ifdef toilet
        addstr("Not valid name of property: Spelling of properties are as listed on board" );
        addch('\n');
        #endif
        #ifndef toilet
       cout << "Not valid name of property: Spelling of properties are as listed on board" << endl;
        #endif
    }

}
int main(int argc, char *argv[]){
#ifdef toilet
    initscr();
#endif
	bool testing = false;
	string loadFile = "";
	srand(time(0));
	map<string , bool> modeMap;
	for (int i = 1; i < argc; ++i){
		if (strcmp(argv[i], "-testing") == 0){
			testing = true;
		}
		if ((strcmp(argv[i],"-load") == 0)&&(i + 1 < argc)){
			loadFile = argv[i + 1];
		}
		if (strcmp(argv[i],"-bruceWayne") == 0){
			modeMap["Bruce Wayne"] = 1;
		}
		if (strcmp(argv[i],"-richGoose") == 0){
			modeMap["richGoose"] = 1;
		}
		if (strcmp(argv[i],"-goose") == 0){
			modeMap["goose"] = 1;
		}
		if (strcmp(argv[i],"-doubleOSAP") == 0){
			modeMap["doubleOSAP"] = 1;
		}
		if (strcmp(argv[i],"-communityChest") == 0){
			modeMap["communityChest"] = 1;
		}
		if (strcmp(argv[i],"-chance") == 0){
			modeMap["chance"] = 1;
		}
	}
	Board *theBoard = Board::getDaBoard(modeMap);
	if (loadFile != ""){
		theBoard->loadBoard(loadFile);
	}
	else {
        string line;
		while(true) {
        #ifdef toilet
            addstr( "enter player names on seperate lines followed by piece Chars: make sure they match the ones on the spec, type q to finish entering players" );
            addch('\n');
	        char l1[10000];
            getstr(l1);
            doupdate();
            int x,y;
            getyx(stdscr, y, x);
            move(y,0);
            clrtoeol();
            move(y,x);
            stringstream ss(l1);
            getline(ss,line);
        #endif
        #ifndef toilet
             cout <<  "enter player names on seperate lines followed by piece Chars: make sure they match the ones on the spec, type q to finish entering players"  << endl;
            getline(cin, line);
        #endif
        	if(line == "q") break;
        	else {
                try {
                    theBoard->addPlayer(line.substr(0, line.size()-2), line[line.length()-1]);
                } catch(invalid_argument& e) {
                    printError("a");
                }
            }
    	}
	}
	theBoard->startGame();
    #ifndef toilet
       cout << theBoard;
    #endif
    #ifdef toilet
       clear();
        theBoard->printBoard();
        refresh();
    #endif


	bool beginTurn = true;
	Player *currentPlayer;
	bool hasRolled = false;
    int doublesCount = 0;
	while(!theBoard->winner()){
		if (beginTurn){
			currentPlayer = theBoard->getNextPlayer(0);
            #ifdef toilet
                addstr( "Player's turn\n" );
            #endif 
            #ifndef toilet
			    cout << currentPlayer->getName() << "'s turn" << endl;
            #endif
			beginTurn = false;
		}
        string line, command;
        #ifndef toilet
            getline(cin,line);
        #endif
        #ifdef toilet
            char l1[10000];
            getstr(l1);
            doupdate();
            int x,y;
            getyx(stdscr, y, x);
            move(y,0);
            clrtoeol();
            move(y,x);
            stringstream ss(l1);
            getline(ss,line); 
        #endif 
        stringstream commandStream(line);
        commandStream >> command;
       
		if (command == "roll"){
            clear();
			if (!hasRolled){
				int r1, r2;
				if (testing&&(commandStream >> r1)){
					if (!(commandStream >> r2))r2 = 0;
				}
				else {

#ifdef toilet
 noecho();
  curs_set(0);
  keypad(stdscr, TRUE);
  timeout(100);
  
  list<snake> snakes;
  list<snake>::iterator it;
  bool quit = false;
  int points = 0;
  int dir = 2;
  int food_x = rand() % 80 + 1;
  int food_y = rand() % 24 + 1;
  int ch;
    
  for(int i = 0; i < 5; i++)  // generate start snake
    snakes.push_front(snake(3+i,3));
  
  while(!quit) {
      // Input
      ch = getch();
      switch(ch) {
        case KEY_UP:
          dir = 1;
          break;
        case KEY_RIGHT:
          dir = 2;
          break;
        case KEY_DOWN:
          dir = 3;
          break;
        case KEY_LEFT:
          dir = 4;
          break;
        case 'q':
          quit = true;
          break;
      }
      
      // Logic
      snake logic = snakes.front();
      int x = logic.getX();
      int y = logic.getY();
      if(dir == 1) y--; // move up
      else if(dir == 2) x++;  // move right
      else if(dir == 3) y++;  // move down
      else if(dir == 4) x--;  // move left
      
      snakes.push_front(snake(x, y));
      
      if(x == food_x && y == food_y) {
        food_x = rand() % 80;
      food_y = rand() % 24;
      points++;
      } else 
        snakes.pop_back();
        
      if(y > 24 || x > 80 || y < 0 || x < 0)  // collision with border
        quit = true;
        
      // Output
      erase();
      mvaddch(food_y,food_x,'X');
      for(it = snakes.begin(); it != snakes.end(); it++) {
        mvaddch((*it).getY(),(*it).getX(),'o');
        if((*it).getY() == y && (*it).getX() == x && it != snakes.begin())  // collision with snake
          quit = true;
      }
      mvprintw(0, 0, "You got %i points. 'q' to quit.\n", points);
      refresh();
    }
    timeout(-1);
    erase();
    mvprintw(0, 0, "You lost and gained a total of %i points.\n", points);
clear();
r1 = points + 3 %6;
r2 = points + 5%6;
addstr("Your roll was determined by your points in the snake game");
addch('\n');
    refresh();
#endif
					#ifndef toilet
                    r1 = rand() % 6 + 1;
					r2 = rand() % 6 + 1;
                    #endif
                    #ifndef toilet
                         cout << "You rolled: " << r1 << " and " << r2 << endl; 
                    #endif
				}
				if (theBoard->getNextPlayer(0)->isInTLine()){
                    clear();
                    #ifndef toilet
					    cout << theBoard->getNextPlayer(0)->getName() << " is in Tims Line" << endl; 
                    #endif
                    #ifdef toilet
                        addstr("Player is in Tims Line");
                        addch('\n');
                    #endif
					theBoard->inTLine(r1,r2);
                    doublesCount = 0;
                    hasRolled = true;
                    refresh();
				}
                else if(r1 == r2 && doublesCount < 2) {
                    #ifndef toilet
                    cout << "You rolled doubles, roll again" << endl;
                    #endif
                    #ifdef toilet
                    addstr("You rolled doubles, roll again");
                    addch('\n');
                    #endif
                    doublesCount++;
                }
                else if(r1 == r2 && doublesCount == 2) {
                    clear();
                    #ifndef toilet
                    cout << "Sorry, we are sending you to DC Tims Line" << endl;
                    #endif
                    #ifdef toilet
                    addstr("Sorry we are sending you to DC Tims Line");
                    addch('\n');
                    #endif
                    refresh();
                    theBoard->movePlayer("GO TO TIMS");
                    doublesCount = 0;
                    hasRolled = true;
                }
                else if(!theBoard->getNextPlayer(0)->isInTLine()){
                    theBoard->Roll(r1 + r2);
				    hasRolled = true;
                }
			}
			else {
                #ifndef toilet
				 cout << "You have already rolled this turn." << endl;
                 addch('\n');
                #endif
                #ifdef toilet
                addstr("You have already rolled this turn." );
                addch('\n');
                #endif
			}
		}
		else if (command == "next"){
            clear();
			if (!hasRolled){
                #ifndef toilet
                cout << "You can not end your turn until you have rolled." << endl;
                #endif
                #ifdef toilet
                addstr("You cannot end your turn until you have rolled\n");
                addch('\n');
                #endif
            }
			else if (!currentPlayer->hasDebt()){
                #ifndef toilet 
                cout << theBoard;
                #endif
				theBoard->next();
				beginTurn = true;
				hasRolled = false;
			}
			else {
				#ifndef toilet 
                cout << "You can not end your turn until you have paid your debt." << endl;
                #endif
			}
		}
		else if (command == "trade"){
			string counterParty, give, recieve, response;
			commandStream >> counterParty >> give >> recieve;
			theBoard->trade(counterParty, give, recieve, true);
		}
		else if (command == "improve"){
			string propertyName, buyOrSell;
			commandStream >> propertyName >> buyOrSell;
			theBoard->improve(propertyName, buyOrSell);
		}		
		else if (command == "mortgage"){
			string propertyName;
            commandStream >> ws;
			getline(commandStream, propertyName);
            try {
			    theBoard->mortgage(propertyName);
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
            theBoard->unmortgage(propertyName);
            } catch(...) {
                printError("p");
            }
		}
		else if (command == "bankrupt"){
			if (theBoard->getNextPlayer(0)->canAfford(0)){
				#ifndef toilet 
                cout << "You can not declare bankruptcy as you do not have debt you can not pay." << endl;
                #endif
                #ifdef toilet
                addstr("you can't declare bankrupty as you have debt you cannot pay\n");
                #endif
			}
			else{
				theBoard->bankrupt();
				beginTurn = true;
				hasRolled = false;
			}
		}
		else if (command == "assets"){
			if (!(currentPlayer->payingTuition())){
                #ifndef toilet
				theBoard->getNextPlayer(0)->displayAssets();
                #endif
                #ifdef toilet
                clear();
                theBoard->getNextPlayer(0)->displayAssetsN();
                refresh();
                #endif
			}
			else {
				#ifndef toilet 
                cout << "You can not view your assets until you have paid your tuition." << endl;
                #endif
			}
		}
		else if (command == "save"){
			if (!(currentPlayer->hasDebt())){
				#ifndef toilet 
                cout << "You can not save until you have paid your debt." << endl;
                #endif
			}
			else {
				string saveFile;
				commandStream >> saveFile;
				theBoard->save(saveFile);
			}
		}
		else if (command == "board"){
			#ifndef toilet 
            cout << theBoard;
            #endif
		}
#ifdef toilet
        refresh();
        theBoard->printBoard();
#endif

	}
	#ifndef toilet 
        cout << theBoard->getNextPlayer(0)->getName() << " Wins!" << endl;
    #endif
    #ifdef toilet
        addstr("Whoo!");
    #endif
}

