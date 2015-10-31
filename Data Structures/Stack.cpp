// An implementation of a stack, using linked lists. 

#include <iostream>

using namespace std;

template <class T>
class Stack {
	public:
		Stack();
		~Stack();
		Stack& operator=(Stack& other);

		void push(T value);
		T pop();
		int size();
		void printList();
	private:
		int _size;
		struct Node {
			T value;
			Node *next;
		};
		Node *_head;
};

template <class T>
Stack<T>::Stack() {
	_size = 0;
	_head = NULL;
}

template <class T>
Stack<T>::~Stack() {
	Node *temp;
	while(_head != NULL) {
		temp = _head->next;
		delete _head;
		_head = temp;
	}
} 

template <class T>
Stack<T>& Stack<T>::operator=(Stack& other) {
	if (this == &other) {
		return *this;
	}
	delete _head;
	_head = NULL;
	Node *temp = other._head;
	while(temp != NULL) {
		push(temp->value);
		temp = temp->next;
	}
}

template <class T>
int Stack<T>::size() {
	return _size;
}

template <class T>
T Stack<T>::pop() {
	_size--;
	T value = _head->value;
	Node *new_head = _head->next;
	delete _head;
	_head = new_head;
	return value;
}

template <class T>
void Stack<T>::push(T value) {
	Node *newNode = new Node();
	newNode->value = value;
	newNode->next = _head;
	_head = newNode;
	_size++;
}

template <class T>
void Stack<T>::printList() {
	Node *temp = _head;
	while (temp != NULL) {
		cout << temp->value << endl;
		temp = temp->next;
	}
}

int main() {
	Stack<int> *stack = new Stack<int>();
	stack->push(2);
	stack->push(4);
	stack->push(7);
	Stack<int> *otherst = new Stack<int>();
	otherst = stack;
	otherst->printList();
}