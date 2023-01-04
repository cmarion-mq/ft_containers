#include <vector>
#include <iostream>

int main() {
// ###############  CONSTRUCTORS  ###############
	std::vector<int> second (4,100);       
                  // four ints with value 10

	std::cout << "The contents of SECOND are:";
	for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

// ###############  CAPACITY  ###############

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
