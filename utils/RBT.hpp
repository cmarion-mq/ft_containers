#ifndef RBT_HPP
# define RBT_HPP

#include <iostream>
#include "RBT_node.hpp"
#include "iterators/rbt_iterator.hpp"
#include "iterators/reverse_iterator.hpp"

namespace ft {
	template < class T, class Compare, class Allocator = std::allocator<T> >
	class RBT
	{
		typedef typename Allocator::template rebind<Node<T> >::other node_allocator;
		typedef Compare												key_compare;
		typedef	typename T::first_type								key_type;
		typedef	typename T::second_type								value_type;
		typedef Node<T> 											node;
		typedef Node<T> *											nodePtr;
		typedef RBT_iterator<T, value_type>							iterator;
		typedef RBT_iterator<T, const value_type>					const_iterator;
		typedef ft::reverse_iterator<iterator>						reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;

/* ####################   PUBLIC  #################### */
		public :
		/*--- CON/DE_STRUCTORS ---*/
			RBT(const key_compare& comp = key_compare(), const Allocator &alloc = Allocator()): _alloc(alloc), _comp(comp), _size(0) {
				_leaf = _node_alloc.allocate(1);
				_maxleaf = _node_alloc.allocate(1);
				_minleaf = _node_alloc.allocate(1);
				_root = _leaf;
				_root->_color = BLACK;
				// _root->_parent = _leaf;
				// _root->_left = _leaf;
				// _root->_right = _leaf;
				_leaf->_parent = NULL;
				_leaf->_left = NULL;
				_leaf->_right = NULL;
				_maxleaf->_parent = _root;
				_maxleaf->_left = NULL;
				_maxleaf->_right = NULL;	
				_minleaf->_parent = _root;
				_minleaf->_left = NULL;
				_minleaf->_right = NULL;
			};

			~RBT() {
				if (_size > 0)
					clear();
				delete _leaf;
				delete _maxleaf;
				delete _minleaf;
			};
	
		/*---      INSERT      ---*/
			iterator	insert(T new_element) {
				nodePtr	temp = _root;
				key_type		new_key = new_element.first;
				_size ++;
				while (!is_leaf(temp)) {
					if (!is_leaf(temp->_right) && !_comp(new_key, temp->_key))
						temp = temp->_right;
					else if (!is_leaf(temp->_left) && _comp(new_key, temp->_key))
						temp = temp->_left;
					else
						break;
				}
				nodePtr new_node = _node_alloc.allocate(_size + 1);
				_node_alloc.construct(new_node, node(new_element, RED, temp, _leaf, _leaf));
				if (temp == _leaf) { 
					_root = new_node;
					new_node->_color = BLACK;
					return(iterator(new_node));
				}
				if (!_comp(new_node->_key, temp->_key))
					temp->_right = new_node;
				else
					temp->_left = new_node;
				new_node->_parent = temp;
				insert_balancing(new_node);
				min_max_actu();
				return (iterator(new_node));
			};

		/*---      DELETE      ---*/
			bool	del(key_type del_key) {
				nodePtr	del_node = find_node(del_key);
				if (del_node == NULL)
					return (false);
				color	del_color = del_node->_color;
				nodePtr x;
				if (is_leaf(del_node->_left)) {
					x = del_node->_right;
					replace(del_node, del_node->_right);
				}
				else if (is_leaf(del_node)) {
					x = del_node->_left;
					replace(del_node, del_node->_left);
				}
				else {
					nodePtr y = min(del_node->_right);
					del_color = y->_color;
					x = y->_right;
					if (y->_parent == del_node) {
						x->_parent = y;
					}
					else {
						replace(y, y->_right);
						y->_right = del_node->_right;
						y->_right->_parent = y;
					}
					replace(del_node, y);
					y->_left = del_node->_left;
					y->_left->_parent = y;
					y->_color = del_node->_color;
				}
				_node_alloc.deallocate(del_node, 1);
				if (del_color == BLACK) 
					del_balancing(x);
				_size --;
				min_max_actu();
				return (true);
			};

		/*---      CLEAR       ---*/
			void clear() {
				nodePtr	temp = _root;
				while (!is_leaf(temp)) {
					if (!is_leaf(temp->_right))
						temp = temp->_right;
					else if (!is_leaf(temp->_left)) 
						temp = temp->_left;
					else {
						nodePtr del = temp;
						if (temp->_parent->_left == temp)
							temp->_parent->_left = _leaf;
						else
							temp->_parent->_right = _leaf;
						temp = temp->_parent;
						_node_alloc.destroy(del);
						_node_alloc.deallocate(del, 1);
					}
				}
				_size = 0;
			};

		/*---      FIND      ---*/
			nodePtr	find_node(key_type key) const {
				nodePtr	temp = _root;
				while (!temp->is_leaf()) {
					if (temp->_key == key)
						return (temp);
					if (!_comp(key, temp->_key))
						temp = temp->_right;
					else
						temp = temp->_left;
				}
				return (NULL);
			};

			iterator	find_node_i(const key_type key) {
				nodePtr	temp = _root;
				while (!temp->is_leaf()) {
					if (temp->_key == key)
						return (iterator(temp));
					if (!_comp(key, temp->_key))
						temp = temp->_right;
					else
						temp = temp->_left;
				}
				return (end());
			};

			const_iterator	find_node_i(const key_type key) const {
				nodePtr	temp = _root;
				while (!temp->is_leaf()) {
					if (temp->_key == key)
						return (const_iterator(temp));
					if (!_comp(key, temp->_key))
						temp = temp->_right;
					else
						temp = temp->_left;
				}
				return (end());
			};
			
		/*---    ITERATORS     ---*/
			iterator				begin() 			{ return ( iterator(_minleaf->_parent)); };
			const_iterator			begin()		const	{ return ( const_iterator(_minleaf->_parent)); };
			reverse_iterator		rbegin()			{ return ( reverse_iterator(end())); };
			const_reverse_iterator	rbegin() 	const	{ return ( const_reverse_iterator(end())); };
			iterator				end()				{ return ( iterator(_maxleaf)); };
			const_iterator			end()		const	{ return ( const_iterator(_maxleaf)); };
			reverse_iterator 		rend()				{ return ( reverse_iterator(begin())); };
			const_reverse_iterator 	rend()		const	{ return ( const_reverse_iterator(begin())); };

		/*---      DIVERS      ---*/
			void printTree() {
    			if (_size > 0)
      				printHelper(_root, "", true);
			};

			size_t	size() const		{ return (_size); };
			size_t	max_size() const	{ return (_alloc.max_size()); };

/* ####################   PRIVATE   #################### */

		private:
			Allocator		_alloc;
			node_allocator	_node_alloc;
			nodePtr 		_root;
			nodePtr 		_leaf;
			nodePtr 		_minleaf;
			nodePtr 		_maxleaf;
			key_compare		_comp;
			size_t			_size;		

		/*--- INSERT HELPERS ---*/
			void	insert_balancing(nodePtr node){
				while (node->_parent->_color == RED) {
					if (node->_parent == node->_parent->_parent->_left) {
						if (node->_parent->_parent->_right->_color == RED) {
							node->_parent->_parent->_right->_color = BLACK;
							node->_parent->_color = BLACK;
							node->_parent->_parent->_color = RED;
							node = node->_parent->_parent;
						}
						else {
							if (node == node->_parent->_right) {
								node = node->_parent;
								left_rotate(node);
							}
							node->_parent->_color = BLACK;
							node->_parent->_parent->_color = RED;
							right_rotate(node->_parent->_parent);
						}
					}
					else {
						if (node->_parent->_parent->_left->_color == RED) {
							node->_parent->_parent->_left->_color = BLACK;
							node->_parent->_color = BLACK;
							node->_parent->_parent->_color = RED;
							node = node->_parent->_parent;
						}
						else {
							if (node == node->_parent->_left) {
								node = node->_parent;
								right_rotate(node);
							}
							node->_parent->_color = BLACK;
							node->_parent->_parent->_color = RED;
							left_rotate(node->_parent->_parent);
						}
					}
					if (node == _root)
						break;
				}
				_root->_color = BLACK;
			};

		/*--- DELETE HELPERS ---*/

			void	replace(nodePtr x, nodePtr y) {
				if (is_leaf(x->_parent))
					_root = y;
				else if (x == x->_parent->_left)
					x->_parent->_left = y;
				else
					x->_parent->_right = y;
				y->_parent = x->_parent;
			}

			void	del_balancing(nodePtr node){
				nodePtr temp;

				while (node != _root && (node->_color == BLACK || is_leaf(node))) {
					if (node == node->_parent->_left) {
						temp = node->_parent->_right;
						if (temp->_color == RED) {
							temp->_color = BLACK;
							node->_parent->_color = RED;
							left_rotate(node->_parent);
							temp = node->_parent->_right;
						}
						if (temp->_right->_color == BLACK && temp->_left->_color == BLACK) {
							temp->_color = RED;
							node = node->_parent;
						}
						else {
							if (temp->_right->_color == BLACK) {
								temp->_left->_color = BLACK;
								temp->_color = RED;
								right_rotate(temp);
								temp = node->_parent->_right;
							}
							temp->_color = node->_parent->_color;
							node->_parent->_color = BLACK;
							temp->_right->_color = BLACK;
							left_rotate(node->_parent);
							node = _root;
						}
					}
					else {
						temp = node->_parent->_left;
						if (temp->_color == RED) {
							temp->_color = BLACK;
							node->_parent->_color = RED;
							right_rotate(node->_parent);
							temp = node->_parent->_left;
						}
						if (temp->_right->_color == BLACK && temp->_left->_color == BLACK) {
							temp->_color = RED;
							node = node->_parent;
						}
						else {
							if (temp->_left->_color == BLACK) {
								temp->_right->_color = BLACK;
								temp->_color = RED;
								left_rotate(temp);
								temp = node->_parent->_left;
							}
							temp->_color = node->_parent->_color;
							node->_parent->_color = BLACK;
							temp->_left->_color = BLACK;
							right_rotate(node->_parent);
							node = _root;
						}
					}
				}
				node->_color = BLACK;
			}

		/*--- OTHER HELPERS ---*/
			void	left_rotate(nodePtr x){
				nodePtr	y = x->_right;
				x->_right = y->_left;
				if (!is_leaf(y->_left))
					y->_left->_parent = x;
				y->_parent = x->_parent;
				if (is_leaf(x->_parent))
					_root = y;
				else if (x == x->_parent->_left)
					x->_parent->_left = y;
				else
					x->_parent->_right = y;
				y->_left = x;
				x->_parent = y;
			};

			void	right_rotate(nodePtr x){
				nodePtr	y = x->_left;
				x->_left = y->_right;
				if (!is_leaf(y->_right))
					y->_right->_parent = x;
				y->_parent = x->_parent;
				if (is_leaf(x->_parent))
					_root = y;
				else if (x == x->_parent->_right)
					x->_parent->_right = y;
				else
					x->_parent->_left = y;
				y->_right = x;
				x->_parent = y;
			};

			nodePtr	min(nodePtr node) {
				if (!node || is_leaf(node))
					return(node);
				while (!is_leaf(node->_left))
					node = node->_left;
				return (node);
			};

			nodePtr	max(nodePtr node) {
				if (!node || is_leaf(node))
					return(node);
				while (!is_leaf(node->_right))
					node = node->_right;
				return (node);
			};

			void	min_max_actu() {
				nodePtr minp = min(_root);
				nodePtr maxp = max(_root);
				if (_minleaf->_parent && _minleaf->_parent->_left == _minleaf)
					_minleaf->_parent->_left = _leaf;
				_minleaf->_parent = minp;
				minp->_left = _minleaf;
				if (_maxleaf && _maxleaf->_parent && _maxleaf->_parent->_right == _maxleaf)
					_maxleaf->_parent->_right = _leaf;
				_maxleaf->_parent = maxp;
				maxp->_right = _maxleaf;
			}

			bool	is_leaf(nodePtr node) {
				return(node == _leaf || node == _minleaf || node == _maxleaf);
			}

		/*--- PRINT HELPER ---*/
			void printHelper(nodePtr node, std::string indent, bool last) {
				if (!is_leaf(node)) {
					std::cout << indent;
					if (last) {
						std::cout << "R----";
						indent += "   ";
					} 
					else {
						std::cout << "L----";
						indent += "|  ";
					}
					std::string sColor = node->_color ? "RED" : "BLACK";
					std::cout << node->_key << "(" << sColor << ")" << std::endl;
					printHelper(node->_left, indent, false);
					printHelper(node->_right, indent, true);
				};
			}
	};


/*	void initializeNULLNode(NodePtr node, NodePtr parent) {
		node->data = 0;
		node->parent = parent;
		node->left = nullptr;
		node->right = nullptr;
		node->color = 0;
	}

	// Preorder
	void preOrderHelper(NodePtr node) {
		if (node != TNULL) {
		cout << node->data << " ";
		preOrderHelper(node->left);
		preOrderHelper(node->right);
		}
	}

	// Inorder
	void inOrderHelper(NodePtr node) {
		if (node != TNULL) {
		inOrderHelper(node->left);
		cout << node->data << " ";
		inOrderHelper(node->right);
		}
	}

	// Post order
	void postOrderHelper(NodePtr node) {
		if (node != TNULL) {
		postOrderHelper(node->left);
		postOrderHelper(node->right);
		cout << node->data << " ";
		}
	}

	NodePtr searchTreeHelper(NodePtr node, int key) {
		if (node == TNULL || key == node->data) {
		return node;
		}

		if (key < node->data) {
		return searchTreeHelper(node->left, key);
		}
		return searchTreeHelper(node->right, key);
	}

	public:
	RedBlackTree() {
		TNULL = new Node;
		TNULL->color = 0;
		TNULL->left = nullptr;
		TNULL->right = nullptr;
		root = TNULL;
	}

	void preorder() {
		preOrderHelper(this->root);
	}

	void inorder() {
		inOrderHelper(this->root);
	}

	void postorder() {
		postOrderHelper(this->root);
	}

	NodePtr searchTree(int k) {
		return searchTreeHelper(this->root, k);
	}

	NodePtr successor(NodePtr x) {
		if (x->right != TNULL) {
		return minimum(x->right);
		}

		NodePtr y = x->parent;
		while (y != TNULL && x == y->right) {
		x = y;
		y = y->parent;
		}
		return y;
	}

	NodePtr predecessor(NodePtr x) {
		if (x->left != TNULL) {
		return maximum(x->left);
		}

		NodePtr y = x->parent;
		while (y != TNULL && x == y->left) {
		x = y;
		y = y->parent;
		}

		return y;
	}


	NodePtr getRoot() {
		return this->root;
	}

	void deleteNode(int data) {
		deleteNodeHelper(this->root, data);
	}*/
}

#endif