#pragma once
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <queue>
#include "Node.h"

class Graph
{
protected:
	std::vector <std::vector<bool>> adjacencies;
	std::vector<Node> nodes;
public:
	void loadAdjacencies(std::string path);
	std::queue<int> BreadthFirstSearch(int start);
	void loadNodes(std::string path);
};