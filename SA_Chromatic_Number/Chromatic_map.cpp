// Chromatic_map.cpp
// Inherits basic functionality from Graph.cpp
// Adds logic for handling coors and calculating the chromatic number of the graph
#include "Chromatic_map.h"

Chromatic_map::Chromatic_map() {}
Chromatic_map::~Chromatic_map() {}


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
		results.push_back(calculate_chromatic_number(i));
	}
	int least = Colors.size();
	int finalSet = 0;
	for (auto i = 0; i < results.size(); i++) {
		if (results.at(i) < least) {
			least = results.at(i);
			finalSet = i;
		}
	}
	clearColors();
	calculate_chromatic_number(finalSet);
	return least;
}

int Chromatic_map::calculate_chromatic_number(int startingNode) {
	//set initial node color and get first round of adjacencies
	nodes.at(startingNode).setColor(1);
	std::queue<int> toCheck = BreadthFirstSearch(startingNode);
	//run until all are checked; since there are no disconnected nodes, it will hit them all
	while (!toCheck.empty()) {
		int next = toCheck.front();
		toCheck.pop();

		int color = checkAdjacentColors(next);
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

int Chromatic_map::checkAdjacentColors(int which) {
	//returns the lowest-index color based on those of any adjacent nodes
	int color = 1;
	bool allChecked = false;
	while (!allChecked) {
		allChecked = true;
		for (int i : nodes.at(which).getAdjacencies()) {
			if (color == nodes[i].getColorID()) {
				//use a new color; will have to recheck against any previous adjacencies
				color++;
				allChecked = false;
				break;
			}
		}
	}
	return color;
}

void Chromatic_map::printCountriesAndColors() {
	for (Node country : nodes) {
		std::cout << country.getName() << " : " << Colors.at(country.getColorID()) << std::endl;
	}
}