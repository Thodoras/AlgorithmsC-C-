// An exponation mod n algorithm with order of growth of O(logexp * logn * logn).
// INPUT: int base, int exponent, int modulo
// OUTPUT: int (base^exponent) mod (modulo)

#include <stdio.h>
#include <math.h>

int pow2Mod(int base, int expon, int mod) {
	int result = base, temp;
	if (expon == 0) {
		return 1;
	}
	for (temp = 2; temp <= expon; temp *= 2) {
		base *= base;
		base %= mod;
	}
	return base;
}

int powMod(int base, int expon, int mod) {
	int curexp, curval, result = 1;
	while (1) {
		curexp = (int) pow(2, floor(log(expon)/log(2)));
		curval = pow2Mod(base, curexp, mod);
		result *= curval;
		result %= mod;
		expon -= curexp;
		if (expon == 0) { break; }
	}
	return result;
}
