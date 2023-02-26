#include <iostream>
#include <string>
#include <stdlib.h>
#include <map>
#include "map.hpp"

#ifndef NS
# define NS ft
#endif

template<typename Key, typename Value>
std::ostream& operator<<(std::ostream& os, NS::map<Key, Value> const& m)
{
   os << "{ ";
   for(NS::map<Key, Value>::iterator p = m.begin(); p != m.end(); ++ p)
        os << '(' << p.first << ':' << p.second << ") ";
   return os << "}\n";
}
 
 struct PointCmp {
    bool operator()(const int &lhs, const int &rhs) const {
        return lhs > rhs;
    }
};

int main() {
// ################################  CONSTRUCTORS  ##############
	std::cout << "\e[7m=============CONSTRUCTORS============\e[0m" << std::endl;
	{
		// (1) Default constructor
		NS::map<std::string, int> map1;
		map1["something"] = 69;
		map1["anything"] = 199;
		map1["that thing"] = 50;
		std::cout << "map1 = " << map1;
		
		// (4) Range constructor
		NS::map<std::string, int> iter(map1.find("anything"), map1.end());
		std::cout << "\niter = " << iter;
		std::cout << "map1 = " << map1;
		
		// (6) Copy constructor
		NS::map<std::string, int> copied(map1);
		std::cout << "\ncopied = " << copied;
		std::cout << "map1 = " << map1;
		
		std::cout << "\nCustom Key class option 1:\n";
		// Use a comparison struct
		NS::map<int, double, PointCmp> mag;
		mag[5] = 13;
		mag[4] = 5;
		mag[15] = 17;	
		for(NS::map<int, double, PointCmp>::iterator p = mag.begin(); p != mag.end(); ++ p)
			std::cout << "first " << p. << ", is " << *p.second << '\n';
	}
	std::cout << std::endl;







	ft::map<int, int> map_int;
	map_int.insert(ft::pair<const int, int> (65,4));
	map_int.insert(ft::pair<const int, int> (75,6));
	map_int.insert(ft::pair<const int, int> (60,4));
	map_int.insert(ft::pair<const int, int> (57,6));
	map_int.insert(ft::pair<const int, int> (40,0));
	map_int.erase(65);
	
	map_int.print();
	// std::cout << "count 3: " << map_int.count(3) << std::endl;
	// std::cout << "count 1: " << map_int.count(1) << std::endl;
	// std::cout << "empty: " << map_int.empty() << std::endl;
	// std::cout << "max size: " << map_int.max_size() << std::endl;
}