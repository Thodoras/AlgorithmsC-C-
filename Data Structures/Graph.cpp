#include <iostream>

using namespace std;

class Graph {

	private:
		int _V;
		int _E;
		bool _undirected;
		struct Node{
			int value;
			Node *next;
		};
		Node **adj;

	public:
		Graph(int V, bool undirected = true);
		~Graph();
		//Graph& operator=(Graph& other);

		void addEdge(int vertex1, int vertex2);
		int V();
		int E();
		void printGraph();
		Graph* reverse();

	private:
		void _addEdge(int vertex1, int vertex2);
};

Graph::Graph(int V, bool undirected) {
	_V = V;
	_E = 0;
	_undirected = undirected;
	adj = new Node*[_V];
	for (int i = 0; i < _V; i++) {
		adj[i] = NULL;
	}
}

Graph::~Graph() {
	for (int i = 0; i < _V; i++) {
		Node *temp, *toDestroy;
		temp = adj[i];
		while(temp != NULL) {
			toDestroy = temp;
			temp = temp->next;
			delete toDestroy;
		}
	}
	delete adj;
}

void Graph::addEdge(int vertex1, int vertex2) {
	_E++;
	Node *edge = new Node();
	edge->value = vertex2;
	edge->next = NULL;
	if (adj[vertex1] == NULL) {
		adj[vertex1] = edge;
	}
	else {
		Node *tempVert = adj[vertex1];
		while (tempVert->next != NULL) {
			tempVert = tempVert->next;
		}
		tempVert->next = edge;
	}
	if (_undirected) {
		this->_addEdge(vertex2, vertex1);	
	}
}

int Graph::V() {
	return _V;
}

int Graph::E() {
	return _E;
}

Graph* Graph::reverse() {
	if (_undirected) {
		return this;
	}
	Graph *newGraph = new Graph(_V, false);
	Node *temp;
	for (int vertex = 0; vertex < _V; vertex++) {
		temp = adj[vertex];
		while (temp != 0) {
			newGraph->addEdge(temp->value, vertex);
			temp = temp->next;
		}
	}
	return newGraph;
}

void Graph::printGraph() {
	for (int i = 0; i < _V; i++) {
		Node *temp = adj[i];
		cout << i << "->";
		while (temp != NULL) {
			cout << temp->value << "->";
			temp = temp->next;
		}
		cout << endl;
	}
}

void Graph::_addEdge(int vertex1, int vertex2) {
	Node *edge = new Node();
	edge->value = vertex2;
	edge->next = NULL;
	if (adj[vertex1] == NULL) {
		adj[vertex1] = edge;
	}
	else {
		Node *tempVert = adj[vertex1];
		while (tempVert->next != NULL) {
			tempVert = tempVert->next;
		}
		tempVert->next = edge;
	}
}

int main() {
	Graph *g = new Graph(4, false);
	g->addEdge(0,1);
	g->addEdge(0,2);
	g->addEdge(1,3);
	g->addEdge(2,3);
	g->printGraph();
	Graph *h = g->reverse();
	delete h;
	cout << (g->E()) << endl;
}