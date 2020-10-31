#pragma once
#include "Graph.h"
class Chromatic_map :
    public Graph
{
private:
    std::map<int, std::string> Colors;
    void clearColors();

    int calculate_chromatic_number(int startingNode);
    int checkAdjacentColors(int which);

public:
    Chromatic_map();
    ~Chromatic_map();
    int chromatic_number();
    void loadColors(std::string path);
    void printCountriesAndColors();
};