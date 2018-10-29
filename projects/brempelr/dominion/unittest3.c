#include "dominion.h"
#include "rngs.h"
#include <stdlib.h>
#include <stdio.h>
#include "assert.h"


int main(){
	
	struct gameState G;

	int cur_turn1 = 0;
	int cur_turn2 = 0;

	for(int i = 0; i < 10; i++)
	{
		G.whoseTurn = cur_turn1;
		cur_turn2 = whoseTurn(&G);

		assert(cur_turn2 == cur_turn1);

		cur_turn1++;
	}

	printf("whoseTurn Test Completed.\n");
	return 0;
}
