#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <map>
#include "map.hpp"

#ifndef NS
# define NS ft
#endif

int main() {
	std::vector<ft::pair<const int, int > > vector_int = {{55,2}, {65,4}, {75,6}, {60,4}, {57,6}, {40,0}};
	// ft::map<int, int> map_int;
	NS::map<int, int> map_int(vector_int.begin(), vector_int.end());
	map_int.erase(65);
	map_int.print();
	// std::cout << "count 3: " << map_int.count(3) << std::endl;
	// std::cout << "count 1: " << map_int.count(1) << std::endl;
	// std::cout << "empty: " << map_int.empty() << std::endl;
	// std::cout << "max size: " << map_int.max_size() << std::endl;
}