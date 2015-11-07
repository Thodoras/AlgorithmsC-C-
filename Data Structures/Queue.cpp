// An implementation of a queue, using linked lists. 

#include <iostream>

using namespace std;

template <class T>
class Queue {

	public:
		Queue();						// Constructor.
		~Queue();						// Destructor.
		Queue& operator=(Queue& other);	// Overides operator "=" in order to be able to make deep copies.

		void enqueue(T value);			// Enque an item T in the end of the list list. 
		T dequeue();					// Dequeue an item from the top of the list.
		int size();						// Return the size of the list.
		void printList();				// Prints the elements of the stack on the console.

	private:
		int _size;
		struct Node {
			T value;
			Node *next;
		};
		Node *head;
		Node *tail;
};

template <class T>
Queue<T>::Queue() {
	_size = 0;
	head = NULL;
	tail = NULL;
}

template <class T>
Queue<T>::~Queue() {
	Node *temp;
	while (head != NULL) {
		temp = head->next;
		delete head;
		head = temp;
	}
}

template <class T>
Queue<T>& Queue<T>::operator=(Queue<T>& other) {
	if (this == &other) {
		return *this;
	}
	delete this;
	Queue<T> *q = new Queue<T>();
	Node *temp = other.head;
	while (temp != NULL) {
		q->enqueue(temp->value);
		temp = temp->next;
	}
	return *q;
}

template <class T>
void Queue<T>::enqueue(T value) {
	Node *newNode = new Node();
	newNode->value = value;
	newNode->next = NULL;
	_size++;
	if (tail == NULL) {
		tail = newNode;
		head = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
}

template <class T>
T Queue<T>::dequeue() {
	T val = head->value;
	_size--;
	if (head->next == NULL) {
		delete head;
		delete tail;
	}
	else {
		Node *temp = head;
		head = head->next;
		delete temp;
	}
	return val;
}

template <class T>
int Queue<T>::size() {
	return _size;
}

template <class T>
void Queue<T>::printList(){
	Node *temp = head;
	string str = "";
	while (temp != NULL) {
		cout << temp->value << " -> ";
		temp = temp->next;
	}
	cout << endl;
}

int main() {
	Queue<int> *queue = new Queue<int>();
	queue->enqueue(2);
	queue->enqueue(3);
	queue->enqueue(1);
	queue->printList();
	queue->dequeue();
	queue->printList();
	Queue<int> *q = new Queue<int>();
	q->printList();
	*q = *queue;
	queue->enqueue(7);
	q->printList();
	queue->printList();
	cout << queue->size() << endl;
}