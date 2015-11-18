// A priority queue implementation without using the STL library (just for fun). Insertions and deletions
// done in O(logN).

#include <iostream>

using namespace std;

template <class T>
class PriorityQueue {

	int size, arraylength;
	int (*compare)(T x, T y);
	T *array;

	public:
		PriorityQueue(int (*compare)(T x, T y));      	// Constructor that take a comparator as an argument.
		~PriorityQueue();								// Destructor.

		bool isEmpty();									// Returns true if PQ is empty.
		void insert(T key);								// Imserts a value.
		T peekMin();									// Returns the minimum key without deleting it.
		T removeMin();									// Returns and deletes minimum key.
		void print();									// Prints all the elements of the heap in height order.

	private:
		void swim();
		void sink(int pos);
		int minIndex(int i, int j);
		void exch(int i, int j);
		T* resize(int& oldLength, int newLength);
};

template <class T>
PriorityQueue<T>::PriorityQueue(int (*compare)(T x, T y)) {
	array = new T[1];
	arraylength = 1;
	size = 0;
	this->compare = compare;
}

template <class T>
PriorityQueue<T>::~PriorityQueue() {
	delete[] array;
}

template <class T>
bool PriorityQueue<T>::isEmpty() {
	return size == 0;
}

template <class T> 
void PriorityQueue<T>::insert(T key) {
	array[size++] = key;
	swim();
	if (size == arraylength) {
		array = resize(arraylength, 2*arraylength);
	}
}

template <class T>
T PriorityQueue<T>::peekMin() {
	return array[0];
}

template <class T>
T PriorityQueue<T>::removeMin() {
	T minKey = array[0];
	exch(0, size - 1);
	size--;
	sink(0);
	if (size <= arraylength/4) {
		resize(arraylength, arraylength/2);
	}
	return minKey;
}

template <class T>
void PriorityQueue<T>::print() {
	for (int i = 0; i < size; i++) {
		cout << array[i] << endl;
	}
}

template <class T>
void PriorityQueue<T>::swim() {
	int temp = size;
	while (temp > 1) {
		if (compare(array[temp - 1], array[temp/2 - 1]) < 0) {
			exch(temp - 1, temp/2 - 1);
			temp /= 2;
		}
		else {
			break;
		}
	}
}

template <class T>
void PriorityQueue<T>::sink(int pos) {
	pos++;
	while (2*pos <= size) {
		int min = minIndex(2*pos-1, 2*pos);
		if (compare(array[min], array[pos - 1]) < 0) {
			exch(min, pos-1);
			pos = min + 1;
		}
		else {
			break;
		}
	}
}

template <class T>
int PriorityQueue<T>::minIndex(int i, int j) {
	if (i == size) {return j;}
	if (j == size) {return i;}
	if (compare(array[j], array[i]) < 0) {return j;}
	return i;
}

template <class T>
void PriorityQueue<T>::exch(int i, int j) {
	T temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

template <class T>
T* PriorityQueue<T>::resize(int& oldLength, int newLength) {
	T *newArray = new T[newLength];
	for (int i = 0; i < oldLength; i++) {
		newArray[i] = array[i];
	}
	oldLength = newLength;
	delete[] array;
	return newArray;
}

int compare(int x, int y) {
	return x - y;
}