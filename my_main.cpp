#include <iostream>
#include <string>
#include <vector>
#include "vector.hpp"
#include <stdlib.h>

int main() {
// ###############  CONSTRUCTORS  ###############
	ft::vector<int> first;                                // empty vector of ints
	ft::vector<int> second (4,100);                       // four ints with value 100
	ft::vector<int> third (second.begin(), second.end());  // iterating through second
	ft::vector<int> fourth (second);                       // a copy of third
	int myints[] = {16,2,77,29};
	ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) ); // the iterator constructor can also be used to construct from arrays:
	ft::vector<int> sixth = fifth; // operator =

	std::cout << "The contents of FIRST are:";
	for (ft::vector<int>::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << ' ' << *it;
  	std::cout << std::endl;

	std::cout << "The contents of SECOND are:";
	for (ft::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << "The contents of THIRD are:";
	for (ft::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << "The contents of FOURTH are:";
	for (ft::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
		std::cout << ' ' << *it;	
	std::cout << std::endl;

	std::cout << "The contents of FIFTH are:";
	for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)	
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << "The contents of XIXTH are:";
	for (ft::vector<int>::iterator it = sixth.begin(); it != sixth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

// ###############  CAPACITY  ###############
	ft::vector<int> myvector;
	for (int i=0; i<100; i++) myvector.push_back(i); // set some content in the vector
	std::cout << "myvector size: " << myvector.size() << std::endl;
	std::cout << "myvector capacity: " << myvector.capacity() << std::endl;
	std::cout << "myvector max_size: " << myvector.max_size() << std::endl;
	std::cout << "first empty?: " << first.empty() << std::endl;
	std::cout << "myvector empty?: " << myvector.empty() << std::endl;

	second.insert(second.begin() + 2, 3);

	second.resize(10);
	std::cout << "SECOND contains:";
	for (int i=0;i<second.size();i++)
    	std::cout << ' ' << second[i];
	std::cout << std::endl;

  	second.resize(8,100);
	std::cout << "SECOND contains:";
	for (int i=0;i<second.size();i++)
    	std::cout << ' ' << second[i];
	std::cout << std::endl;

	return 0;
}