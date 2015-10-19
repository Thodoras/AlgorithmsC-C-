// A program that generates randomly (dublicates allowed) 15,000 numbers between 2 and 30,000
// and prints a message notifying if a number is prime or not. The computation is done in O(log^3(N))
// time.
// INPUT: 
// OUTPUT: 15,000 random and a message about their primality
// DEPENDENCIES: prime.c, modularExp.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "prime.c"

int main() {
	int current, i, number, primes = 0;
	printf("Current time is %d\n", (int) time(NULL));
	srand(time(NULL));
	for (i = 1; i <= 15000; i++) {
		number = (rand() % 29999) + 2;
		if (primality(number)) {
			primes++;
			printf("%d is     prime\n", number);
		}
		else {
			printf("%d is NOT prime\n", number);
		}
	}
	printf("Found %f percent primes", ((double) primes)/ 15000);
}