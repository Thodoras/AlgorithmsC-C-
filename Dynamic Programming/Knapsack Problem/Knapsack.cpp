/*
 * Knapsack.cpp
 *
 *  Created on: Dec 4, 2015
 *      Author: thodoras
 */

#include "Knapsack.h"

using namespace std;

int Knapsack::knapsack(vector<int> values, vector<int> weights, int TotalWeight) {

	vector<vector<int> > temp (values.size()+1, vector<int>(TotalWeight + 1)); // 2-dimensional vector

	// initialize temp vector
	for (int i = 0; i <= TotalWeight; i++) {
		temp[0][i] = 0;
	}

	for (int i = 1; i < values.size()+1; i++) {
		for (int j = 0; j <= TotalWeight; j++) {
			if (j - weights[i-1] >= 0 && temp[i-1][j] < temp[i-1][j - weights[i-1]] + values[i-1]) {
				temp[i][j] = temp[i-1][j - weights[i-1]] + values[i-1];
			}
			else {
				temp[i][j] = temp[i-1][j];
			}
		}
	}
	return temp[values.size()][TotalWeight];
}
