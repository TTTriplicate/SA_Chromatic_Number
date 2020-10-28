// SA_Chromatic_Number.cpp
// Author: chris Sousa
// A exploration of grph theory, specifically chromatic numbers
// using an adjacency matrix of South America

#include <iostream>

#include "Chromatic_map.h"

int main()
{
	Chromatic_map South_America;

	South_America.loadAdjacencies("adjacencies.txt");
	South_America.loadCountries("countries.txt");

	std::cout << South_America.chromatic_number();
}