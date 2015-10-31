// An algorithm that decides whether a number is prime or not. Order of growth 100 * O(modularExp).
// INPUT int number.
// OUTPUT 1 if prime, 0 else
// DEPENDENCIES modularExp.h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "modularExp.h"

int primality(int num) {
	int randbase, val, i;
	srand(time(NULL));
	if (num == 1) {
		return 0;
	}
	for (i=1; i<=100 && i<=num; i++) {
		randbase = (rand() % (num - 1)) + 1;
		printf("%d\n", randbase);
		val = powMod(randbase, num - 1, num);
		if (val != 1) {
			return 0;
		}
	}
	return 1;
}