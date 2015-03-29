#ifndef __DECKBUILDER_H__
#define __DECKBUILDER_H__
#include "slccard.h"
#include "nhcard.h"
#include <string>
#include <vector>

class deckBuilder{
public:
	std::vector<Card *> buildDeck(std::string config);
};

#endif
