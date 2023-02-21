#ifndef RBT_ITERATOR
# define RBT_ITERATOR

#include "../utils/RBT_node.hpp"

template< class T >
ft::Node<T> *rbt_nextt(ft::Node<T> *from) {

};

template< class T >
ft::Node<T> *rbt_previous(ft::Node<T> *from) {
	
};

namespace ft {
	template< class T >
	class RBT_iterator {
		public:
	/*-------- TYPES ---------*/
			typedef T*  iterator;

	/*--- CON/DE_STRUCTORS ---*/
		RBT_iterator(): _current(NULL) {};
		
		private:
			iterator	_current;
    };
}
#endif