#include <iostream>
#include <string>
#include <stdlib.h>
#include <stack>
#include <vector>
#include "stack.hpp"

#ifndef NS
# define NS ft
#endif

template <typename T>
static void display(NS::stack<T, NS::vector<T> > stack) {
	std::cout << "size: " << stack.size() << std::endl;
	std::cout << "empty: " << stack.empty() << std::endl;
	if (!stack.empty())
		std::cout << "top: " << stack.top() << std::endl;
	std::cout << std::endl;
}

int main() {
	// ################################  CONSTRUCTORS  ##############
	std::cout << "\e[7m=============CONSTRUCTORS============\e[0m" << std::endl;
	{
		NS::vector<int> f_vector(3,100);
		NS::vector<int> s_vector(2,200);	
		NS::stack<int, NS::vector<int> > first;
		NS::stack<int, NS::vector<int> > second(f_vector);
		NS::stack<int, NS::vector<int> > third;
		NS::stack<int, NS::vector<int> > fourth(s_vector);	
		display(first);
		display(second);
		display(third);
		display(fourth);
	}
		std::cout << std::endl;
	// ################################  CAPACITY  ###############
	std::cout << "\e[7m=============CAPACITY============\e[0m" << std::endl;
	std::cout << "\033[31m***Empty***\033[0m" << std::endl;
	{
		NS::stack<int, NS::vector<int> > mystack;

		for (int i=1; i <= 10; i++)
			mystack.push(i);
		display(mystack);
		while (!mystack.empty())
			mystack.pop();
		display(mystack);	
	}
	std::cout << "\033[31m***Size***\033[0m" << std::endl;
	{
		NS::stack<int, NS::vector<int> > myints;
		display(myints);

		for (int i=0; i<5; i++)
			myints.push(i);
		display(myints);
		myints.pop();
		display(myints);
	}
	std::cout << std::endl;
	// ################################  ELEMENT ACCESS  ###############
	std::cout << "\e[7m=============ELEMENT ACCESS============\e[0m" << std::endl;
	std::cout << "\033[31m***Top***\033[0m" << std::endl;
	{
		NS::stack<int, NS::vector<int> > mystack;
		mystack.push(10);
		mystack.push(20);
		mystack.top() -= 5;
		display(mystack);
	}
	std::cout << std::endl;
	// ################################  MODIFIERS  ###############
	std::cout << "\e[7m=============MODIFIERS============\e[0m" << std::endl;
	std::cout << "\033[31m***Push***\033[0m" << std::endl;
	{
		NS::stack<int, NS::vector<int> > mystack;

		for (int i=0; i<5; ++i)
			mystack.push(i);

		std::cout << "Popping out elements...";
		while (!mystack.empty()) {
			std::cout << ' ' << mystack.top();
			mystack.pop();
		}
		display(mystack);
		std::cout << std::endl;
	}
	std::cout << "\033[31m***Pop***\033[0m" << std::endl;
	{
		NS::stack<int> mystack;
		for (int i=0; i<5; ++i)
			mystack.push(i);

		std::cout << "Popping out elements...";
		while (!mystack.empty()) {
			std::cout << ' ' << mystack.top();
			mystack.pop();
		}
		std::cout << std::endl;
	}
	return (0);
}