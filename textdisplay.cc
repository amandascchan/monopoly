#include <iostream>
#include <sstream>
#include "textdisplay.h"
#include <string>
#include <string.h>
#include <stdlib.h>
using namespace std;

const string names[] = {"Goose Nesting", "EV1", "NEEDLES HALL", "EV2", "EV3", "V1","PHYS","B1", "CIF", "B2", "GO TO TIMS", "OPT", "EIT", "BMH", "ESC", "SLC", "SLC", "LHI", "C2", "UWP", "REV", "CPH", "NEEDLES HALL", "DWE", "MC", "PAC", "COOP FEE", "RCH", "DC", "DC Tims Line", "HH","PAS", "NEEDLES HALL", "ECH", "MKV", "TUITION", "ML", "SLC", "AL", "COLLECT OSAP"};
const bool prop[] = {false, true, false, true, true, false, true, true, false, true, false, true,true, true, true, false, false, true, true, false, false, true, false, true, true, false,false, true, true, false, true, true, false, true, false, false, true, false, true, false};
TextDisplay::TextDisplay(): theDisplay(NULL)  {
  theDisplay = new char *[56];
  for(int i = 0; i < 56; i++) {
    theDisplay[i] = new char [90];
    for(int j = 0; j < 90; j++) {
        theDisplay[i][j] = ' ';
    }
  }
  init();
}

TextDisplay::~TextDisplay() {
  for(int i = 0; i < 56; i++) {
    delete [] theDisplay[i];
  }
  delete [] theDisplay;
}

void TextDisplay::init() {
    for(int i = 0; i < 11; i++) {
        drawBox(0, i*8, names[i], prop[i]);
        drawBox(10*5, i*8, names[29+i], prop[29+i]);
    }
    for(int i = 0; i < 11*8+1;i++) {
        theDisplay[0][i] = '-';
        theDisplay[10*5][i] = '_';
    }
    for(int i = 1; i < 10; i++) {
        drawBox(i*5, 0, names[11 + (i-1)*2], prop[11 + (i-1)*2]);
        drawBox(i*5, 10*8, names[11 + (i-1)*2 + 1], prop[11+(i-1)*2 + 1]);
    }
}
void TextDisplay::drawBox(int row, int column, string name, bool property) {
    int i = name.length();
    char *f = strdup(name.c_str());
    while(i--) {
        if(f[i] == ' ') {
            f[i] = 0;  
            break;
        }    
    }
    int p = 0;
    if(property) p = 1;
       
    strcpy(&(theDisplay[row+1+p][column+1]), f);
    theDisplay[row+1+p][column+strlen(f)+1] = ' ';
    free(f);
   if(i > 0) {
       char *d = strdup(name.substr(i+1, -1).c_str());
       strcpy(&(theDisplay[row+2+p][column+1]),d); 
       theDisplay[row+2+p][column+strlen(d)+1] = ' ';
       free(d);
   } 
    for(int i = 0; i < 9; i++) {
        theDisplay[row][column+i] = '_';
        if(property) theDisplay[row+1][column+i] = '_';
        theDisplay[row+5][column+i] = '_';
    }
    for(int i = 0; i < 6; i++) {
        theDisplay[row+i][column] = '|';
        theDisplay[row+i][column+8] = '|';
    }

}
void TextDisplay::notify(int r, int c, char ch){
 /* int prev = *(theDisplay[r*gridSize+c]) - '0';
  colourCount[prev]--;
  *(theDisplay[r*gridSize+c]) = ch;
  colourCount[ch-'0']++; */
}


ostream &operator<<(std::ostream &out, const TextDisplay &td) {
  for(int i = 0; i < 56; i++) {
    for(int j = 0; j < 90; j++) {
      out << td.theDisplay[i][j];
    }
    cout << endl;
  }
  return out;
}
