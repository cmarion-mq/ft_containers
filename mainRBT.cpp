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
	ft::Node<int> *one = bst.insert(55);
	ft::Node<int> *two = bst.insert(40);
	ft::Node<int> *three = bst.insert(65);
	ft::Node<int> *thour = bst.insert(60);
	ft::Node<int> *five = bst.insert(75);
	ft::Node<int> *six = bst.insert(57);
std::cout << "after 57" << std::endl;
	ft::Node<int> *seven = bst.insert(56);

	print_node(one);
	print_node(two);
	print_node(three);
	print_node(thour);
	print_node(five);
	print_node(six);
	print_node(seven);
	bst.printTree();
}