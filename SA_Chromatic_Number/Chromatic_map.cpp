#include "Chromatic_map.h"

Chromatic_map::Chromatic_map() {}
Chromatic_map::~Chromatic_map() {}

void Chromatic_map::loadCountries(std::string path) {
	//creates nodes with names read from file
	try {
		std::ifstream readIn(path);
		std::string line;
		while (getline(readIn, line)) {
			Node newNode;
			newNode.setColor(0);
			newNode.setName(line);
			nodes.push_back(newNode);
		}
	}
	catch (std::exception e) {
		std::cerr << e.what() << std::endl;
	}
}

void Chromatic_map::loadColors(std::string path) {
	std::map<int, std::string> colors;
	try {
		std::ifstream readIn(path);
		std::string line;
		int i = 0;
		while (getline(readIn, line)) {
			colors.insert(std::make_pair(i, line));
			i++;
		}
	}
	catch (std::exception e) {
		std::cerr << e.what() << std::endl;
	}
	setAllowedColors(colors);
}
void Chromatic_map::setAllowedColors(std::map<int, std::string> input) {
	for (Node i : nodes) {
		i.setAllowedColors(input);
	}
}

int Chromatic_map::chromatic_number() {
	std::vector<int> results;
	for (int i = 0; i < adjacencies.size(); i++) {
		clearColors();
		toCheck.empty();
		results.push_back(calculate_chromatic_number(i));
	}
	int least = 7;
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
	for (int i = 0; i < adjacencies.at(startingNode).size(); i++) {
		if (adjacencies.at(startingNode).at(i)) {
			toCheck.push(i);
			visited[i] = 1;
		}
	}
	//run until all are checked
	while (!toCheck.empty()) {
		int next = toCheck.front();
		toCheck.pop();

		int color = checkAdjacentColors(next, visited);
		nodes[next].setColor(color);
	}
	int greatest = 0;
	for (Node n : nodes) {
		if (n.getColorID() > greatest) {
			greatest = n.getColorID();
		}
	}
	return greatest;
}

void Chromatic_map::clearColors() {
	for (Node i : nodes) {
		i.setColor(0);
	}
}

int Chromatic_map::checkAdjacentColors(int which, std::vector<bool> &visited) {
	//returns the lowest-index color based on those of any adjacent nodes
	int color = 1;
	bool allChecked = 0;
	while (!allChecked) {
		allChecked = true;
		for (int i = 0; i < adjacencies.size(); i++) {
			if (adjacencies[which][i]) {
				if (!visited[i]) {
					toCheck.push(i);
					visited[i] = 1;
					continue;//if not visited, will have no color and can continue the loop
				}
				else {
					//don't care if it matches itself
					if (i == which) {
						continue;
					}
					else if (color == nodes[i].getColorID()) {
						//use a new color; will have to recheck against any previous adjacencies
						color++;
						allChecked = false;
					}
				}

			}
		}
	}
	return color;
}