#ifndef RBT_NODE_HPP
# define RBT_NODE_HPP

#include <iostream>
#include "pair.hpp"

namespace ft {
	enum color {BLACK, RED};
	
	template <class ValueType >
	struct Node {
		ValueType  		_value;
		color			_color;
		Node			*_parent;
		Node			*_left;
		Node			*_right;
	
		Node(): _value(ValueType()), _color(BLACK), _parent(NULL), _left(NULL), _right(NULL)
		{};

		Node(ValueType pair, color color, Node *parent, Node *left, Node *right): _value(pair), _color(color), _parent(parent), _left(left), _right(right)
		{};

		bool is_leaf() const {
			return (!_left && !_right);
		};
	};
}

#endif