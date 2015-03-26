#include "fileread.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

FileRead::FileRead(string fileName): fileName(fileName), {
  ifstream file(fileName);

  for(int i = 0; i < 40; i++) {
    sNames[i] = 0;
    sTypes[i] = 0;
    sDesc[i] = 0;
  }
}

string getSName(int i) {

}


#ifndef __FILEREAD_H__
#define __FILEREAD_H__
#include <iostream>
#include "textdisplay.h"
#include <string>

const int maxNeighbours = 4;

class FileRead {
  //where s means square
  string fileName;
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
