#include "Chromatic_map.h"

Chromatic_map::Chromatic_map() {
	for (int i = 0; i < 14; i++) {
		Node newNode;
		newNode.setColor(0);
		nodes.push_back(newNode);
	}
}
Chromatic_map::~Chromatic_map() {}

int Chromatic_map::chromatic_number() {
	std::vector<int> results;
	for (int i = 0; i < adjacencies.size(); i++) {
		clearColors();
		toCheck.empty();
		results.push_back(calculate_chromatic_number(i));
	}
	return 1;
}

int Chromatic_map::calculate_chromatic_number(int startingNode) {
	nodes[startingNode].setColor(1);
	for (int i = 0; i < adjacencies.at(startingNode).size(); i++) {
		if (adjacencies.at(startingNode).at(i)) {
			toCheck.push(nodes.at(i));
		}
	}
	return 1;
}

void Chromatic_map::clearColors() {
	for (Node i : nodes) {
		i.setColor(0);
	}
}
bool Chromatic_map::allColored() {
	for (Node i : nodes) {
		if (!i.getColorID()) {
			return false;
		}
	}
	return true;
}