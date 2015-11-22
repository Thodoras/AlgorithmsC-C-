/*
 * MergeSort.h
 *
 *  Created on: Nov 22, 2015
 *      Author: thodoras
 */

// A deterministic, stable sorting algorithm for generic arrays with order of growth O(NlogN).
// Needs a compare function.

#ifndef MERGESORT_H_
#define MERGESORT_H_

template <class T>
class Mergesort {

	public:
		static void sort(T array[], int length, int (*compare)(T x, T y));					// The main method.

	private:
		static void sort(T array[], T aux[], int low, int high, int (*compare)(T x, T y));
		static void merge(T array[], T aux[], int low, int mid, int high, int (*compare)(T x, T y));
		static void swap(T array[], int i, int j);
};

#endif /* MERGESORT_H_ */
