#ifndef __SLC_H__
#define __SLC_H__

class Card;

class SLC: public NonProperty{
	std::vector<Card *> deck;
public:
	void action();
	SLC(Board *, TextDisplay *);
	~SLC();
};

#endif