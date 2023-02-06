#ifndef RBT_ITERATOR
# define RBT_ITERATOR

#include "../utils/RBT_node.hpp"

template< class T >
ft::Node<T> *rbt_nextt(Node<T> *from) {

};

template< class T >
ft::Node<T> *rbt_previous(Node<T> *from) {
	
};

namespace ft {
	template< class T >
	class RBT_iterator {
		public:
	/*-------- TYPES ---------*/
			typedef T*  iterator;

	/*--- CON/DE_STRUCTORS ---*/
		rbt_iterator(): _current(NULL) {};
		
		private:
			iterator	_current;
    };
}
#endif