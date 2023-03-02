#include <iostream>
#include <string>
#include <stdlib.h>
#include <map>
#include "map.hpp"

#ifndef NS
# define NS ft
#endif
 
 struct PointCmp {
    bool operator()(const int &lhs, const int &rhs) const {
        return lhs > rhs;
    }
};

template<class Key, class Value, class Compare>
void print(NS::map<Key, Value, Compare> map) {
	std::cout << "size = " << map.size() << std::endl;
	for(typename NS::map<Key, Value, Compare>::iterator p = map.begin(); p != map.end(); ++ p)
			std::cout << (*p).first << ", is " << (*p).second << std::endl;
	std::cout << std::endl;
};

int main() {
// ################################  CONSTRUCTORS  ##############
	std::cout << "\e[7m=============CONSTRUCTORS============\e[0m" << std::endl;
	{
		// (1) Default constructor
		NS::map<std::string, int> map1;
		map1["1"] = 69;
		map1["2"] = 199;
		map1["3"] = 50;
		print(map1);
		
		// (4) Range constructor
		NS::map<std::string, int> iter(map1.find("anything"), map1.end());
		std::cout << "iter = " << std::endl;
		print(iter);
		std::cout << "map1 = " << std::endl;
		print(map1);
		
		// (6) Copy constructor
		NS::map<std::string, int> copied(map1);
		std::cout << "copied = " << std::endl;
		print(copied);
		std::cout << "map1 = " << std::endl;
		print(map1);
		
		std::cout << "\nCustom Key class option 1:\n";
		// Use a comparison struct
		NS::map<int, double, PointCmp> mag;
		mag[5] = 13;
		mag[4] = 5;
		mag[15] = 17;	
		print(mag);
	}
	std::cout << std::endl;

// ################################  ELEMENT ACCESS  ##############
	std::cout << "\e[7m=============ELEMENT ACCESS============\e[0m" << std::endl;
	{
		NS::map<std::string,int> mymap;
        mymap["alpha"] = 0;
        mymap["beta"] = 0;
        mymap["gamma"] = 0;
  		// mymap.at("alpha") = 10;
  		// mymap.at("beta") = 20;
  		// mymap.at("gamma") = 30;

		print(mymap);
	}





	NS::map<int, int> map_int;
	map_int.insert(NS::pair<const int, int> (65,4));
	map_int.insert(NS::pair<const int, int> (75,6));
	map_int.insert(NS::pair<const int, int> (60,4));
	map_int.insert(NS::pair<const int, int> (57,6));
	map_int.insert(NS::pair<const int, int> (40,0));
	map_int.erase(65);
	
	print(map_int);
	// std::cout << "count 3: " << map_int.count(3) << std::endl;
	// std::cout << "count 1: " << map_int.count(1) << std::endl;
	// std::cout << "empty: " << map_int.empty() << std::endl;
	// std::cout << "max size: " << map_int.max_size() << std::endl;
}