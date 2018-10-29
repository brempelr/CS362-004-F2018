#include "dominion.h"
#include "rngs.h"
#include "assert.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

	struct gameState G;
	int temp1;
	int temp2;
	int temp3;
	int seed = 50;

	int k[10] = {adventurer, gardens, embargo, village, minion, council_room, cutpurse, sea_hag, tribute, smithy};

	initializeGame(2, k, seed, &G);

	temp1 =  numHandCards(&G);
	temp3 = G.numBuys;
	temp2 = cardEffect(council_room, 0, 0, 0, &G, NULL);
	
	if(temp2 == 0 && (numHandCards(&G) == (temp1 + 3)) && (temp3 + 1) == G.numBuys)
	{
		printf("Council Room test completed.\n");
	}
	else
	{
		printf("Council Room test failed.\n");
	}
	return 0;
}
