#pragma once
#include <string>
#include <map>
#include <stdexcept>
#include <vector>

class Node
{
private:
	std::string name;
	int color = 0;
	std::vector<int> adjacent;
public:
	Node();
	~Node();
	void setColor(int index);
	int getColorID();
	void setName(std::string nodeName);
	std::string getName();
	void setAdjacencies(std::vector<bool> input);
	std::vector<int> getAdjacencies();
};