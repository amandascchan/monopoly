#include "../../../Board/board.h"
#include "../../../Player/player.h"
#include "../../../TextDisplay/textdisplay.h"
#include "academic.h"
#include <string>
#include <iostream>


Academic::Academic(Board *theBoard, TextDisplay *td): Property(theBoard, td), numImp(0){
    isMortgaged =false;
    owner =NULL;
    for(int i = 0; i < 6; i ++) {
        tuition[i] = 0;
    }
}

void Academic::action(){
  if (owner == NULL){
    buy();
  }
  else {
    if (!isMortgaged){
    int fee = tuition[numImp];
    if ((owner->ownsBlock(block))&&(numImp == 0)){fee *= 2;}
    theBoard->getNextPlayer(0)->transaction(-fee, owner);
    }
  }
}

void Academic::improve(std::string buyOrSell){
  if (buyOrSell == "buy"){
    if (owner->ownsBlock(block)){
      if (owner->canAfford(impCost)){
        owner->transaction(-impCost, NULL);
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
      owner->transaction(impCost/2, NULL);
      --numImp;
    }
    else {
      std::cout << "You do not have any improvements to sell." << std::endl;
    }
    
  }
}

void Academic::mortgage(){
  if (numImp == 0){
    isMortgaged = true;
    owner->transaction(price/2, NULL);
  }
  else {
    std::cout << "Can not mortgage property that has improvements." << endl;
  }
}