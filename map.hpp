#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include <sstream>
#include "utils/RBT.hpp"
#include "utils/pair.hpp"

namespace ft {
	template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T>> >
	class map {
/* ####################  PUBLIC  #################### */
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
			// typedef std::bidirectional_iterator<value_type>		iterator;
			// typedef std::bidirectional_iterator<value_type> 	const_iterator;
			// typedef std::reverse_iterator<iterator>				reverse_iterator;
			// typedef std::reverse_iterator<const_iterator> 		const_reverse_iterator;

			class value_compare : public std::binary_function<value_type, value_type, bool> {
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
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _rbt(comp, alloc) {};

			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {
				for (InputIterator it = first; it != last; ++ it)
					_rbt.insert(*it);
			};

			map (const map& x) {};

/* ####################  PRIVATE  #################### */
	/*--- MEMBER OBJECTS ---*/			
		private :
			RBT<value_type, key_compare , allocator_type>	_rbt;


/*---     ITERATORS    ---*/

/*---     CAPACITY     ---*/

/*---  ELEMENT ACCESS  ---*/
			
/*---     MODIFIERS    ---*/

/*---     ALLOCATOR    ---*/
	};
}

#endif