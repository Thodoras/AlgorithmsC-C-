// An implementation of a basic Graph API for directed and undirected graphs.

#include <iostream>
#include <vector>

using namespace std;

class Graph {

	private:
		int _V;
		int _E;
		bool _undirected;
		vector<int> *_adj;

	public:
		Graph(int V, bool undirected = true); 	// Constructor, undirected by default
		~Graph();								// Destructor

		void addEdge(int vertex1, int vertex2); // add an edge from vertex1 to vertex2.
		vector<int> adj(int vertex);            // return all 1st degree neighbors of a given vertex.
		int V();								// return number of vertices.
		int E();								// return number of edges.
		int degreeV(int vertex);				// returns the degree (i.e. number of adjacent vertices) of a given vertex
		Graph* reverse();						// create a clone graph with opposite direction edges
		void printGraph();						// print graph.
};


Graph::Graph(int V, bool undirected) {
	_V = V;
	_E = 0;
	_undirected = undirected;
	_adj = new vector<int>[_V];
}


Graph::~Graph() {
	delete _adj;
}

void Graph::addEdge(int vertex1, int vertex2) {
	_E++;
	_adj[vertex1].push_back(vertex2);
	if (_undirected) {
		_adj[vertex2].push_back(vertex1);
	}
}

vector<int> Graph::adj(int vertex) {
	return _adj[vertex];
}

int Graph::V() {
	return _V;
}

int Graph::E() {
	return _E;
}

int Graph::degreeV(int vertex) {
	return adj(vertex).size();
}

Graph* Graph::reverse() {
	if (_undirected) {
		return this;
	}
	Graph *newGraph = new Graph(_V, false);
	for (int i = 0; i < V(); i++) {
		for (int j = 0; j < degreeV(i); j++) {
			newGraph->addEdge(adj(i)[j], i);
		}
	}
	return newGraph;
}

void Graph::printGraph() {
	for (int i = 0; i < V(); i++) {
		cout << i << " -- ";
		for (int j = 0; j < degreeV(i); j++) {
			cout << adj(i)[j] << "-";
		}
		cout << endl;
	}
}

