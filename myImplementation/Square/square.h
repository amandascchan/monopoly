#ifndef __SQUARE_H__
#define __SQUARE_H__
#include <iostream>
#include "textdisplay.h"
#include <string>
class Square {
	std::string name;
	Board *theBoard;
	int row, column;              //co-ordinates of the cell
	TextDisplay * td;        //pointer to the text display
  	// Add private members, if necessary (access to Xwindow, location in the window etc)
  	//int x, y, width, height;
	//Xwindow * window;

	//void notifyDisplay();					    //notify the TextDisplay of the change
public:
	Square(Board *, TextDisplay *);
	virtual void action()=0;
	virtual ~Square();
};
#endif
