#pragma once
#include <string>
#include <map>
#include <stdexcept>
class Node
{
private:
	std::string name;
	int color = 0;
public:
	Node();
	~Node();
	void setColor(int index);
	int getColorID();
	void setName(std::string nodeName);
	std::string getName();
};

