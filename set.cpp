#include <iostream>
#include <string>
#include <stdlib.h>
#include <set>
#include "set.hpp"

#include <limits>


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

template <typename ForwardIt, typename T>
void iota(ForwardIt first, ForwardIt last, T value = T())
{
    while (first != last) {
        *first++ = value;
        ++value;
    }
}

template <typename T>
void init_array(T* arr, std::size_t size)
{
    iota(arr, arr + size, (T)rand());
}

typedef NS::set<int, std::less<int>, std::allocator<int> > intset;
typedef NS::set<std::string, std::less<std::string>, std::allocator<std::string> > strset;

void PRINT_BOUND(intset::iterator b, intset::iterator end)                                                                        \
{
    if (b != end) {       
        std::cout << "Value" << " " << *b;
    } else {     
        std::cout << "End iterator";
    }
    std::cout << std::endl;
}


int main() {
    
    int int_arr[64];
    init_array(int_arr, 64);
    std::size_t int_size = 64;
    std::size_t str_size = 32;
    (void)int_size;
    (void)str_size;
    std::string str_arr[32] = {
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
        "YvY4aQFHgAuagn4dFLO1", "eGR6Dtv7LW75qlV5Fkik"
    };
    {
        intset m(int_arr, int_arr + int_size);

        m.insert(34);
        m.insert(3468);
        m.insert(96533);
        m.insert(1954894589);
        m.insert(7754322);
        m.insert(3632);
        m.insert(3);
        m.insert(4);
        m.insert(-873487);
        m.insert(-95763433);
        m.insert(453834782);
        m.insert(19458942);
        m.insert(1245689793);

        intset::iterator b = m.lower_bound(98583944);

        PRINT_BOUND(b, m.end());

        b = m.lower_bound(209485948);

        PRINT_BOUND(b, m.end());

        b = m.lower_bound(19458942);

        PRINT_BOUND(b, m.end());

        b = m.lower_bound(19458941);

        PRINT_BOUND(b, m.end());

        b = m.lower_bound(19458943);

        PRINT_BOUND(b, m.end());

        b = m.lower_bound(-1);

        PRINT_BOUND(b, m.end());

        b = m.lower_bound(3);

        PRINT_BOUND(b, m.end());

        b = m.lower_bound(4);

        PRINT_BOUND(b, m.end());

        b = m.lower_bound(5);

        PRINT_BOUND(b, m.end());

        b = m.lower_bound(0);

        PRINT_BOUND(b, m.end());

        b = m.lower_bound(std::numeric_limits<int>::max());

        PRINT_BOUND(b, m.end());

        m.insert(std::numeric_limits<int>::max());

        b = m.lower_bound(std::numeric_limits<int>::max());

        PRINT_BOUND(b, m.end());
    }

    // {
    //     intset temp(int_arr, int_arr + int_size);

    //     temp.insert(34);
    //     temp.insert(3468);
    //     temp.insert(96533);
    //     temp.insert(1954894589);
    //     temp.insert(7754322);
    //     temp.insert(3632);
    //     temp.insert(3);
    //     temp.insert(4);
    //     temp.insert(-873487);
    //     temp.insert(-95763433);
    //     temp.insert(453834782);
    //     temp.insert(19458942);
    //     temp.insert(1245689793);

    //     const intset m(temp);

    //     intset::const_iterator b = m.lower_bound(98583944);

    //     PRINT_BOUND(b, m.end());

    //     b = m.lower_bound(209485948);

    //     PRINT_BOUND(b, m.end());

    //     b = m.lower_bound(19458942);

    //     PRINT_BOUND(b, m.end());

    //     b = m.lower_bound(19458941);

    //     PRINT_BOUND(b, m.end());

    //     b = m.lower_bound(19458943);

    //     PRINT_BOUND(b, m.end());

    //     b = m.lower_bound(-1);

    //     PRINT_BOUND(b, m.end());

    //     b = m.lower_bound(3);

    //     PRINT_BOUND(b, m.end());

    //     b = m.lower_bound(4);

    //     PRINT_BOUND(b, m.end());

    //     b = m.lower_bound(5);

    //     PRINT_BOUND(b, m.end());

    //     b = m.lower_bound(0);

    //     PRINT_BOUND(b, m.end());

    //     b = m.lower_bound(std::numeric_limits<int>::max());

    //     PRINT_BOUND(b, m.end());
    // }

    // {
    //     const intset m;

    //     intset::const_iterator b = m.lower_bound(5);

    //     PRINT_BOUND(b, m.end());
    // }


	// // ################################  CONSTRUCTORS  ##############
    // {
    //     NS::set<int> first;                           // empty set of ints
    //     display(first);

    //     int myints[]= {10,20,30,40,50};
    //     NS::set<int> second (myints,myints+5);        // range
    //     display(second);

    //     NS::set<int> third (second);                  // a copy of second
    //     display(third);

    //     NS::set<int> fourth (second.begin(), second.end());  // iterator ctor.
    //     display(fourth);

    //     NS::set<int,classcomp> fifth;                 // class as Compare
    //     display(fifth);

    //     bool(*fn_pt)(int,int) = fncomp;
    //     NS::set<int,bool(*)(int,int)> sixth (fn_pt);  // function pointer as Compare
    //     display(sixth);
    // }
}