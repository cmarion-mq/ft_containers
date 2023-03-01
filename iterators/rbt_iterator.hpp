#ifndef RBT_ITERATOR
# define RBT_ITERATOR

#include "../utils/RBT_node.hpp"
#include "iterators/iterators_traits.hpp"

namespace ft {
	template< class ValueType>
	class RBT_iterator;

	template< class ValueType>
	class RBT_const_iterator;
	
/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
*****************************                   ITERATOR BASE                    *****************************
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
	template< class ValueType>
	class RBT_itBase {
/* ####################   PUBLIC  #################### */
		public:
	/*-------- TYPES ---------*/
			typedef Node<ValueType>	node;
			typedef node *			nodePtr;

	/*--- CON/DE_STRUCTORS ---*/
			RBT_itBase(): _current(NULL) {};

			RBT_itBase(nodePtr current): _current(current) {};
								
			RBT_itBase(const RBT_itBase &x) {
				_current = x._current;
			};

			RBT_itBase &operator =(const RBT_itBase<ValueType> &x) {
				if (this == &x) { 
					return *this;
				}
				_current = x._current;
				return (*this);
			}

			~RBT_itBase() {};

			RBT_itBase	&operator	--() {
				if (_current->is_leaf()) {
					if (_current->_parent) {
						_current = _current->_parent;
					}
					return (*this);
				}
				if (!_current->_left->is_leaf()) {
					_current = _current->_left;
					while (!_current->_right->is_leaf())
						_current = _current->_right;
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
					_current = _current->_parent;
					return (*this);
				}
			};

			RBT_itBase	&operator	++() {
				if (_current->is_leaf()) {
					if (_current->_parent) {
						_current = _current->_parent;
					}
					return (*this);
				}
				if (!_current->_right->is_leaf()) {
					_current = _current->_right;
					while (!_current->_left->is_leaf())
						_current = _current->_left;
					return (*this);
				}
				else {
					nodePtr init = _current;
					while (_current->_parent && !_current->_parent->is_leaf() && _current == _current->_parent->_right)
						_current = _current->_parent;
					if (_current->_parent == NULL) {
						_current = init->_right;
						return (*this);
					}
					_current = _current->_parent;
					return (*this);
				}
			};

			const nodePtr getCurrent() const { return (_current);}

			RBT_itBase	operator	++(int) {
				RBT_itBase temp(*this);
				operator ++();
				return (temp);
			}

			RBT_itBase	operator	--(int) {
				RBT_itBase temp(*this);
				operator --();
				return (temp);
			}

			bool		operator ==(const RBT_itBase &other) const {
				return (_current == other._current);
			}

			bool		operator !=(const RBT_itBase &other) const {
				return (_current != other._current);
			}

			ValueType 	&operator	*()		{ return (_current->_pair);		};
			ValueType 	*operator	->()	{ return (&_current->_pair);	};

/* ####################   PRIVATE  #################### */
		private:			
		/*--- MEMBER OBJECTS ---*/
			nodePtr	_current;
    };

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
*****************************                      ITERATOR                      *****************************
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

	template< class ValueType>
	class RBT_iterator {
/* ####################   PUBLIC  #################### */
		public:
	/*-------- TYPES ---------*/
			typedef Node<ValueType>	node;
			typedef node *			nodePtr;

	/*--- CON/DE_STRUCTORS ---*/
			RBT_iterator(): _current(RBT_itBase<ValueType>()) {};

			RBT_iterator(nodePtr current): _current(RBT_itBase<ValueType>(current)) {};

			RBT_iterator(const RBT_iterator &x) {
				_current = x._current;
			};

			RBT_iterator &operator =(const RBT_iterator &x) {
				if (this == &x) { 
					return *this;
				}
				_current = x._current;
				return (*this);
			}

			~RBT_iterator() {};

			RBT_iterator	&operator	--() {
				-- _current;
				return (*this);
			};

			RBT_iterator	&operator	++() {
				++ _current;
				return (*this);
			};

			RBT_iterator	operator	++(int) {
				RBT_iterator temp(*this);
				operator ++();
				return (temp);
			}

			RBT_iterator	operator	--(int) {
				RBT_iterator temp(*this);
				operator --();
				return (*this);
			}

								
			ValueType 		&operator	*()		{ return (*_current);		};
			ValueType 		*operator	->()	{ return (&(*_current));	};

			const RBT_itBase<ValueType>	&base() const {
				return (_current);
			}

/* ####################   PRIVATE  #################### */
		private:			
		/*--- MEMBER OBJECTS ---*/
			RBT_itBase<ValueType>	_current;
	};


/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
*****************************                   CONST ITERATOR                   *****************************
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

	template< class ValueType>
	class RBT_const_iterator {
/* ####################   PUBLIC  #################### */
		public:
	/*-------- TYPES ---------*/
			typedef Node<ValueType>	node;
			typedef node *			nodePtr;

	/*--- CON/DE_STRUCTORS ---*/
			RBT_const_iterator(): _current(NULL) {};

			RBT_const_iterator(nodePtr current): _current(RBT_itBase<ValueType>(current)) {};

			RBT_const_iterator(const RBT_const_iterator &x) {
				_current = x._current;
			};

			RBT_const_iterator &operator =(const RBT_const_iterator &x) {
				if (this == &x) { 
					return *this;
				}
				_current = x._current;
				return (*this);
			}

			~RBT_const_iterator() {};

			RBT_const_iterator	&operator	--() {
				-- _current;
				return (*this);
			};

			RBT_const_iterator	&operator	++() {
				++ _current;
				return (*this);
			};

			RBT_const_iterator	operator	++(int) {
				RBT_const_iterator temp(*this);
				operator ++();
				return (temp);
			}

			RBT_const_iterator	operator	--(int) {
				RBT_const_iterator temp(*this);
				operator --();
				return (*this);
			}

			ValueType 		&operator	*()		{ return (*_current);		};
			ValueType 		*operator	->()	{ return (&(*_current));	};

			const RBT_itBase<ValueType>	&base() const {
				return (_current);
			}

/* ####################   PRIVATE  #################### */
		private:			
		/*--- MEMBER OBJECTS ---*/
			RBT_itBase<ValueType>	_current;
	};

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
*****************************                      OPERATORS                     *****************************
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

	template <class ValueType1, class ValueType2>
	bool operator == (const RBT_iterator< ValueType1>& lhs, const RBT_iterator< ValueType2>& rhs) {
		return ( lhs.base() == rhs.base());
	};

	template <class ValueType1, class ValueType2>
	bool operator == (const RBT_const_iterator< ValueType1>& lhs, const RBT_iterator< ValueType2>& rhs) {
		return ( lhs.base() == rhs.base());
	};

	template <class ValueType1, class ValueType2>
	bool operator == (const RBT_iterator< ValueType1>& lhs, const RBT_const_iterator< ValueType2>& rhs) {
		return ( lhs.base() == rhs.base());
	};

	template <class ValueType1, class ValueType2>
	bool operator == (const RBT_const_iterator< ValueType1>& lhs, const RBT_const_iterator< ValueType2>& rhs) {
		return ( lhs.base() == rhs.base());
	};

	template <class ValueType1, class ValueType2>
	bool operator != (const RBT_iterator< ValueType1>& lhs, const RBT_iterator< ValueType2>& rhs) {
		return ( lhs.base() != rhs.base());
	};

	template <class ValueType1, class ValueType2>
	bool operator != (const RBT_const_iterator< ValueType1>& lhs, const RBT_iterator< ValueType2>& rhs) {
		return ( lhs.base() != rhs.base());
	};

	template <class ValueType1, class ValueType2>
	bool operator != (const RBT_iterator< ValueType1>& lhs, const RBT_const_iterator< ValueType2>& rhs) {
		return ( lhs.base() != rhs.base());
	};

	template <class ValueType1, class ValueType2>
	bool operator != (const RBT_const_iterator< ValueType1>& lhs, const RBT_const_iterator< ValueType2>& rhs) {
		return ( lhs.base() != rhs.base());
	};
}

#endif