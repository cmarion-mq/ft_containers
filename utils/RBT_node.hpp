#ifndef RBT_NODE_HPP
# define RBT_NODE_HPP

#include <iostream>
#include "pair.hpp"

namespace ft {
	enum color {BLACK, RED};
	
	template <class T >
	struct Node {
		typedef	typename T::first_type	key;

		T	    		_pair;
		key				_key;
		color			_color;
		Node			*_parent;
		Node			*_left;
		Node			*_right;
	
		Node(): _pair(T()), _key(key()), _color(BLACK), _parent(NULL), _left(NULL), _right(NULL)
		{};

		Node(T pair, color color, Node *parent, Node *left, Node *right): _pair(pair), _key(pair.first), _color(color), _parent(parent), _left(left), _right(right)
		{};

		bool is_leaf() {
			return (!_left && !_right)
		}
	};
}

#endif