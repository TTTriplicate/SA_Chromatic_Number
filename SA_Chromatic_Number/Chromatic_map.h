#pragma once
#include "Graph.h"
#include "Node.h"
class Chromatic_map :
    public Graph
{
public:
    Chromatic_map();
    Chromatic_map(std::string filepath);
    int chromatic_number();
private:
    int calculate_chromatic_number();
};

