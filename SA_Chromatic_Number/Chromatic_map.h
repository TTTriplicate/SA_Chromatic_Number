#pragma once
#include "Graph.h"
#include "Node.h"
#include <queue>
class Chromatic_map :
    public Graph
{
public:
    Chromatic_map();
    ~Chromatic_map();
    int chromatic_number();
    void loadCountries(std::string path);
    void loadColors(std::string path);
private:
    std::vector<Node> nodes;
    std::queue<int> toCheck;
    void clearColors();
    void setAllowedColors(std::map<int, std::string> input);

    int calculate_chromatic_number(int startingNode);
    int checkAdjacentColors(int which, std::vector<bool>& visited);
};

