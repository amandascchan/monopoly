#include "../../../Board/board.h"
#include "../../../Player/player.h"
#include "../../../TextDisplay/textdisplay.h"
#include "academic.h"
#include <string>
#include <iostream>


int Academic::getRent(){
  return getIm(numImp);
}
int Academic::getImCost(){
  return impCost;
}
int Academic::getIm(int imps){
  int fee = tuition[imps];
  if (owner->ownsBlock(block)&&(numImp == 0)){fee *= 2;}
  return fee;
}

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
      //std::cout << "about to charge player" << std::endl;
      theBoard->getNextPlayer(0)->transaction(-getRent(), owner);
    }
  }
}

void Academic::improve(std::string buyOrSell){
  if (buyOrSell == "buy"){
    if (numImp >= 5){
      std::cout << "You can not improve "<< name <<" further." << endl;
    }
    else if (owner->ownsBlock(block)){
      if (owner->canAfford(impCost)){
        owner->transaction(-impCost, NULL);
        ++numImp;
        td->addImprov(row, column, numImp);
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
      theBoard->transfer(owner, impCost/2);
      --numImp;
      td->removeImprov(row, column, numImp);
    }
    else {
      std::cout << "You do not have any improvements to sell." << std::endl;
    }
  }
}

int Academic::getNumImp(){
  return numImp;
}

void Academic::mortgage(){
    std:: cout << "wh" << endl;
  if (numImp == 0){
    isMortgaged = true;
    theBoard->transfer(owner,price/2);
  }
  else {
    std::cout << "Can not mortgage property that has improvements." << endl;
  }
}
