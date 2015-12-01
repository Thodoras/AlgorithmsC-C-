/*
 * WeightedIndependentSets.h
 *
 *  Created on: Dec 1, 2015
 *      Author: thodoras
 */

// A basic dynamic programming algorithm for computing in a
// list of weights (integers), the heaviest composition
// of them that are non-adjacent in O(n) time.

#ifndef WEIGHTEDINDEPENDENTSETS_H_
#define WEIGHTEDINDEPENDENTSETS_H_

#include <iostream>
#include <vector>

class WeightedIndependentSets {

private:
	std::vector<int> weights;
	std::vector<int> dynArray;
	bool opt;

public:
	WeightedIndependentSets(std::vector<int>& weights);
	virtual ~WeightedIndependentSets();

	int optValue();
	std::vector<int> optVertices();
};

#endif /* WEIGHTEDINDEPENDENTSETS_H_ */

