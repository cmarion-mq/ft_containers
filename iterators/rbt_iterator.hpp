#ifndef RBT_ITERATOR
# define RBT_ITERATOR

#include "../utils/RBT_node.hpp"

// template< class T >
// ft::Node<T> *rbt_nextt(ft::Node<T> *from) {

// };


namespace ft {
	template< class T >
	class RBT_iterator {
		public:
	/*-------- TYPES ---------*/


	/*--- CON/DE_STRUCTORS ---*/
		RBT_iterator(): _current(NULL) {};

		RBT_iterator(Node<T> *current): _current(current) {};

		private:
		/*-------- TYPES ---------*/
			typedef Node<T>*	nodePtr;
			
		/*--- MEMBER OBJECTS ---*/
			nodePtr	_current;
			
			/*nodePtr rbt_previous(nodePtr *from) {
				if (from->is_leaf()) {
					if (from->_parent)
						return (from->_parent);
					return (from);
				}
				if (!from->_left->is_leaf()) {
					from = from->_left;
					while (!from->_right->is_leaf())
						from = from->_right
					return (from);
				}
				else {
					nodePtr init = from;
					while (from->_parent && !from->_parent->is_leaf() && from == from->_parent->_left)
						from = from->_parent;
					if (from->_parent == NULL)
						return (init->_left);
					return (from->_parent);
				}
			};*/

			RBT_iterator &operator --() {
				if (_current->is_leaf()) {
					if (_current->_parent) {
						_current = _current->_parent;
						return (*this);
					}
					return (*this);
				}
				if (!_current->_left->is_leaf()) {
					_current = _current->_left;
					while (!_curent->_right->is_leaf())
						_current = _current->_right
					return (*this);
				}
				else {
					nodePtr init = _current;
					while (_current->_parent && !_current->_parent->is_leaf() && _current == _current->_parent->_left)
						_current = _current->_parent;
					if (_current->_parent == NULL) {
						_current = init->_left;
						return (*this);
					}
					_current = _current->_parent
					return (*this);
				}
			};
    };
}
#endif