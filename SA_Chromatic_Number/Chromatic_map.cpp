// Chromatic_map.cpp
// Inherits basic functionality from Graph.cpp
// Adds logic for handling coors and calculating the chromatic number of the graph
#include "Chromatic_map.h"

Chromatic_map::Chromatic_map() {}
Chromatic_map::~Chromatic_map() {}

void Chromatic_map::loadCountries(std::string path) {
	//creates nodes with names read from file
	try {
		std::ifstream readIn(path);
		std::string line;
		int i = 0;
		while (getline(readIn, line)) {
			//create a node with the name from file, NULL color, and the correct adjacencies from the matrix
			Node newNode;
			newNode.setColor(0);
			newNode.setName(line);
			newNode.setAdjacencies(adjacencies.at(i++));//read adjacencies[i] and then increment i
			nodes.push_back(newNode);
		}
	}
	catch (std::exception e) {
		std::cerr << e.what() << std::endl;
	}
}

void Chromatic_map::loadColors(std::string path) {
	//reads the colors from a file and puts them in a map for reference
	std::map<int, std::string> colors;
	try {
		std::ifstream readIn(path);
		std::string line;
		int i = 0;
		while (getline(readIn, line)) {
			Colors.emplace(i, line);
			i++;
		}
	}
	catch (std::exception e) {
		std::cerr << e.what() << std::endl;
	}
}

int Chromatic_map::chromatic_number() {
	//finds the chromatic number of the graph by brute force
	std::vector<int> results;
	for (int i = 0; i < adjacencies.size(); i++) {
		clearColors();
		toCheck.empty();
		results.push_back(calculate_chromatic_number(i));
	}
	int least = Colors.size();
	for (int i : results) {
		if (i < least) {
			least = i;
		}
	}
	return least;
}

int Chromatic_map::calculate_chromatic_number(int startingNode) {
	std::vector<bool> visited{ 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	//set initial node color and get first round of adjacencies
	nodes.at(startingNode).setColor(1);
	for (int a : nodes.at(startingNode).getAdjacencies()) {
		toCheck.push(a);
		visited[a] = 1;
	}
	//run until all are checked; since there are no disconnected nodes, it will hit them all
	while (!toCheck.empty()) {
		int next = toCheck.front();
		toCheck.pop();

		int color = checkAdjacentColors(next, visited);
		nodes[next].setColor(color);
	}
	//return the highest color index used for this iteration
	int greatest = 0;
	for (Node n : nodes) {
		if (n.getColorID() > greatest) {
			greatest = n.getColorID();
		}
	}
	return greatest;
}

void Chromatic_map::clearColors() {
	//sets all color indices to 0, representing uncolored node
	for (Node i : nodes) {
		i.setColor(0);
	}
}

int Chromatic_map::checkAdjacentColors(int which, std::vector<bool> &visited) {
	//returns the lowest-index color based on those of any adjacent nodes
	int color = 1;
	bool allChecked = false;
	while (!allChecked) {
		allChecked = true;
		for (int i : nodes.at(which).getAdjacencies()) {
			if (!visited[i]) {
				//if not visited, will have no color; add it to the queue and keep going
				toCheck.push(i);
				visited[i] = 1;
			}
			else {
				if (color == nodes[i].getColorID()) {
					//use a new color; will have to recheck against any previous adjacencies
					color++;
					allChecked = false;
					break;
				}
			}
		}
	}
	return color;
}