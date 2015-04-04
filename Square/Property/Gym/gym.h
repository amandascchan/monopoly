#ifndef __GYM_H__
#define __GYM_H__
#include <string>
#include "../property.h"

class TextDisplay;
class Player;
class Board;

class Gym: public Property {
	friend class Board;
	std::string desc;
public:
	int getRent();
	int getMult();
	Gym(Board *, TextDisplay *);
};
#endif