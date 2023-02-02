#ifndef RBT_ITERATOR
# define RBT_ITERATOR

namespace ft {
	template< class T >
	class rbt_iterator {
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