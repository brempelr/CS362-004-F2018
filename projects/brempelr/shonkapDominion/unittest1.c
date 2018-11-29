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

	m = isGameOver(&G);

	assert(m != 1);	

	G.supplyCount[2] = 0;
	G.supplyCount[3] = 0;
	G.supplyCount[4] = 0;

	m = isGameOver(&G);

	assert(m == 1);

	G.supplyCount[2] = 1;

	G.supplyCount[province] = 0;

	m = isGameOver(&G);

	assert(m == 1);

	printf("isGameOver Test Completed.\n");
	return 0;
}
