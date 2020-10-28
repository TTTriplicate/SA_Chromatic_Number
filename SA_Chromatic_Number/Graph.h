#pragma once
#include <vector>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
class Graph
{
public:
	std::vector <std::vector<bool>> adjacencies;
	void loadAdjacencies(std::string path);
};
