/*
 * WeightedIndependentSets.cpp
 *
 *  Created on: Dec 1, 2015
 *      Author: thodoras
 */

#include "WeightedIndependentSets.h"

using namespace std;

WeightedIndependentSets::WeightedIndependentSets(vector<int>& weights) {
	this->weights = weights;
	dynArray.push_back(0);
	dynArray.push_back(weights[0]);
	opt = false;
}

WeightedIndependentSets::~WeightedIndependentSets() {
}

int WeightedIndependentSets::optValue() {
	opt = true;
	for (unsigned int i = 1; i < weights.size(); i++) {
		if (dynArray[(i+1)-2] + weights[i] < dynArray[(i+1)-1] ) {
			dynArray.push_back(dynArray[(i+1)-1]);
		}
		else {
			dynArray.push_back(dynArray[(i+1)-2] + weights[i]);
		}
	}
	return dynArray[weights.size()];
}

vector<int> WeightedIndependentSets::optVertices() {
	if (!opt) {
		optValue();
	}
	vector<int> optVert;
	int i = dynArray.size() - 1;
	while (i > 0) {
		if (dynArray[i-1] >= dynArray[i-2] + weights[i-1]) {
			i--;
		}
		else {
			optVert.push_back(i-1);
			i-=2;
		}
	}
	return optVert;
}

