#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include "vector.hpp"
#include <map>
#include "map.hpp"

#ifndef NS
# define NS ft
#endif

int main() {
	ft::map<int, int> map_int;
	map_int.insert(ft::pair<const int, int> (65,4));
	map_int.insert(ft::pair<const int, int> (75,6));
	map_int.insert(ft::pair<const int, int> (60,4));
	map_int.insert(ft::pair<const int, int> (57,6));
	map_int.insert(ft::pair<const int, int> (40,0));
	// map_int.erase(65);
	
	map_int.print();
	// std::cout << "count 3: " << map_int.count(3) << std::endl;
	// std::cout << "count 1: " << map_int.count(1) << std::endl;
	// std::cout << "empty: " << map_int.empty() << std::endl;
	// std::cout << "max size: " << map_int.max_size() << std::endl;
}