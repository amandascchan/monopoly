#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <sstream>
#include <string>
extern const std::string names[];
extern const bool prop[];
class TextDisplay {
  char **theDisplay;          //the n x n display 

  /*
   * The following field helps track how the game as progressed
   * The field should track how much Cells of the grid are of each color
   * Whenever a Cell changes color, the corresponding color count should
   * be updated.
   */
  void drawBox(int row, int column, std::string name, bool property);
  void init();
 public:
  TextDisplay(); //one arg constructor where the parameter is the gridSize

  /*
   * The TextDisplay is an observer of each Cell. Cells call notify to 
   * update the (r,c) location to be ch
   */
  void notify(int r, int c, char ch);  

	
  ~TextDisplay(); //dtor

  friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
