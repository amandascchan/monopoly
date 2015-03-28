#include "player.h"
#include "card.h"
#include "slccard.h"
#include "nhcard.h"
#include <string.h>
#include <vector.h>
#include "deckBuilder.h"
#include <sstream.h>

int main(){
	deckBuilder myDB;
	String myConfig = "24
SLCCard 24
-4 1
-3 3
-2 4
-1 4
1 3
2 4
3 4
4 1"
	vector<Card *> mydeck = myDB.buildDeck(myConfig);



}
