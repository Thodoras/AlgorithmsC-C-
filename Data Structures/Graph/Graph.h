/*
 * Graph.h
 *
 *  Created on: Dec 6, 2015
 *      Author: thodoras
 */

// An implementation of a basic Graph API for directed
// and undirected unweighted graphs.

#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>

class Graph {

	int _V;
	int _E;
	bool _undirected;
	std::vector<int> _adj;

public:
	Graph(int V, bool undirected = true);	// Constructor, undirected by default
	virtual ~Graph();						// Destructor

	void addEdge(int vertex1, int vertex2); // add an edge from vertex1 to vertex2
	std::vector<int> adj(int vertex);      	// return all 1st degree neighbors of a given vertex.
	int V();								// return number of vertices.
	int E();								// return number of edges.
	int degreeV(int vertex);				// returns the degree (i.e. number of adjacent vertices) of a given vertex
	Graph* reverse();						// create a clone graph with opposite direction edges
};

#endif /* GRAPH_H_ */
