#ifndef __DECKBUILDER_H__
#define __DECKBUILDER_H__
#include "player.h"
#include "slccard.h"
#include "nhcard.h"
#include <string.h>
#include <vector.h>

class deckBuilder{
	vector<Card *> buildDeck(String config);
};

#endif
