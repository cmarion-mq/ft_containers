#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include "vector.hpp"

#ifndef NS
# define NS ft
#endif

template <typename T, typename Allocator>
static void display(NS::vector<T, Allocator>& vect) {
    std::cout << "size: " << vect.size() << std::endl;
    std::cout << "max_size: " << vect.max_size() << std::endl;
    std::cout << "capacity: " << vect.capacity() << std::endl;
    std::cout << "empty: " << vect.empty() << std::endl;
	if (!vect.empty()){
		std::cout << "content: " << std::endl;
		for (size_t i = 0; i < vect.size(); i++) {
			std::cout << "::::: i " << i << "    " << vect[i] <<std::endl;}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

/*int main() {
	// NS::vector<int> first(42);
	// std::cout << first.max_size() << std::endl;
	// NS::vector<int> second(first.max_size() + 1);

	// NS::vector<int> second(10);
	// second.reserve(second.max_size() + 1);

	NS::vector<int> myvector (10);   // 10 zero-initialized ints
	myvector.at(11);
}*/
	typedef NS::vector<std::string, std::allocator<std::string> > strvector;
	typedef NS::vector<int, std::allocator<int> > intvector;
	typedef NS::vector<long, std::allocator<long> > longvector;
	typedef NS::vector<double, std::allocator<double> > doublevector;
	typedef NS::vector<char, std::allocator<char> > charvector;
	
	template <typename ForwardIt, typename T>
	void iota(ForwardIt first, ForwardIt last, T value = T())
	{
		while (first != last) {
			*first++ = value;
			++value;
		}
	}
	template <typename T>
	void PRINT_LINE(std::string msg, T value) {
        std::cout << msg << " " << (value) << std::endl;
    }


int main() {
 std::size_t s_size = 32;
    std::size_t b_size = 64;                                                                       
    (void)s_size;                                                                                  
    (void)b_size;                                                                                  
    std::string s_string[32] = {                                                                   
        "QExoqp0nICr0sXsHqty2", "naax9QcpJhvaL7DezsNQ", "25ZTtB6wbptfbxM8AvHB",                    
        "tShYNtc0MkdjqLrOatgz", "7Z3kf1Qec0NnsLSEpbOt", "WhkSNrKJC966fvjZ2Or1",                    
        "8vlxlFRRgW7yYj4GO7dt", "5sq1aoT8zP0HaHj3nFOK", "61Dv31GYZhkgjKCErpng",                    
        "l0IIcWWHhOcPzoxEamQM", "bE1RYclskwXlhCm46YFs", "kXeoi5qz94JYPqSDTs79",                    
        "TFsQP1dz8VVos9KzUpY0", "b3wYQR7An193gjgYuRj3", "xSmyNsnSJ47jLqrvbpyr",                    
        "guAIP2Wq43Gf8VhHsyu5", "yT6c2loPebHovnq9BQog", "3qvU1xcVm2g1DKFDlqh4",                    
        "L0q8RR9P41VD4sVjdnWl", "YdjESsIZM4b1oGQPjpBe", "l1ZVQbWKw7brHUSimJgq",                    
        "xdn0cf4vqRzpfXWtl10G", "lYnZvpqaV0s8DowMZwzV", "8P1cyKrwJNLoJyvLjYqO",                    
        "4MhOXNbAX23CEijO5cRT", "tHe3miAwCOVQbuoLaEP2", "l6uNLsc8fiLl3eWoG6j6",                    
        "477xt6l0lph9ALQdr4HX", "D9UJNe4s8YF02LhrwOdl", "dLCisBNOdE8yugntu6cj",                    
        "YvY4aQFHgAuagn4dFLO1", "eGR6Dtv7LW75qlV5Fkik"};                                                                                             
    std::string b_string[64] = {                                                                   
        "uvg6KqtcgduR31n3ajsv", "wbiAcjgojb9JOagZwyMn", "ATZKCzaPOqgkhPjwuGlf",                    
        "MOhaJs56yjOw8f6nLPRA", "0gyB2Tr42v6awMw2nK7J", "e6GsiLFUuoDpVFEhJKZ1",                    
        "z0jXAhiV9keBsaLOY0Xf", "P68p2ZAosHJdmoZh1C7N", "Pu3EuZVeY0TCO3ojdK0t",                    
        "z7jCHMooHCS73M8GygKB", "uT4KoK83JrZxZjkul7ty", "g8gfrZoY5XwfzRusvHvv",                    
        "7PGmkM0OSRnYREt9mFIP", "q1od7mBIpPEsCtpF9kdw", "XQo0LWId5TdZnLnpUNOb",                    
        "U0m1R0kFFhAFyS6hmHHw", "K0lPKfxJxIOnE8QB90xn", "cZ5xyQifMJhrKxqBK9A7",                    
        "cFBiwjfYw7Js6qEGy5Kt", "1tW0KWfXxeFO69tByqcE", "3Fvq9NxBrhPXHe0IlIVx",                    
        "MSRDjdFRvHAhFGhiMtDe", "zGm2joMh71jQkYzg5L4V", "Mq4RRaeLvSAO0z2ibp8Q",                    
        "WnLFYnQKP8TNJkqVVbUg", "E98UphbbVSzrW5Mzurmg", "F8HRxeEcaTZDkFPkioij",                    
        "jmUVl4Q8X5BwVNzXN219", "n7Xp4w4FwzGKit7AI4SO", "4MxXYr6rKOcXLt9UkVd2",                    
        "4RVTDsADtRyboaai9d29", "XaSqsrrtdhAfFoJIc5KK", "9Z9jdVCrTT09bg348ceb",                    
        "I6uqLG9dO5mfNdSMwOYm", "UwMTzJPlbnhgwbHpDi6w", "DebjMP9afncYE6GhhO00",                    
        "YGPuscYDiGfAjY1UWST0", "K6gbvgGjVZgEFUDlkdSk", "8xCBPI0w6TpC0RA62c2W",                    
        "fYMxkNwmKg3moP8KvD9v", "QpPdhwhEYjIugg3OPcPH", "qQBXjSn43I3EMP54SyxZ",                    
        "7qvdKwoW1CQEZTWPvuSC", "rCT212rdYO0zTGHXesKg", "dBHvlHsBwcR9MkkenYYG",                    
        "NQiSlergqR8fVbOeivLj", "xYVqsV147UIe7jVBVwXo", "tcxayO4DdEJ885TbqUMy",                    
        "9TGSMTD8U8ksRpHqq0cL", "TIJ16jCv9BSUiWvhbF9T", "BM9GL2ig1hePkA6lM6Ck",                    
        "TfJTYB9JQMU6CGcYg20Q", "Fg6e5YT2FQbpTZNTDqdo", "LI5q6ml40MeE9H1dPb93",                    
        "OaxJUSm3nYN9Y8Ela7sS", "BgBeODAwXz7xJo50Rwqd", "xdkgKj1dEoJ6zuVhkvvo",                    
        "olIewtUEvXJgs1lB9bCn", "dTsPDS0x2uXtcgOIJHb8", "DYvJ2phLppGNZKboTBrd",                    
        "DjNFMtt9PxkzqvWBHI6j", "1Z3YkeTFlPniKnzFhzgu", "76XqQg6hqMf5IXxKPOEs",                    
        "gzaapTWW7i9EZjjzLeK6"};

    		int s_int[32];                                                                               \
			iota(s_int, s_int + 32, (int)rand());
			int b_int[64];                                                                               \
			iota(b_int, b_int + 64, (int)rand());


	/*
	// ################################  CONSTRUCTORS  ##############
	std::cout << "\e[7m=============CONSTRUCTORS============\e[0m" << std::endl;
	{
		NS::vector<int> first; 			
		NS::vector<int> second;								// empty vector of ints
		NS::vector<int> third (second.begin(), second.end());	// iterating through second
		NS::vector<int> fourth (second);						// a copy of third
		int myints[] = {16,2,77,29};
		NS::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) ); // the iterator constructor can also be used to construct from arrays:
		NS::vector<int> sixth = fifth; // operator =

		std::cout << "The contents of FIRST are:" << std::endl;
		display(first);

		std::cout << "The contents of SECOND are:" << std::endl;
		display(second);

		std::cout << "The contents of THIRD are:" << std::endl;
		display(third);

		std::cout << "The contents of FOURTH are:" << std::endl;
		display(fourth);

		std::cout << "The contents of FIFTH are:" << std::endl;
		display(fifth);

		std::cout << "The contents of SIXTH are:" << std::endl;
		display(sixth);
	}
	std::cout << std::endl;
	// ################################  ITERATORS   ################
	std::cout << "\e[7m===============ITERATORS=============\e[0m" << std::endl;
	{
		NS::vector<int> myvector;
		for (int i=1; i<=5; i++) myvector.push_back(i);

		std::cout << "begin-end  myvector contains:" << std::endl;
		for (NS::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		std::cout << std::endl;
	}{
		NS::vector<int> myvector (5);  // 5 default-constructed ints
		int i=0;
		NS::vector<int>::reverse_iterator rit = myvector.rbegin();
		for (; rit!= myvector.rend(); ++rit)
		*rit = ++i;

		std::cout << "rbegin-rend myvector contains:" << std::endl;
		display(myvector);
	}
	std::cout << std::endl;
	// ################################  CAPACITY  ###############
	std::cout << "\e[7m=============CAPACITY============\e[0m" << std::endl;
	std::cout << "\033[31m***Resize***\033[0m" << std::endl;
	{
		NS::vector<int> myvector;
		for (int i=1;i<10;i++) myvector.push_back(i);
		std::cout << "myvector contains:" << std::endl;
		display(myvector);
		myvector.resize(5);
		std::cout << "resize(5)  myvector contains:" << std::endl;
		display(myvector);
		myvector.resize(8,100);
		std::cout << "resize(8,100)  myvector contains:" << std::endl;
		display(myvector);
		myvector.resize(12);
		std::cout << "resize(12)  myvector contains:" << std::endl;
		display(myvector);
	}
	std::cout << "\033[31m***Empty***\033[0m" << std::endl;
	{
		NS::vector<int> myvector;
		int sum (0);

		for (int i=1;i<=10;i++) myvector.push_back(i);
		std::cout << "myvector contains:" << std::endl;
		display(myvector);
		while (!myvector.empty()) {
			sum += myvector.back();
			myvector.pop_back();
		}
		std::cout << "total: " << sum << std::endl;
		std::cout << "after emptying myvector contains:" << std::endl;
		display(myvector);
	}
	std::cout << "\033[31m***Reserve***\033[0m" << std::endl;
	{
		NS::vector<int>::size_type sz;
		NS::vector<int> foo;
		sz = foo.capacity();
		std::cout << "making foo grow:" << std::endl;
		for (int i=0; i<100; ++i) {
			foo.push_back(i);
			if (sz!=foo.capacity()) {
				sz = foo.capacity();
				std::cout << "capacity changed: " << sz << std::endl;
			}
		}
		NS::vector<int> bar;
		sz = bar.capacity();
		bar.reserve(100);   // this is the only difference with foo above
		std::cout << "making bar grow:" << std::endl;
		for (int i=0; i<100; ++i) {
			bar.push_back(i);
			if (sz!=bar.capacity()) {
				sz = bar.capacity();
			std::cout << "capacity changed: " << sz << std::endl;
			}
		}
	}
	std::cout << std::endl;
	// ################################  ELEMENT ACCESS  ###############
	std::cout << "\e[7m=============ELEMENT ACCESS============\e[0m" << std::endl;
	std::cout << "\033[31m***Operator []***\033[0m" << std::endl;
	{
		NS::vector<int> myvector (10);   // 10 zero-initialized elements
		NS::vector<int>::size_type sz = myvector.size();

		for (unsigned i=0; i<sz; i++)
			myvector[i]=i; // assign some values:
		std::cout << "myvector contains:" << std::endl;
		display(myvector);
		for (unsigned i=0; i<sz/2; i++) { // reverse vector using operator[]:
			int temp;
			temp = myvector[sz-1-i];
			myvector[sz-1-i]=myvector[i];
			myvector[i]=temp;
		}
		std::cout << "myvector contains:" << std::endl;
		display(myvector);
	}
	std::cout << "\033[31m***At***\033[0m" << std::endl;
	{
		NS::vector<int> myvector (10);   // 10 zero-initialized ints

		for (unsigned i=0; i<myvector.size(); i++)
			myvector.at(i)=i; // assign some values:
		std::cout << "myvector contains:" << std::endl;
		display(myvector);
	}
	std::cout << "\033[31m***Front***\033[0m" << std::endl;
	{
		NS::vector<int> myvector;
		myvector.push_back(78);
		myvector.push_back(16); // now front equals 78, and back 16
		std::cout << "myvector contains:" << std::endl;
		display(myvector);
		myvector.front() -= myvector.back();
		std::cout << "myvector.front() -= myvector.back()  myvector contains:" << std::endl;
		display(myvector);
	}
	std::cout << "\033[31m***Back***\033[0m" << std::endl;
	{
		NS::vector<int> myvector;
		myvector.push_back(10);
		while (myvector.back() != 0) {
			myvector.push_back ( myvector.back() -1 );
		}
		std::cout << "myvector contains:" << std::endl;
		display(myvector);
	}
	// ################################  MODIFIERS  ###############
	std::cout << "\e[7m=============MODIFIERS============\e[0m" << std::endl;
	std::cout << "\033[31m***Assign***\033[0m" << std::endl;
	{
		NS::vector<int> first;
		NS::vector<int> second;
		NS::vector<int> third;
		
		first.assign (7,100);             // 7 ints with a value of 100
		second.assign (first.begin()+1, first.end()-1); // the 5 central values of first
		
		int myints[] = {1776,7,4};
		third.assign (myints,myints+3);   // assigning from array.
		std::cout << "First: " << std::endl;
		display(first);
		std::cout << "Second: " << std::endl;
		display(second);
		std::cout << "Third: " << std::endl;
		display(third);
	}
	std::cout << "\033[31m***Push back / Pop back***\033[0m" << std::endl;
	{
		NS::vector<int> myvector;
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);
		display(myvector);
		while (!myvector.empty()) {
			myvector.pop_back();
		}
		display(myvector);
	}
	std::cout << "\033[31m***Insert***\033[0m" << std::endl;
	{
		NS::vector<int> myvector (3,100);
		NS::vector<int>::iterator it = myvector.begin();
		it = myvector.insert ( it , 200 );
		std::cout << "myvector contains: " << std::endl;
		display(myvector);

		myvector.insert (it,2,300);
		std::cout << "myvector contains: " << std::endl;
		display(myvector);

		it = myvector.begin(); // "it" no longer valid, get a new one
		NS::vector<int> anothervector (2,400);
		myvector.insert (it+2,anothervector.begin(),anothervector.end());
		std::cout << "myvector contains: " << std::endl;
		display(myvector);

		int myarray [] = { 501,502,503 };
		myvector.insert (myvector.begin(), myarray, myarray+3);
		std::cout << "myvector contains: " << std::endl;
		display(myvector);
	}
	std::cout << "\033[31m***Erase***\033[0m" << std::endl;
	{
		NS::vector<int> myvector;
		for (int i=1; i<=10; i++)
			myvector.push_back(i);// set some values (from 1 to 10)
		std::cout << "myvector contains: " << std::endl;
		display(myvector);

		myvector.erase (myvector.begin()+5);// erase the 6th element
		std::cout << "myvector contains: " << std::endl;
		display(myvector);

		myvector.erase (myvector.begin(),myvector.begin()+3);// erase the first 3 elements:
		std::cout << "myvector contains: " << std::endl;
		display(myvector);
	}
	std::cout << "\033[31m***Swap***\033[0m" << std::endl;
	{
		NS::vector<int> foo (3,100);   // three ints with a value of 100
		NS::vector<int> bar (5,200);   // five ints with a value of 200

		foo.swap(bar);

		std::cout << "foo contains:";
		display(foo);
		std::cout << "bar contains:";
		display(bar);
	}
	std::cout << "\033[31m***Clear***\033[0m" << std::endl;
	{
		NS::vector<int> myvector;
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);

		std::cout << "myvector contains:";
		display(myvector);

		myvector.clear();
		std::cout << "myvector contains:";
		display(myvector);

		myvector.push_back (1101);
		myvector.push_back (2202);
		std::cout << "myvector contains: " << std::endl;
		display(myvector);
	}
	// ################################  ALLOCATOR  ###############
	std::cout << "\e[7m=============ALLOCATOR============\e[0m" << std::endl;
	{
		NS::vector<int> myvector;
		int * p;
		unsigned int i;

		p = myvector.get_allocator().allocate(5); // allocate an array with space for 5 elements using vector's allocator
		for (i=0; i<5; i++)
			myvector.get_allocator().construct(&p[i],i); // construct values in-place on the array

		std::cout << "myvector contains: " << std::endl;
		display(myvector);

	// destroy and deallocate:
		for (i=0; i<5; i++)
			myvector.get_allocator().destroy(&p[i]);
		myvector.get_allocator().deallocate(p,5);
	}
	// ################################  RELATIONAL OPERATORS  ###############
	std::cout << "\e[7m=============RELATIONAL OPERATORS============\e[0m" << std::endl;
	{
		NS::vector<int> foo (3,100);   // three ints with a value of 100
		NS::vector<int> bar (2,200);   // two ints with a value of 200

		if (foo == bar) std::cout << "foo and bar are equal" << std::endl;;
		if (foo != bar) std::cout << "foo and bar are not equal" << std::endl;;
		if (foo < bar) std::cout << "foo is less than bar" << std::endl;;
		if (foo > bar) std::cout << "foo is greater than bar" << std::endl;;
		if (foo <= bar) std::cout << "foo is less than or equal to bar" << std::endl;;
		if (foo >= bar) std::cout << "foo is greater than or equal to bar" << std::endl;;
	}
	// ################################  RELATIONAL OPERATORS  ###############
	std::cout << "\e[7m=============SWAP Overload============\e[0m" << std::endl;
	{
		NS::vector<int> foo (3,100);   // three ints with a value of 100
		NS::vector<int> bar (5,200);   // five ints with a value of 200
		swap(foo, bar);

		std::cout << "foo contains:";
		display(foo);
		std::cout << "bar contains:";
		display(bar);
	}
		return (0);
	*/
}