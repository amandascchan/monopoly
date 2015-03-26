#ifndef __FILEREAD_H__
#define __FILEREAD_H__
#include <iostream>
#include "textdisplay.h"
#include <string>

const int maxNeighbours = 4;

class FileRead {
  //where s means square
  string sNames[40]; //temporary, property names
  string sTypes[40]; //temporary
  string sDesc[40]; //square descriptions.
  string fileName;
  //figure out card stuff later
  int lineNumber;
public:
  FileRead(string fileName);
  string getSName(int i);
  string getSType(int i);
  string getSDesc(int i);

};
#endif
