#include "Node.h"

Node::Node() {}

Node::~Node() {}

void Node::setColor(int index) {
	if (index > Color.size()) {
		throw std::invalid_argument("No currently mapped colors match the key: " + index);
	}
	color = index;
}

void Node::setAllowedColors(std::map<int, std::string> colorMap) {
	Color = colorMap;
}

int Node::getColorID() {
	return color;
}
std::string Node::getColorString() {
	return Color[color];
}

void Node::setName(std::string nodeName) {
	name = nodeName;
}
std::string Node::getName() {
	return name;
}