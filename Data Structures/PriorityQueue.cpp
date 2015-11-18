// A priority queue implementation without using the STL library (just for fun). To be continued... 

#include <iostream>

using namespace std;

template <class T>
class PriorityQueue {

	int size, arraylength;
	T *array;

	public:
		PriorityQueue();
	//	~PriorityQueue();

		bool isEmpty();
		void insert(T key);
		T removeMin();
		void print();

	private:
		void swim();
		void sink(int pos);
		int minIndex(int i, int j);
		void exch(int i, int j);
		T* resize(int& oldLength, int newLength);
};

template <class T>
PriorityQueue<T>::PriorityQueue() {
	array = new T[1];
	arraylength = 1;
	size = 0;
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
		if (array[temp - 1] < array[temp/2 - 1]) {
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
		if (array[min] < array[pos - 1]) {
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
	if (array[j] < array[i]) {return j;}
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

int main() {
	PriorityQueue<int> *pq = new PriorityQueue<int>();
	pq->insert(3);
	pq->insert(2);
	pq->insert(7);
	pq->insert(0);
	pq->insert(1);
	pq->removeMin();
	pq->removeMin();
	pq->print();
}
