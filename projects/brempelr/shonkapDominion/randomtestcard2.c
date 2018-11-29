#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion_helpers.h"

int main(int argc, char* args[]){
	
	int i, j, m, runs;
	int seed;
	int players, current;
	int test_fail = 0;
	int test_complete = 0;

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	struct gameState g;
	
	if(argc != 3) {
		printf("Usage: randomtestcard2 Num_Runs Seed\n");
		return -1;
	}
	
	seed = atoi(args[2]);
	runs = atoi(args[1]);
	
	srand(seed);
	
	printf("Beginning Smithy Test\n");

	for (i = 0; i < runs; i++) {
		
		players = rand() % (MAX_PLAYERS - 1) + 2;
		initializeGame(players, k, seed, &g);
		
		printf("Number of players this game: %d\n", players);

		for (j = 0; j < players; j++) {
			
			g.handCount[j] = rand() % (MAX_HAND - 3) + 1;
			g.deckCount[j] = rand() % (MAX_DECK - 3) + 3;
			
			current = numHandCards(&g);
			g.hand[j][0] = smithy;
			
			m = playCard(0, 0, 0, 0, &g);

			if (numHandCards(&g) != current + 2) {
				
				printf("Test run %d, player %d, failed to add 3 cards\n", i + 1, j + 1);
				test_fail++;
			}
			if (m != 0) {
				printf("Test run %d, player %d, failed to return correct value\n", i + 1, j + 1);
				test_fail++;
			}

			test_complete += 2;
			endTurn(&g);
			
		}
		
	}
	
	printf("All tests completed - %d tests run - %d tests failed\n", test_complete, test_fail);
	return 0;
	
}
