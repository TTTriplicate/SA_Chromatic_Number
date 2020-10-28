#pragma once
#include "Graph.h"
#include "Node.h"
class Chromatic_map :
    public Graph
{
public:
    Chromatic_map();
    ~Chromatic_map();
    int chromatic_number();
    void loadCountries(std::string path);
//private:
    std::vector<Node> nodes;
    std::queue<Node> toCheck;
    void clearColors();
    int checkAdjacentColors(int which);
    bool allColored();

    int calculate_chromatic_number(int startingNode);
};

