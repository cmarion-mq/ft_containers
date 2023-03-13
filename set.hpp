#ifndef SET_HPP
# define SET_HPP

#include <iostream>
#include <sstream>
#include "utils/RBT.hpp"
#include "utils/pair.hpp"
#include "utils/equal.hpp"
#include "utils/lexicographical_compare.hpp"

namespace ft {
	template<class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key> > 
	class set {
/* ####################   TYPES   #################### */
		public :
			typedef Key												key_type;
			typedef Key												value_type;
			typedef size_t											size_type;
			typedef std::ptrdiff_t 									difference_type;
			typedef Compare											key_compare;
			typedef Compare											value_compare;
			typedef Allocator										allocator_type;
			typedef typename Allocator::reference					reference;
			typedef typename Allocator::const_reference				const_reference;
			typedef typename Allocator::pointer						pointer;
			typedef typename Allocator::const_pointer				const_pointer;
			typedef	RBT<value_type, key_compare, allocator_type>	rbt;
			typedef typename rbt::iterator							iterator;
			typedef typename rbt::const_iterator 					const_iterator;
			typedef typename rbt::reverse_iterator 					reverse_iterator;
			typedef typename rbt::const_reverse_iterator	  		const_reverse_iterator;
	
/* ####################  PUBLIC  #################### */
		/*--- CON/DE_STRUCTORS ---*/
			explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _rbt(rbt(comp, alloc)) {};

			template <class InputIterator> 
			set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _rbt(rbt(comp, alloc)) {
				insert(first, last);
			};

			set (const set& x) {
				insert(x.begin(), x.end());
			};

			set& operator= (const set& x) {
				clear();
				insert(x.begin(), x.end());
				return (*this);
			};

			~set () {};

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

		/*---     MODIFIERS    ---*/
			pair<iterator, bool>	insert (const value_type& val) {
				typename rbt::nodePtr f = _rbt.find_node(val);
				if (!f)
					return (pair<iterator, bool> (_rbt.insert(val), true));
				else
					return (pair<iterator, bool> (iterator(f), false));
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

			size_type 				erase( const value_type& val ) {
				if (_rbt.del(val))
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

			void 					swap (set& x) {
				_rbt.swap(x._rbt);
			};

			void 					clear() {
				_rbt.clear();
			};

		/*---     OBSERVERS    ---*/
			key_compare		key_comp() 		const	{ return (key_compare()); };
			value_compare 	value_comp() 	const	{ return (value_compare(key_comp())); };

		/*---     OPERATIONS    ---*/
			iterator		find (const value_type &val) {
				typename rbt::nodePtr f = _rbt.find_node(val);
				if (f) {
					return (iterator(f));
				}
				return (end());
			};
						
			size_type		count( const value_type &val ) const {
				if (_rbt.find_node(val))
					return (1);
				return (0);
			};

			iterator 		lower_bound (const value_type& val) const	{
				return (const_iterator(_rbt.lower_bound(val)));
			};

			iterator 		upper_bound (const value_type& val) const	{
				return (iterator(_rbt.upper_bound(val)));
			};

			pair<iterator,iterator>	equal_range (const value_type& val) const {
				return ft::make_pair(lower_bound(val), upper_bound(val));
			};

		/*---     ALLOCATOR    ---*/
			allocator_type get_allocator() const { return (_rbt.get_allocator()); };

/* ####################  PRIVATE  #################### */
		private :
		/*--- MEMBER OBJECTS ---*/			
			rbt	_rbt;
	};

		template <class T, class Compare, class Alloc>
		bool operator ==( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs ) {
			if (lhs.size() != rhs.size())
				return false;
			else
			{
				return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
			}
		};

		template <class T, class Compare, class Alloc>
		bool operator !=( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs ) {
			return (!(lhs == rhs));
		};

		template <class T, class Compare, class Alloc>
		bool operator <( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs ) {
				return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		};

		template <class T, class Compare, class Alloc>
		bool operator <=( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs ) {
			return (!(rhs < lhs));
		};

		template <class T, class Compare, class Alloc>
		bool operator >( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs ) {
			return (rhs < lhs);
		};

		template <class T, class Compare, class Alloc>
		bool operator>= ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs ) {
			return (!(lhs < rhs));
		};

		template <class T, class Compare, class Alloc>
		void swap (set<T,Compare,Alloc>& x, set<T,Compare,Alloc>& y) {
			x.swap(y);
		}
}

#endif