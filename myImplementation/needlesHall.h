#ifndef __NEEDLESHALL_H__
#define __NEEDLESHALL_H__
class Player;
class NHCard;

class NeedlesHall: public NonProperty{
	std::vector<Card *> deck;
	void action();
	NeedlesHall(Board *theBoard, Square *prevSquare, Square *nextSquare);
	~NeedlesHall();
};

#endif