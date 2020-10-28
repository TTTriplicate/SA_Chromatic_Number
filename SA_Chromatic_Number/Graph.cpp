
#include "Graph.h"


void Graph::loadAdjacencies(std::string path) {
	//reads an adjacency matrix from a specified file
	try {
		std::ifstream readIn(path);
		std::string line;
		bool adjacent;
		int i = 0;
		while (getline(readIn, line)) {
			std::vector<bool> newRow;
			adjacencies.push_back(newRow);
			std::istringstream row(line);
			while (row >> adjacent) {
				adjacencies.at(i).push_back(adjacent);
			}
			i++;
		}
	}
	catch (std::invalid_argument e) {
		std::cerr << e.what() << std::endl;
	}
}