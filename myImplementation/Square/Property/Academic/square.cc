#include "textdisplay.h"
#include "square.h"
#include <string>

using namespace std;

Square::Square(Board *theBoard, TestDisplay): desc(""), rent(0),cost(0), imCost(0), row(0), column(0), td(NULL), owner(NULL) {
    for(int i = 0; i < 6; i ++) {
        tiution[i] = 0;
    }
}