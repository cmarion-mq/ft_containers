#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include <sstream>
#include "iterators/reverse_iterator.hpp"
#include "iterators/rbt_iterator.hpp"
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
			typedef ft::rbt_iterator<value_type>				iterator;
			typedef ft::rbt_iterator<const value_type> 			const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> 		const_reverse_iterator;

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
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _rbt(comp, alloc) {
				for (InputIterator it = first; it != last; ++ it)
					_rbt.insert(*it);
			};

			map (const map& x) {}; //###################_TO_DO

		/*---     CAPACITY     ---*/
			bool		empty() const		{ return (_rbt.size() == 0); };
			size_type	size() const		{ return (_rbt.size()); };
			size_type	max_size() const	{ return (_rbt.max_size()); };
		
		/*---  ELEMENT ACCESS  ---*/
		
		
		/*---     MODIFIERS    ---*/
			void clear() {
				_rbt.clear();
			};

			iterator erase( iterator pos ) {}; //###################_TO_DO

			size_type erase( const Key& key ) {
				if (_rbt.del(key))
					return (1);
				return (0);
			};

			pair<iterator,bool> insert (const value_type& val) {}; //###################_TO_DO

		/*---     MODIFIERS    ---*/
			size_type count( const Key& key ) const {
				if (_rbt.find_node(key))
					return (1);
				return (0);
			};

		/*---      DIVERS      ---*/
			void print() {
				std::cout << "size: " << size() << std::endl;
				_rbt.printTree();
			};

/* ####################  PRIVATE  #################### */
	/*--- MEMBER OBJECTS ---*/			
		private :
			RBT<value_type, key_compare, allocator_type>	_rbt;


/*---     ITERATORS    ---*/


			
/*---     ALLOCATOR    ---*/
	};
}

#endif