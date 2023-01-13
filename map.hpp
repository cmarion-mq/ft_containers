#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include <sstream>
// #include "is_integral.hpp"
// #include "enable_if.hpp"
// #include "equal.hpp"
// #include "lexicographical_compare.hpp"
// #include "iterators_traits.hpp"
// #include "reverse_iterator.hpp"
#include "utils/is_integral.hpp"
#include "utils/enable_if.hpp"
#include "utils/equal.hpp"
#include "utils/lexicographical_compare.hpp"
#include "iterators/iterators_traits.hpp"
#include "iterators/reverse_iterator.hpp"

namespace ft {
	template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T>> >
	class map
	{
		public:
/*-------- TYPES ---------*/
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef pair<const Key, T>							value_type;
			typedef size_t										size_type;
			typedef std::ptrdiff_t 								difference_type;
			typedef Compare										key_compare;
			typedef Allocator									allocator_type;
			typedef typename Allocator::reference				reference;
			typedef typename Allocator::const_reference			const_reference;
			typedef typename Allocator::pointer					pointer;
			typedef typename Allocator::const_pointer			const_pointer;
			typedef std::bidirectional_iterator<iterator>		iterator;
			typedef std::bidirectional_iterator<const_iterator> const_iterator;
			typedef std::reverse_iterator<iterator>				reverse_iterator;
			typedef std::reverse_iterator<const_iterator> 		const_reverse_iterator;

			class value_compare : public binary_function<value_type,value_type,bool> {
				friend class map;
				public:
					bool operator()(const value_type& x, const value_type& y) const {
						return comp(x.first, y.first);
					}
					
				protected:
					Compare comp;
					value_compare(Compare c) : comp(c) {}
			};

/*--- CON/DE_STRUCTORS ---*/
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());

			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());

			map (const map& x);

/*---     ITERATORS    ---*/

/*---     CAPACITY     ---*/

/*---  ELEMENT ACCESS  ---*/
			
/*---     MODIFIERS    ---*/

/*---     ALLOCATOR    ---*/

		private:
			allocator_type	_alloc;
	};
}

#endif