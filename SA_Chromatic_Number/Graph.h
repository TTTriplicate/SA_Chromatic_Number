#pragma once
#include <vector>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
class Graph
{
protected:
	std::vector <std::vector<bool>> adjacencies;
public:
	void loadAdjacencies(std::string path);
};
