#ifndef __SQUARE_H__
#define __SQUARE_H__
#include <iostream>
#include <string>

class Board;
class TextDisplay;

class Square {
	friend class Board;
	friend class Player;
protected:
	std::string name;
	Board *theBoard;
	int row, column;              //co-ordinates of the cell
	TextDisplay * td; 
    int index;
	       //pointer to the text display
  	// Add private members, if necessary (access to Xwindow, location in the window etc)
  	//int x, y, width, height;
	//Xwindow * window;

	//void notifyDisplay();					    //notify the TextDisplay of the change
public:
	Square(Board *, TextDisplay *);
	std::string getName();
	void setPosition(int, int);
	virtual void action()=0;
	virtual ~Square();
	void setDisplay(TextDisplay * t);         //setter for TextDisplay
	int getIm(int i);
    int getCost();
  	int getImCost();
    std::string getBlock();
    std::string getDesc();
	int getRent();
};
#endif
