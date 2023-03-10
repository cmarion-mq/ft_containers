#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include <sstream>
#include "utils/RBT.hpp"
#include "utils/pair.hpp"
#include "utils/equal.hpp"
#include "utils/lexicographical_compare.hpp"

namespace ft {
	template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<pair<const Key, T> > >
	class map {
		public:

/* ####################   TYPES   #################### */
			typedef Key												key_type;
			typedef T												mapped_type;
			typedef pair<const Key, T>								value_type;
			typedef size_t											size_type;
			typedef std::ptrdiff_t 									difference_type;
			typedef Compare											key_compare;
			typedef Allocator										allocator_type;
			typedef typename Allocator::reference					reference;
			typedef typename Allocator::const_reference				const_reference;
			typedef typename Allocator::pointer						pointer;
			typedef typename Allocator::const_pointer				const_pointer;

			class value_compare : public std::binary_function<value_type, value_type, bool> {
				friend class map;
				public:
					bool operator()(const value_type& x, const value_type& y) const {
						return comp(x.first, y.first);
					}

				protected:
					key_compare comp;
					value_compare(key_compare c) : comp(c) {}
			};

			typedef	RBT<value_type, value_compare, allocator_type>		rbt;
			typedef typename rbt::iterator							iterator;
			typedef typename rbt::const_iterator 					const_iterator;
			typedef typename rbt::reverse_iterator 					reverse_iterator;
			typedef typename rbt::const_reverse_iterator	  		const_reverse_iterator;

/* ####################  PUBLIC  #################### */
		/*--- CON/DE_STRUCTORS ---*/
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _rbt(RBT<value_type, value_compare, allocator_type>(value_compare(comp), alloc)) {};

			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _rbt(rbt(value_compare(comp), alloc)) {
				insert(first, last);
			};

			map (const map &x) {
				insert(x.begin(), x.end());
			};

			map& operator= (const map& x) {
				clear();
				insert(x.begin(), x.end());
				return (*this);
			}

			~map () {}

		/*---    ITERATORS     ---*/
			iterator				begin() 			{ return (_rbt.begin()); };	
			const_iterator			begin() 	const	{ return (_rbt.begin()); };
			reverse_iterator		rbegin()			{ return (_rbt.rbegin()); };
			const_reverse_iterator	rbegin() 	const	{ return (_rbt.rbegin()); };
			iterator				end()				{ return (_rbt.end()); };
			const_iterator			end()		const	{ return (_rbt.end()); };
			reverse_iterator 		rend()				{ return (_rbt.rend()); };
			const_reverse_iterator 	rend()		const	{ return (_rbt.rend()); };

		/*---     CAPACITY     ---*/
			bool		empty() const		{ return (_rbt.size() == 0); };
			size_type	size() const		{ return (_rbt.size()); };
			size_type	max_size() const	{ return (_rbt.max_size()); };
		
		/*---  ELEMENT ACCESS  ---*/
		
			mapped_type			&operator[] (const key_type& k) {
				typename rbt::nodePtr f = _rbt.find_node(ft::make_pair(k, T()));
				if (f)
					return (f->_value.second);
				_rbt.insert(value_type(k, mapped_type()));
				return(_rbt.find_node(ft::make_pair(k, T()))->_value.second);
			};

			mapped_type&		at (const key_type& k) {
				typename rbt::nodePtr f = _rbt.find_node(ft::make_pair(k, T()));
				if (!f) {
					throw std::out_of_range("map::at");
				}
				return (f->_value.second);
			};
			
			const mapped_type&	at (const key_type& k) const {
				typename rbt::nodePtr f = _rbt.find_node(ft::make_pair(k, T()));
				if (!f) {
					throw std::out_of_range("map::at");
				}
				return (f->_value.second);

			};

		/*---     MODIFIERS    ---*/
			pair<iterator, bool>	insert (const value_type& val) {
				iterator i = find(val.first);
				if (i == end())
					return (pair<iterator, bool> (_rbt.insert(val), true));
				else
					return (pair<iterator, bool> (i, false));
			};

			iterator 				insert (iterator position, const value_type& val) {
				(void) position;
				return (insert(val).first);
			};

			template <class InputIterator>
			void					insert (InputIterator first, InputIterator last) {
				while (first != last) {
					value_type temp = *first;
					insert(temp);
					first ++;
				}
			};

			void 					erase( iterator pos ) {
				_rbt.del(*pos);
			};

			size_type 				erase( const Key& key ) {
				if (_rbt.del(ft::make_pair(key, T())))
					return (1);
				return (0);
			};

			void 					erase (iterator first, iterator last) {
				while (first != last) {
					iterator del = first;
					first ++;
					erase(del);
				}
			};

			void 					swap (map& x) {
				_rbt.swap(x._rbt);
			};

			void 					clear() {
				_rbt.clear();
			};

		/*---     OBSERVERS    ---*/
			key_compare		key_comp() 		const	{ return (key_compare()); };
			value_compare 	value_comp() 	const	{ return (value_compare(key_comp())); };

		/*---     OPERATIONS    ---*/
			iterator		find (const key_type &k) {
				typename rbt::nodePtr f = _rbt.find_node(ft::make_pair(k, T()));
				if (f) {
					return (iterator(f));
				}
				return (end());
			};
			
			const_iterator	find (const key_type& k) const {
				typename rbt::nodePtr f = _rbt.find_node(ft::make_pair(k, T()));
				if (f)
					return (const_iterator(f));
				return (end());
			};
			
			size_type		count( const key_type &key ) const {
				if (_rbt.find_node(ft::make_pair(key, T())))
					return (1);
				return (0);
			};

			iterator 		lower_bound (const key_type& k) 		{ return (_rbt.lower_bound(ft::make_pair(k, T()))); };
			const_iterator	lower_bound (const key_type& k) const	{ return (_rbt.lower_bound(ft::make_pair(k, T()))); };
			iterator 		upper_bound (const key_type& k) 		{ return (_rbt.upper_bound(ft::make_pair(k, T()))); };
			const_iterator 	upper_bound (const key_type& k) const 	{ return (_rbt.upper_bound(ft::make_pair(k, T()))); };

			pair<iterator,iterator>             equal_range (const key_type& k) {
				return ft::make_pair(lower_bound(k), upper_bound(k));
			};

			pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
				return ft::make_pair(lower_bound(k), upper_bound(k));
			};

		/*---     ALLOCATOR    ---*/
			allocator_type get_allocator() const { return (_rbt.get_allocator()); };

		/*---      DIVERS      ---*/
			void print() {
				std::cout << "size: " << size() << std::endl;
				_rbt.printTree();
			};

/* ####################  PRIVATE  #################### */
		private :
	/*--- MEMBER OBJECTS ---*/			
			RBT<value_type, key_compare, allocator_type>	_rbt;
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator ==( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
		if (lhs.size() != rhs.size())
			return false;
		else
		{
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		}
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator !=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
		return (!(lhs == rhs));
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator <( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator <=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
		return (!(rhs < lhs));
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator >( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
		return (rhs < lhs);
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator>= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
		return (!(lhs < rhs));
	};

	template <class Key, class T, class Compare, class Alloc>
	void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y) {
		x.swap(y);
	};
}

#endif