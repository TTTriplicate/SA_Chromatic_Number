#include "Node.h"

Node::Node() {}

Node::~Node() {}

void Node::setColor(int index) {
	color = index;
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