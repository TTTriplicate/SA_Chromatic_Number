#pragma once
#include <string>
#include <map>
#include <stdexcept>
class Node
{
private:
	std::string name;
	int color = 0;
	std::map<int, std::string> Color{//functions as an Enum that can return a string value
		{0, "NULL"}, {1, "Red"}, {2, "Green"}, {3, "Blue"},
		{4, "Yellow"}, {5, "Magenta"}, {6, "Cyan"}, {7, "Orange"}
		};
public:
	Node();
	~Node();
	void setColor(int index);
	int getColorID();
	std::string getColorString();
	void setName(std::string nodeName);
	std::string getName();
	void setAllowedColors(std::map<int, std::string> colorMap);
};

