/*
 * Knapsack.h
 *
 *  Created on: Dec 4, 2015
 *      Author: thodoras
 */

 // A classic algorith for computing the maximum sum of values of n weighted values
 // within a total weight(W) restriction. Order of growth is O(nW).

#ifndef KNAPSACK_H_
#define KNAPSACK_H_

#include <vector>

class Knapsack {
public:
	static int knapsack(std::vector<int> values, std::vector<int> weights, int TotalWeight);
};

#endif /* KNAPSACK_H_ */
