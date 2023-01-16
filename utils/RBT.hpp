#ifndef RBT_HPP
# define RBT_HPP

#include <iostream>
#include "RBT_node.hpp"

namespace ft {
	template < class T, class Compare, class Allocator = std::allocator<T> >
	class RBT
	{
		typedef Compare		comp;
		typedef Node<T> 	node;
		typedef Node<T> *	nodePtr;

		public :
/*--- CON/DE_STRUCTORS ---*/
			RBT(const Allocator &alloc = Allocator()): _alloc(alloc) {
				_leaf = new node();
				_root = _leaf;
			};

			~RBT() {};
	
/*--- INSERT ---*/
			nodePtr	insert(T new_key) {
				nodePtr	temp = _root;
				while (temp != _leaf) {
					if (temp->_right == _leaf || temp->_left == _leaf)
						break;
					if (new_key > temp->_key)
						temp = temp->_right;
					else
						temp = temp->_left;
				}
				nodePtr new_node = new node(new_key, RED, temp, _leaf, _leaf);
				if (temp == _leaf) 
					_root = new_node;
				else if (new_key > temp->_key)
					temp->_right = new_node;
				else
					temp->_left = new_node;
				if (new_node->_parent == _leaf)
					new_node->_color = BLACK;
				insert_balancing(new_node);
				return (new_node);
			}

			void printTree() {
    			if (_root != _leaf)
      				printHelper(_root, "", true);
			}

		private:
			Allocator	_alloc;
			nodePtr 	_root;
			nodePtr 	_leaf;
			comp		_comp;

			void	insert_balancing(nodePtr node){
	// std::cout << "out while" << node->_key << std::endl;
				while (node->_parent->_color == RED) {
					if (node->_parent == node->_parent->_parent->_left) {
	// std::cout << "node->_parent->_parent->_left" << std::endl;
						if (node->_parent->_parent->_right->_color == RED) {
	// std::cout << "node->_parent->_parent->_right" << std::endl;
							node->_parent->_parent->_right->_color = BLACK;
							node->_parent->_parent->_left->_color = BLACK;
							node->_parent->_parent->_color = RED;
							node = node->_parent->_parent;
						}
						else if (node == node->_parent->_right) {
							node = node->_parent;
	// std::cout << "node = node->_parent;" << std::endl;
							left_rotate(node);
						}
						else {
							node->_parent->_color = BLACK;
							node->_parent->_parent->_color = RED;
							right_rotate(node);
						}
					}
					else {
	// std::cout << "node->_parent->_parent->_right" << std::endl;
						if (node->_parent->_parent->_left->_color == RED) {
	// std::cout << "node->_parent->_parent->_right / in if" << std::endl;
							node->_parent->_color = BLACK;
							node->_parent->_parent->_left->_color = BLACK;
							node->_parent->_parent->_color = RED;
							node = node->_parent->_parent;
						}
						else {
							if (node == node->_parent->_left) {
	// std::cout << "node->_parent->_parent->_right / in else if" << std::endl;
								node = node->_parent;
								right_rotate(node);
							}
							node->_parent->_color = BLACK;
							node->_parent->_parent->_color = RED;
	// std::cout << "node->_parent->_parent->_right / before left_rotate" << std::endl;
							left_rotate(node->_parent->_parent);
						}
					}
	// std::cout << "just bore break" << std::endl;
					if (node == _root)
						break;
				}
				_root->_color = BLACK;
			}

			void	left_rotate(nodePtr x){
				nodePtr	y = x->_right;
				x->_right = y->_left;
				if (y->_left != _leaf)
					y->_left->_parent = x;
				y->_parent = x->_parent;
				if (y->_parent == _leaf)
					_root = y;
				else if (x == x->_parent->_left)
					x->_parent->_left = y;
				else
					x->_parent->_right = y;
				y->_left = x;
				x->_parent = y;
			}

			void	right_rotate(nodePtr y){
				nodePtr	x = y->_right;
				y->_right = x->_left;
				if (x->_right != _leaf)
					x->_right->_parent = x;
				y->_parent = x->_parent;
				if (y->_parent == _leaf)
					_root = y;
				else if (y == y->_parent->_right)
					y->_parent->_right = x;
				else
					y->_parent->_left = x;
				x->_right = y;
				y->_parent = x;
			}

		void printHelper(nodePtr root, std::string indent, bool last) {
			if (_root != _leaf) {
			std::cout << indent;
			if (last) {
				std::cout << "R----";
				indent += "   ";
			} else {
				std::cout << "L----";
				indent += "|  ";
			}

			std::string sColor = _root->_color ? "RED" : "BLACK";
			std::cout << _root->_key << "(" << sColor << ")" << std::endl;
			printHelper(_root->_left, indent, false);
			printHelper(_root->_right, indent, true);
			}
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

	// For balancing the tree after deletion
	void deleteFix(NodePtr x) {
		NodePtr s;
		while (x != root && x->color == 0) {
		if (x == x->parent->left) {
			s = x->parent->right;
			if (s->color == 1) {
			s->color = 0;
			x->parent->color = 1;
			leftRotate(x->parent);
			s = x->parent->right;
			}

			if (s->left->color == 0 && s->right->color == 0) {
			s->color = 1;
			x = x->parent;
			} else {
			if (s->right->color == 0) {
				s->left->color = 0;
				s->color = 1;
				rightRotate(s);
				s = x->parent->right;
			}

			s->color = x->parent->color;
			x->parent->color = 0;
			s->right->color = 0;
			leftRotate(x->parent);
			x = root;
			}
		} else {
			s = x->parent->left;
			if (s->color == 1) {
			s->color = 0;
			x->parent->color = 1;
			rightRotate(x->parent);
			s = x->parent->left;
			}

			if (s->right->color == 0 && s->right->color == 0) {
			s->color = 1;
			x = x->parent;
			} else {
			if (s->left->color == 0) {
				s->right->color = 0;
				s->color = 1;
				leftRotate(s);
				s = x->parent->left;
			}

			s->color = x->parent->color;
			x->parent->color = 0;
			s->left->color = 0;
			rightRotate(x->parent);
			x = root;
			}
		}
		}
		x->color = 0;
	}

	void rbTransplant(NodePtr u, NodePtr v) {
		if (u->parent == nullptr) {
		root = v;
		} else if (u == u->parent->left) {
		u->parent->left = v;
		} else {
		u->parent->right = v;
		}
		v->parent = u->parent;
	}

	void deleteNodeHelper(NodePtr node, int key) {
		NodePtr z = TNULL;
		NodePtr x, y;
		while (node != TNULL) {
		if (node->data == key) {
			z = node;
		}

		if (node->data <= key) {
			node = node->right;
		} else {
			node = node->left;
		}
		}

		if (z == TNULL) {
		cout << "Key not found in the tree" << endl;
		return;
		}

		y = z;
		int y_original_color = y->color;
		if (z->left == TNULL) {
		x = z->right;
		rbTransplant(z, z->right);
		} else if (z->right == TNULL) {
		x = z->left;
		rbTransplant(z, z->left);
		} else {
		y = minimum(z->right);
		y_original_color = y->color;
		x = y->right;
		if (y->parent == z) {
			x->parent = y;
		} else {
			rbTransplant(y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}

		rbTransplant(z, y);
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
		}
		delete z;
		if (y_original_color == 0) {
		deleteFix(x);
		}
	}

	// For balancing the tree after insertion
	void insertFix(NodePtr k) {
		NodePtr u;
		while (k->parent->color == 1) {
		if (k->parent == k->parent->parent->right) {
			u = k->parent->parent->left;
			if (u->color == 1) {
			u->color = 0;
			k->parent->color = 0;
			k->parent->parent->color = 1;
			k = k->parent->parent;
			} else {
			if (k == k->parent->left) {
				k = k->parent;
				rightRotate(k);
			}
			k->parent->color = 0;
			k->parent->parent->color = 1;
			leftRotate(k->parent->parent);
			}
		} else {
			u = k->parent->parent->right;

			if (u->color == 1) {
			u->color = 0;
			k->parent->color = 0;
			k->parent->parent->color = 1;
			k = k->parent->parent;
			} else {
			if (k == k->parent->right) {
				k = k->parent;
				leftRotate(k);
			}
			k->parent->color = 0;
			k->parent->parent->color = 1;
			rightRotate(k->parent->parent);
			}
		}
		if (k == root) {
			break;
		}
		}
		root->color = 0;
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

	NodePtr minimum(NodePtr node) {
		while (node->left != TNULL) {
		node = node->left;
		}
		return node;
	}

	NodePtr maximum(NodePtr node) {
		while (node->right != TNULL) {
		node = node->right;
		}
		return node;
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

	void leftRotate(NodePtr x) {
		NodePtr y = x->right;
		x->right = y->left;
		if (y->left != TNULL) {
		y->left->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == nullptr) {
		this->root = y;
		} else if (x == x->parent->left) {
		x->parent->left = y;
		} else {
		x->parent->right = y;
		}
		y->left = x;
		x->parent = y;
	}

	void rightRotate(NodePtr x) {
		NodePtr y = x->left;
		x->left = y->right;
		if (y->right != TNULL) {
		y->right->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == nullptr) {
		this->root = y;
		} else if (x == x->parent->right) {
		x->parent->right = y;
		} else {
		x->parent->left = y;
		}
		y->right = x;
		x->parent = y;
	}

	// Inserting a node
	void insert(int key) {
		NodePtr node = new Node;
		node->parent = nullptr;
		node->data = key;
		node->left = TNULL;
		node->right = TNULL;
		node->color = 1;

		NodePtr y = nullptr;
		NodePtr x = this->root;

		while (x != TNULL) {
		y = x;
		if (node->data < x->data) {
			x = x->left;
		} else {
			x = x->right;
		}
		}

		node->parent = y;
		if (y == nullptr) {
		root = node;
		} else if (node->data < y->data) {
		y->left = node;
		} else {
		y->right = node;
		}

		if (node->parent == nullptr) {
		node->color = 0;
		return;
		}

		if (node->parent->parent == nullptr) {
		return;
		}

		insertFix(node);
	}

	NodePtr getRoot() {
		return this->root;
	}

	void deleteNode(int data) {
		deleteNodeHelper(this->root, data);
	}*/
}

#endif