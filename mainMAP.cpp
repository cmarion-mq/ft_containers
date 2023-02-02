#include <iostream>
#include <string>
#include <stdlib.h>
#include "map.hpp"
#include <vector>

int main() {
	std::vector<ft::pair<const int, int >> vector_int = {{1,2},{3,4},{5,6}};
	// ft::map<int, int> map_int;
	ft::map<int, int> map_int(vector_int.begin(), vector_int.end());
	// /map_int.clear();
	map_int.print();
	std::cout << "empty: " << map_int.empty() << std::endl;
	std::cout << "max size: " << map_int.max_size() << std::endl;
}