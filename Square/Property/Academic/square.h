#ifndef __SQUARE_H__
#define __SQUARE_H__
class TextDisplay;
class Player;
class Academic: public Property {
  std::string block;
  int imCost;
  int tuition[6];
  int rent;
  Player *owner;
  std::string desc;
  TextDisplay * td;        //pointer to the text display

  // Add private members, if necessary (access to Xwindow, location in the window etc)
  //int x, y, width, height;
  //Xwindow * window;

  //void notifyDisplay();					    //notify the TextDisplay of the change

public:
  Square();

};
#endif
