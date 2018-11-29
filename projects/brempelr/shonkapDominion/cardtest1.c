#include "dominion.h"
#include "rngs.h"
#include "assert.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

	struct gameState G;
	int temp1;
	int temp2;
	int seed = 50;

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	initializeGame(2, k, seed, &G);

	temp1 = G.numActions;
	
	temp2 = cardEffect(village, 0, 0, 0, &G, NULL);

	if(temp2 == 0 && (G.numActions == (temp1 + 2)))
	{
		printf("Village test completed.\n");
	}
	else
	{
		printf("Village test failed.\n");
	}
	return 0;
}
