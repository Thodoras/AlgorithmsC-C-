// A deterministic, stable sorting algorithm for generic arrays with order of growth O(NlogN).
// Needs a compare function.

#include <iostream>

using namespace std;

template <class T>
class Mergesort {

	public:
		static void sort(T array[], int length, int (*compare)(T x, T y));					// The method to be used.

	private:
		static void sort(T array[], T aux[], int low, int high, int (*compare)(T x, T y));
		static void merge(T array[], T aux[], int low, int mid, int high, int (*compare)(T x, T y));
		static void swap(T array[], int i, int j);
};

template <class T>
void Mergesort<T>::sort(T array[], int length, int (*compare)(T x, T y)) {
	T *aux = new T[length];
	sort(array, aux, 0, length-1, compare);
	delete aux;
}

template <class T>
void Mergesort<T>::sort(T array[], T aux[], int low, int high, int (*compare)(T x, T y)) {
	if (low >= high) {
		return;
	}
	int mid = low + (high - low) / 2;
	sort(array, aux, low, mid, compare);
	sort(array, aux, mid + 1, high, compare);
	merge(array, aux, low, mid, high, compare);
}

template <class T>
void Mergesort<T>::merge(T array[], T aux[], int low, int mid, int high, int (*compare)(T x, T y)) {
	for (int i = low; i <= high; i++) {
		aux[i] = array[i];
	}
	int i = low;
	int j = mid + 1;
	for (int k = low; k <= high; k++) {
		if (j > high) {
			array[k] = aux[i++];
		}
		else if (i > mid) {
			array[k] = aux[j++];
		}
		else if ((*compare)(aux[i], aux[j]) > 0) {
			array[k] = aux[j++];
		}
		else {
			array[k] = aux[i++];
		}
	}
}

template <class T>
void Mergesort<T>::swap(T array[], int i, int j) {
	T temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
