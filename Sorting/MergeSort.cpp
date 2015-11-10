// Working only for integer arrays. To be continued...

#include <iostream>

using namespace std;

class Mergesort {

	public:
		static void sort(int array[], int length);

	private:
		static void sort(int array[], int aux[], int low, int high);
		static void merge(int array[], int aux[], int low, int mid, int high);
		static void swap(int array[], int i, int j);
};

void Mergesort::sort(int array[], int length) {
	int *aux = new int[length];
	sort(array, aux, 0, length-1);
	delete aux;
}

void Mergesort::sort(int array[], int aux[], int low, int high) {
	if (low >= high) {
		return;
	}
	int mid = low + (high - low) / 2;
	sort(array, aux, low, mid);
	sort(array, aux, mid + 1, high);
	merge(array, aux, low, mid, high);
}

void Mergesort::merge(int array[], int aux[], int low, int mid, int high) {
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
		else if (aux[i] > aux[j]) {
			array[k] = aux[j++];
		}
		else {
			array[k] = aux[i++];
		}
	}
}

void Mergesort::swap(int array[], int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

int main() {
	int array[] = {3, 7, 4, 1, 8};
	Mergesort::sort(array, 5);
	for (int i= 0; i < 5; i++) {
		cout << array[i] << endl;
	}
}