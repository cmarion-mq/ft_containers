#ifndef RBT_NODE_HPP
# define RBT_NODE_HPP

#include <iostream>
#include "pair.hpp"

namespace ft {
	enum color {BLACK, RED};
	
	template <class T, class Allocator = std::allocator<T> >
	struct Node {
		typedef	typename T::first_type	key;

		T	    		_pair;
		key				_key;
		Allocator		_alloc;
		color			_color;
		Node			*_parent;
		Node			*_left;
		Node			*_right;
	
		Node(const Allocator &alloc = Allocator()): _pair(T()), _key(key()), _alloc(alloc), _color(BLACK), _parent(NULL), _left(NULL), _right(NULL)
		{};

		Node(T pair, color color, Node *parent, Node *left, Node *right, const Allocator &alloc = Allocator()): _key(pair.first), _alloc(alloc), _color(color), _parent(parent), _left(left), _right(right) {
			_alloc.construct(&_pair, pair);
		};
	};
}

#endif