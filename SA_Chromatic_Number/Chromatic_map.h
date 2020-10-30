#pragma once
#include "Graph.h"
#include <queue>
class Chromatic_map :
    public Graph
{
private:
    std::map<int, std::string> Colors;
    std::queue<int> toCheck;
    void clearColors();

    int calculate_chromatic_number(int startingNode);
    int checkAdjacentColors(int which, std::vector<bool>& visited);

public:
    Chromatic_map();
    ~Chromatic_map();
    int chromatic_number();
    void loadCountries(std::string path);
    void loadColors(std::string path);
    void printCountriesAndColors();
};

