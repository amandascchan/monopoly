#pragma once
#ifndef __TCUP_H__
#define __TCUP_H__
class Player;
class TCUP {
    int numCups;
 public:
    TCUP();
    void giveCup(Player *p);
    void returnCup(Player *p);

};

#endif
