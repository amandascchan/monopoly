#ifndef __NEEDLESHALL_H__
#define __NEEDLESHALL_H__
class Player;
class NHCard;

class NeedlesHall: public NonProperty{
	std::vector<Card *> deck;
public:
	void action();
	NeedlesHall(Board *, TextDisplay *);
	~NeedlesHall();
};

#endif