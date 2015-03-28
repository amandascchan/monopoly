#ifndef __SQUARE_H__
#define __SQUARE_H__
#include <iostream>
#include "textdisplay.h"
#include <string>
class Square {
  std::string name;
  int r, c;                   //co-ordinates of the cell
  std::string block;
  int cost;
  int imCost;
  int im[6];

  TextDisplay * td;        //pointer to the text display

  // Add private members, if necessary (access to Xwindow, location in the window etc)
  //int x, y, width, height;
  //Xwindow * window;

  //void notifyDisplay();					    //notify the TextDisplay of the change

public:
  Square();                                   // Default constructor

  void setCoords(const int r, const int c);				//setter for private co-ordinates of cell

  void setDisplay(TextDisplay * t);         //setter for TextDisplay
  void setName(std::string name);

  void setIm(int i, int cost);
  int getIm(int i);
  void setCost(int cost);
  int getCost();
  void setImCost(int cost);
  int getImCost();
  std::string getName();
  void setBlock(std::string name);
  std::string getBlock();

};
#endif
