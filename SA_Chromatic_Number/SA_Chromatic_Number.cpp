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

	for (std::vector<bool> row : South_America.adjacencies) {
		for (bool i : row) {
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}

	std::cout << South_America.chromatic_number();
}