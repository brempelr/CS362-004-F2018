#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion_helpers.h"

int main(int argc, char* args[]){
	
	int i, j, m, n, runs;
	int seed, cards;
	int players, current, after;
	int test_fail = 0;
	int test_complete = 0;

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	struct gameState g;
	
	if(argc != 3) {
		printf("Usage: randomtestadventurer Num_Runs Seed\n");
		return -1;
	}
	
	seed = atoi(args[2]);
	runs = atoi(args[1]);
	
	srand(seed);
	
	printf("Beginning Adventure Test\n");

	for (i = 0; i < runs; i++) {
		
		players = rand() % (MAX_PLAYERS - 1) + 2;
		initializeGame(players, k, seed, &g);
		
		printf("Number of players this game: %d\n", players);

		for (j = 0; j < players; j++) {
			
			g.handCount[j] = rand() % (MAX_HAND - 3) + 1;
			g.deckCount[j] = rand() % (MAX_DECK - 3) + 3;
			
			g.hand[j][0] = adventurer;

			current = 0;
			after = 0;
			cards = g.handCount[j];

			for (n = 0; n < g.handCount[j]; n++) {
				if (g.hand[j][n] == gold || g.hand[j][n] == silver || g.hand[j][n] == copper) {
					current++;
				}
			}
			
			m = playCard(0, 0, 0, 0, &g);

			for (n = 0; n < g.handCount[j]; n++) {
				if (g.hand[j][n] == gold || g.hand[j][n] == silver || g.hand[j][n] == copper) {
					after++;
				}
			}
			
			if (cards + 1 != g.handCount[j]) {
				printf("Test run %d, player %d, failed to add 1 card (2 treas - 1 played)\n", i + 1, j + 1);
				test_fail++;
			}
			
			if (current + 2 != after) {
				
				printf("Test run %d, player %d, failed to add 2 treasures\n", i + 1, j + 1);
				test_fail++;
			}
			if (m != 0) {
				printf("Test run %d, player %d, failed to return correct value", i + 1, j + 1);
				printf(" (deck may not contain 2 treasures)\n");
				test_fail++;
			}

			test_complete += 3;
			endTurn(&g);
			
		}
		
	}
	
	printf("All tests completed - %d tests run - %d tests failed\n", test_complete, test_fail);
	return 0;
	
}
