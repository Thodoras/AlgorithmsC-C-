/*
 * Graph.cpp
 *
 *  Created on: Dec 6, 2015
 *      Author: thodoras
 */

#include "Graph.h"

using namespace std;

Graph::Graph(int V, bool undirected) {
	_V = V;
	_E = 0;
	_undirected = undirected;
	_adj = vector<int> (_V);
}

Graph::~Graph() {
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
