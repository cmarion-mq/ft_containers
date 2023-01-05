#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include "vector.hpp"

#ifndef NS
# define NS ft
#endif

int main() {
// ###############  CONSTRUCTORS  ###############
	NS::vector<int> first;                                // empty vector of ints
	NS::vector<int> second (4,100);                       // four ints with value 100
	NS::vector<int> third (second.begin(), second.end());  // iterating through second
	NS::vector<int> fourth (second);                       // a copy of third
	int myints[] = {16,2,77,29};
	NS::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) ); // the iterator constructor can also be used to construct from arrays:
	NS::vector<int> sixth = fifth; // operator =

	std::cout << "The contents of FIRST are:";
	for (NS::vector<int>::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << ' ' << *it;
  	std::cout << std::endl;

	std::cout << "The contents of SECOND are:";
	for (NS::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << "The contents of THIRD are:";
	for (NS::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << "The contents of FOURTH are:";
	for (NS::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
		std::cout << ' ' << *it;	
	std::cout << std::endl;

	std::cout << "The contents of FIFTH are:";
	for (NS::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)	
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << "The contents of XIXTH are:";
	for (NS::vector<int>::iterator it = sixth.begin(); it != sixth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

// ###############  CAPACITY  ###############
	NS::vector<int> myvector;
	for (int i=0; i<100; i++) myvector.push_back(i); // set some content in the vector
	std::cout << "myvector size: " << myvector.size() << std::endl;
	std::cout << "myvector capacity: " << myvector.capacity() << std::endl;
	std::cout << "myvector max_size: " << myvector.max_size() << std::endl;
	std::cout << "first empty?: " << first.empty() << std::endl;
	std::cout << "myvector empty?: " << myvector.empty() << std::endl;
	second.resize(10);
	std::cout << "Resize 10 SECOND contains:";
	for (size_t i = 0; i < second.size(); i++)
    	std::cout << ' ' << second[i];
	std::cout << std::endl;

  	second.resize(8,100);
	std::cout << "SECOND contains:";
	for (size_t i = 0;i < second.size(); i++)
    	std::cout << ' ' << second[i];
	std::cout << std::endl;

  	second.resize(15,5);
	std::cout << "SECOND contains:";
	for (size_t i=0;i<second.size(); i++)
    	std::cout << ' ' << second[i];
	std::cout << std::endl;

// ###############  MODIFIERS  ###############
	{
		NS::vector<int> first (3,100);
		NS::vector<int>::iterator it = first.begin();
		it = first.insert ( it , 200 );
		std::cout << "myvector contains:";
		for (it = first.begin(); it < first.end(); it++)
			std::cout << ' ' << *it;
		std::cout << std::endl;

		first.insert (it,2,300);
		std::cout << "myvector contains:";
		for (it = first.begin(); it < first.end(); it++)
			std::cout << ' ' << *it;
		std::cout << std::endl;

		it = first.begin(); // "it" no longer valid, get a new one
		NS::vector<int> anothervector (2,400);
		first.insert (it+2,anothervector.begin(),anothervector.end());
		std::cout << "myvector contains:";
		for (it = first.begin(); it < first.end(); it++)
			std::cout << ' ' << *it;
		std::cout << std::endl;

		int myarray [] = { 501,502,503 };
		first.insert (first.begin(), myarray, myarray+3);
		std::cout << "myvector contains:";
		for (it = first.begin(); it < first.end(); it++)
			std::cout << ' ' << *it;
		std::cout << std::endl;
	}
	{
		NS::vector<int> myvector;
		
		for (int i=1; i<=10; i++) myvector.push_back(i);// set some values (from 1 to 10)
		
		myvector.erase (myvector.begin()+5);// erase the 6th element
		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); ++i)
			std::cout << ' ' << myvector[i];
		std::cout << std::endl;

		myvector.erase (myvector.begin(),myvector.begin()+3);// erase the first 3 elements:
		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); ++i)
			std::cout << ' ' << myvector[i];
		std::cout << std::endl;
	}

// ###############  ELEMENT ACCESS  ###############
	{
		NS::vector<int> myvector (10);   // 10 zero-initialized ints

		for (unsigned i=0; i<myvector.size(); i++)
    		myvector.at(i)=i; // assign some values

		std::cout << "myvector contains:";
  		for (unsigned i=0; i<myvector.size(); i++)
    		std::cout << ' ' << myvector.at(i);
  		std::cout << std::endl;
		//myvector.at(12);
	}
	return 0;
}