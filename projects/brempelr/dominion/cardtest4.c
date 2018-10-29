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

	int k[10] = {adventurer, gardens, embargo, village, minion, council_room, cutpurse, sea_hag, tribute, smithy};

	initializeGame(2, k, seed, &G);

	temp1 =  numHandCards(&G);
	temp2 = cardEffect(adventurer, 0, 0, 0, &G, NULL);
	
	if(temp2 == 0 && (numHandCards(&G) == (temp1 + 1)))
	{
		printf("Adventurer test completed.\n");
	}
	else
	{
		printf("Adventurer test failed.\n");
	}
	return 0;
}
