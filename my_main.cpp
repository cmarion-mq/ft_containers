#include <iostream>
#include <string>
#include <vector>
#include "vector.hpp"
#include <stdlib.h>

int main() {

	// ft::vector<std::string> vector_str;
	ft::vector<int> vector_int(4, 100);
	ft::vector<int> cpy_int(&vector_int);

	// for (int i = 0; i < 10; i++) {
	// 	vector_buffer.push_back(Buffer());
	// }

	// for (int i = 0; i < COUNT; i++) {
	// 	const int idx = rand() % COUNT;
	// 	vector_buffer[idx].idx = 5;
	// }
	std::cout << vector_int[0] << std::endl;
	for (size_t i = 0; i < 4; i ++)
		std::cout << vector_int[i] << std::endl;
	return (0);
}