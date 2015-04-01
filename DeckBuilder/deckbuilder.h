#ifndef __DECKBUILDER_H__
#define __DECKBUILDER_H__
#include <string>
#include <vector>

class Card;

class deckBuilder{
public:
	std::vector<Card *> buildDeck(std::string config);
};

#endif
