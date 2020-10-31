// Graph.cpp
// Implements an adjacency-based graph using a 2d vector of bool
// which can be loaded from a file
#include "Graph.h"


void Graph::loadAdjacencies(std::string path) {
	//reads an adjacency matrix from a specified file
	try {
		std::ifstream readIn(path);
		std::string line;
		bool adjacent;
		int i = 0;
		while (getline(readIn, line)) {
			std::vector<bool> newRow;
			adjacencies.push_back(newRow);
			std::istringstream row(line);
			while (row >> adjacent) {
				adjacencies.at(i).push_back(adjacent);
			}
			i++;
		}
	}
	catch (std::exception e) {
		std::cerr << e.what() << std::endl;
	}
}

void Graph::loadNodes(std::string path) {
	//creates nodes with names read from file
	try {
		std::ifstream readIn(path);
		std::string line;
		int i = 0;
		while (getline(readIn, line)) {
			//create a node with the name from file, NULL color, and the correct adjacencies from the matrix
			Node newNode;
			newNode.setName(line);
			newNode.setAdjacencies(adjacencies.at(i++));//read adjacencies[i] and then increment i
			nodes.push_back(newNode);
		}
	}
	catch (std::exception e) {
		std::cerr << e.what() << std::endl;
	}
}

std::queue<int> Graph::BreadthFirstSearch(int start) {
	//From a starting node, generates and returns the BFS sequence
	std::queue<int> sequence;
	std::vector<bool> visited;
	visited.resize(nodes.size());
	for(bool b : visited) {
		b = false;
	}
	sequence.emplace(start);
	std::queue<int> toSearch = sequence;
	visited.at(start) = true;
	while (sequence.size() < visited.size()) {
		Node current = nodes.at(toSearch.front());
		toSearch.pop();
		for (int i : current.getAdjacencies()) {
			if (visited[i]) {
				continue;
			}
			else {
				visited[i] - true;
				sequence.emplace(i);
				toSearch.emplace(i);
			}
		}
	}
	return sequence;
}