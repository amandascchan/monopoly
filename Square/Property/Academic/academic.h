#ifndef __ACADEMIC_H__
#define __ACADEMIC_H__
#include <string>
#include "../property.h"

class TextDisplay;
class Player;
class Board;


class Academic: public Property {
	friend class Board;
	int impCost;
	int numImp;
	int tuition[6];
	std::string desc;
public:
	Academic(Board *, TextDisplay *);
	void improve(std::string);
	void mortgage();
	int getRent();
	int getImCost();
	int getIm(int);
	int getNumImp();
};
#endif
