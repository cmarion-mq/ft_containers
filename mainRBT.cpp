#include <iostream>
#include <string>
#include <stdlib.h>
#include "utils/RBT.hpp"

template < class T>
void print_node(ft::Node<T> *node) {
	std::cout << "*************NODE: " << node->_key << std::endl;
	std::cout << std::endl << "adress: " << node << std::endl;
	std::cout << "color: " << node->_color << std::endl;
	std::cout << std::endl << "parent adsress: " << node->_parent << std::endl;
	std::cout << "parent key: " << node->_parent->_key << std::endl;
	std::cout << std::endl << "left address: " << node->_left << std::endl;
	std::cout << "left key: " << node->_left->_key << std::endl;
	std::cout << std::endl << "right adsress: " << node->_right << std::endl;
	std::cout << "right key: " << node->_right->_key << std::endl << std::endl;
}

int main() {
	ft::RBT<int, std::less<int>> bst;
	bst.insert(55);
	bst.insert(40);
	bst.insert(65);
	bst.insert(60);
	bst.insert(75);
	bst.insert(57);
	bst.insert(56);

	bst.del(57);
	bst.printTree();
}