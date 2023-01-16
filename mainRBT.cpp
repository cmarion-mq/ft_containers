#include <iostream>
#include <string>
#include <stdlib.h>
#include "utils/RBT.hpp"

template < class T>
void print_node(ft::Node<T> *node) {
	std::cout << std::endl << "key: " << node->_key << std::endl;
	std::cout << std::endl << "color: " << node->_color << std::endl;
	std::cout << "parent: " << node->_parent->_key << std::endl;
	std::cout << "left: " << node->_left->_key << std::endl;
	std::cout << "right: " << node->_right->_key << std::endl;
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