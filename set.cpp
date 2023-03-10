#include <iostream>
#include <string>
#include <stdlib.h>
#include <set>
#include "set.hpp"

#ifndef NS
# define NS ft
#endif

template <typename T, typename Allocator>
static void display(NS::set<T, Allocator>& set) {
    std::cout << "size: " << set.size() << std::endl;
    std::cout << "max_size: " << set.max_size() << std::endl;
    std::cout << "empty: " << set.empty() << std::endl;
	if (!set.empty()){
		std::cout << "content: " << std::endl;
        // typename ft::set<T, Allocator>::const_iterator val = set.begin();
		// for (size_t i = 0; i < set.size(); i++) {
		// 	std::cout << "::::: i " << i << "    " << *val <<std::endl;
        //     val ++;
        // }
		// std::cout << std::endl;
	}
	std::cout << std::endl;
}

bool fncomp (int lhs, int rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs<rhs;}
};

int main() {
	// ################################  CONSTRUCTORS  ##############
    {
        NS::set<int> first;                           // empty set of ints
        display(first);

        int myints[]= {10,20,30,40,50};
        NS::set<int> second (myints,myints+5);        // range
        display(second);

        NS::set<int> third (second);                  // a copy of second
        display(third);

        NS::set<int> fourth (second.begin(), second.end());  // iterator ctor.
        display(fourth);

        NS::set<int,classcomp> fifth;                 // class as Compare
        display(fifth);

        bool(*fn_pt)(int,int) = fncomp;
        NS::set<int,bool(*)(int,int)> sixth (fn_pt);  // function pointer as Compare
        display(sixth);
    }
}