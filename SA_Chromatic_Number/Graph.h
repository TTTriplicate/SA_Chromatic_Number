#pragma once
#include <vector>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Node.h"

class Graph
{
protected:
	std::vector <std::vector<bool>> adjacencies;
	std::vector<Node> nodes;
public:
	void loadAdjacencies(std::string path);
};
