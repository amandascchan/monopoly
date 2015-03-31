#include "textdisplay.h"
#include "square.h"
#include <string>
#include <iostream>

using namespace std;

Academic::Academic(Board *theBoard, TextDisplay *td): theBoard(theBoard), td(td){
    for(int i = 0; i < 6; i ++) {
        tiution[i] = 0;
    }
}

Academic::action(){
  if (!isMortgaged){
    int fee = tuition[numImp];
    if ((owner->ownsBlock(block))&&(numImp == 0)){fee *= 2;}
    theBoard->getNextPlayer(0)->transaction(-fee);
    owner->transaction(fee);
  }
}

Academic::improve(std::string buyOrSell){
  if (buyOrSell == "buy"){
    if (owner->ownsBlock(block)){
      if (owner->canAfford(impCost)){
        owner->transaction(-impCost);
        ++numImp;
      }
      else {
        std::cout << "YOU ARE TO POOR MUHAHA" << endl;
      }
    }
    else {
      std::cout << "You can not improve this property as you do not own the entire block." << std::endl;
    }
  }
  else if (buyOrSell == "sell"){
    if (numImp > 0){
      owner->transaction(impCost/2);
      --numImp;
    }
    else {
      std::cout << "You do not have any improvements to sell." << std::endl;
    }
    
  }
}

Academic::mortgage(){
  if (numImp == 0){
    isMortgaged = true;
    theBoard->getNextPlayer(0)->transaction(price/2);
  }
  else {
    std::cout << "Can not mortgage property that has improvements." << endl;
  }
}