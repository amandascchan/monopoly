#ifndef __DECKBUILDER_H__
#define __DECKBUILDER_H__
#include <string>
#include <vector>

class Card;
class Board;

class deckBuilder{
	Board *theBoard;
public:
	deckBuilder(Board *);
	std::vector<Card *> buildDeck(std::string config, std::string name);
};

#endif
