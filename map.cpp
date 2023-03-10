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
void print(const NS::map<Key, Value, Compare> &map) {
	std::cout << "size = " << map.size() << std::endl;
	for(typename NS::map<Key, Value, Compare>::const_iterator p = map.begin(); p != map.end(); ++ p)
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
		print(mymap);

  		mymap.at("alpha") = 10;
  		mymap.at("beta") = 20;
  		mymap.at("gamma") = 30;
		// std::cout << mymap.at("test") << std::endl;
		
		print(mymap);
	}
// ################################  MODIFIERS  ##############
	std::cout << "\e[7m=============MODIFIERS============\e[0m" << std::endl;
	{
		std::cout << "\e[7m Insert \e[0m" << std::endl;
		NS::map<char,int> mymap;
		// first insert function version (single parameter):
		mymap.insert ( NS::pair<const char,int>('a',100) );
		mymap.insert ( NS::pair<const char,int>('z',200) );

		NS::pair<NS::map<const char,int>::iterator,bool> ret;
		ret = mymap.insert ( NS::pair<const char,int>('z',500) );
		if (ret.second==false) {
			std::cout << "element 'z' already existed";
			std::cout << " with a value of " << ret.first->second << std::endl;
		}

		// // second insert function version (with hint position):
		// NS::map<const char,int>::iterator it = mymap.begin();
		// mymap.insert (it, NS::pair<const char,int>('b',300));  // max efficiency inserting
		// mymap.insert (it, NS::pair<const char,int>('c',400));  // no max efficiency insertiNS
		
		// third insert function version (range insertion):
		NS::map<char,int> anothermap;
		anothermap.insert(mymap.begin(),mymap.find('c'));

		// showing contents:
		std::cout << "mymap contains:" << std::endl; 
		print(mymap);
		std::cout << "anothermap contains:" << std::endl;
		print(anothermap);
	}
	{
		std::cout << "\e[7m Erase \e[0m" << std::endl;
		NS::map<char,int> mymap;
		NS::map<char,int>::iterator it;
		// insert some values:
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;
		std::cout << "mymap contains:" << std::endl;
		print(mymap);
		it=mymap.find('b');
		mymap.erase (it);                   // erasing by iterator
		mymap.erase ('c'); 					// erasing by key
		std::cout << "mymap contains:" << std::endl;
		print(mymap);                 
		it=mymap.find ('e');
		mymap.erase ( it, mymap.end() );    // erasing by range
		std::cout << "mymap contains:" << std::endl;
		print(mymap);
	}
	{
		std::cout << "\e[7m Swap \e[0m" << std::endl;
		NS::map<char,int> foo,bar;
		foo['x']=100;
		foo['y']=200;
		bar['a']=11;
		bar['b']=22;
		bar['c']=33;
		foo.swap(bar);
		std::cout << "foo contains:" << std::endl;
		print(foo);
		std::cout << "bar contains:" << std::endl;
		print(bar);
	}
	{
		std::cout << "\e[7m Clear \e[0m" << std::endl;
		NS::map<char,int> mymap;
		mymap['x']=100;
		mymap['y']=200;
		mymap['z']=300;
		std::cout << "mymap contains:" << std::endl;
		print(mymap);
		mymap.clear();
		std::cout << "mymap contains:" << std::endl;
		print(mymap);
		mymap['a']=1101;
		mymap['b']=2202;
		std::cout << "mymap contains:" << std::endl;
		print(mymap);
	}
// ################################  OPERATIONS  ##############
	std::cout << "\e[7m=============OPERATIONS============\e[0m" << std::endl;
	{
		std::cout << "\e[7m Find \e[0m" << std::endl;
		NS::map<char,int> mymap;
		NS::map<char,int>::iterator it;

		mymap['a']=50;
		mymap['b']=100;
		mymap['c']=150;
		mymap['d']=200;

		it = mymap.find('b');
		if (it != mymap.end())
			mymap.erase (it);

		// print content:
		std::cout << "elements in mymap:" << std::endl;
		std::cout << "a => " << mymap.find('a')->second << std::endl;
		std::cout << "c => " << mymap.find('c')->second << std::endl;
		std::cout << "d => " << mymap.find('d')->second << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "\e[7m Count \e[0m" << std::endl;
		NS::map<char,int> mymap;
		char c;
		mymap ['a']=101;
		mymap ['c']=202;
		mymap ['f']=303;
		for (c='a'; c<'h'; c++)
		{
			std::cout << c;
			if (mymap.count(c)>0)
			std::cout << " is an element of mymap." << std::endl;
			else 
			std::cout << " is not an element of mymap." << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "\e[7m Lower/Upper_bound \e[0m" << std::endl;
		NS::map<char,int> mymap;
		NS::map<char,int>::iterator itlow,itup;

		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;

		itlow=mymap.lower_bound ('b');  // itlow points to b
		itup=mymap.upper_bound ('d');   // itup points to e (not d!)

		mymap.erase(itlow,itup);        // erases [itlow,itup)
		print(mymap);
	}
}