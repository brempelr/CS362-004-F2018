#include "dominion.h"
#include "rngs.h"
#include <stdlib.h>
#include <stdio.h>
#include "assert.h"


int main(){
	
	struct gameState G;

	int m = 0;
	int k[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int seed = 50;

	initializeGame(2, k, seed, &G);

	G.coins = 0;

	m = buyCard(1, &G);

	assert(m == -1);

	G.coins = 9;

	G.numBuys = 0;

	m = buyCard(1, &G);

	assert(m == -1);

	G.numBuys = 2;

	m = buyCard(3, &G);

	assert(m == 0);

	m = buyCard(3, &G);

	assert(m == -1);

	G.coins = 10;

	m = buyCard(1, &G);

	assert(m == 0);

	m = buyCard(1, &G);

	assert(m == -1);	

	printf("buyCard Test Completed.\n");
	return 0;
}
