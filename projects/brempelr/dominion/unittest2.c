#include "dominion.h"
#include "rngs.h"
#include <stdlib.h>
#include <stdio.h>
#include "assert.h"


int main(){
	
	assert(getCost(smithy) == 4);

	assert(getCost(gold) == 6);

	assert(getCost(mine) == 5);

	assert(getCost(adventurer) == 6);
	
	assert(getCost(steward) == 3);

	assert(getCost(baron) == 4);
	
	printf("getCost Test Completed.\n");
	return 0;
}
