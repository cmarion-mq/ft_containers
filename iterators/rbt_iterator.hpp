#ifndef RBT_ITERATOR
# define RBT_ITERATOR

#include "../utils/RBT_node.hpp"
#include "iterators/iterators_traits.hpp"

namespace ft {
	template< typename ValueType>
	class RBT_iterator;

	template< typename ValueType>
	class RBT_const_iterator;
/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
*****************************                   ITERATOR BASE                    *****************************
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
	template< typename ValueType>
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

			virtual ~RBT_itBase() {};

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

			bool			operator ==(constRBT_itBase &other) const {
				return (_current == other._current);
			}

			bool			operator !=(constRBT_itBase &other) const {
				return (_current != other._current);
			}

			ValueType 		&operator	*()		{ return (_current->_pair);		};
			ValueType 		*operator	->()	{ return (&_current->_pair);	};
			
			operatorRBT_itBase<const ValueType>() const {
				return (RBT_itBase<const ValueType>)(this->_current);
			}

/* ####################   PRIVATE  #################### */
		private:			
		/*--- MEMBER OBJECTS ---*/
			nodePtr	_current;
    };

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
*****************************                      ITERATOR                      *****************************
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

	template< typename ValueType>
	class RBT_iterator {
/* ####################   PUBLIC  #################### */
		public:
	/*-------- TYPES ---------*/
			typedef Node<ValueType>	node;
			typedef node *			nodePtr;

	/*--- CON/DE_STRUCTORS ---*/
			RBT_iterator(): _current(NULL) {};

			RBT_iterator(nodePtr current): _current(RBT_itBase(current)) {};

			RBT_iterator(const RBT_iterator &x) {
				_current = x._current;
			};

			RBT_iterator &operator =(const RBT_itBase<ValueType> &x) {
				if (this == &x) { 
					return *this;
				}
				_current = x._current;
				return (*this);
			}

			virtual ~RBT_itBase() {};

			RBT_iterator	&operator	--() {
				-- _current;
				return (*this);
			};

			RBT_iterator	&operator	++() {
				++ _current;
				return (*this);
			};

			RBT_iterator	operator	++(int) {
				RBT_itBase temp(*this);
				operator ++();
				return (temp);
			}

			RBT_iterator	operator	--(int) {
				RBT_itBase temp(*this);
				operator --();
				return (*this);
			}

			bool			operator ==(constRBT_itBase &other) const {
				return (_current == other._current);
			}

			bool			operator !=(constRBT_itBase &other) const {
				return (_current != other._current);
			}

			ValueType 		&operator	*()		{ return (_current->_pair);		};
			ValueType 		*operator	->()	{ return (&_current->_pair);	};
			
			operatorRBT_itBase<const ValueType>() const {
				return (RBT_itBase<const ValueType>)(this->_current);
			}

/* ####################   PRIVATE  #################### */
		private:			
		/*--- MEMBER OBJECTS ---*/
			RBT_itBase	_current;
	};

	template< typename ValueType>
	class RBT_const_iterator;

}

#endif