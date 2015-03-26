#include "textdisplay.h"
#include "square.h"


using namespace std;

Square::Square(): state(0), prevState(0), numNeighbours(0), r(0), c(0), td(NULL) {
  numNeighbours = 0;
}
char Square::getState() {
  return state - '0';}

void Square::setState(const int& change) {
  if(state) {
    prevState = state;
  }
  state = change;
  char notC = change + '0';
  td->notify(r, c, notC);
}
void Square::setCoords(const int r, const int c) {
  this->r = r;
  this->c = c;
}
void Square::setDisplay(TextDisplay * t) {
  td = t;
}
/*void Square::addNeighbour(Square *neighbour) {
  neighbours[numNeighbours] = neighbour;
  numNeighbours++;
}
void Square::notify( const int & change) {
  int copyState = state;
  notify(change,copyState);
}
void Square::notify(const int & current, const int & previous){
  if(state == previous && current != state) {
    state = current;
    td->notify(r,c,state + '0');
    for(int i = 0; i < numNeighbours; i++) {
      neighbours[i]->notify(current, previous);
    }
  }
  else return;
}*/
