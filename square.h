#ifndef __SQUARE_H__
#define __SQUARE_H__
class TextDisplay;
class Player;
class Square {
  std::string name;
  std::string block;
  int cost;
  int imCost;
  int im[6];
  Player *owner;
  std::string desc;

  TextDisplay * td;        //pointer to the text display

  // Add private members, if necessary (access to Xwindow, location in the window etc)
  //int x, y, width, height;
  //Xwindow * window;

  //void notifyDisplay();					    //notify the TextDisplay of the change

public:
  Square();                                   // Default constructor
  int row, column;

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
  void setDesc(std::string desc);
  std::string getDesc();
  void setOwner(Player *);

};
#endif
