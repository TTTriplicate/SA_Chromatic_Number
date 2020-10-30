#include "Node.h"

Node::Node() {}

Node::~Node() {}

void Node::setColor(int index) {
	color = index;
}
int Node::getColorID() {
	return color;
}

void Node::setName(std::string nodeName) {
	name = nodeName;
}
std::string Node::getName() {
	return name;
}

void Node::setAdjacencies(std::vector<bool> input) {
	for (std::vector<bool>::size_type i = 0; i < input.size(); i++) {
		if (input.at(i)) {
			adjacent.push_back(i);
		}
	}
}
