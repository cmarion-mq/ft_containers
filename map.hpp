#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include <sstream>
#include "utils/RBT.hpp"
#include "utils/pair.hpp"

namespace ft {
	template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > >
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
			typedef RBT_iterator<value_type, mapped_type>		iterator;
			typedef RBT_iterator<value_type, const mapped_type> const_iterator;
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
				insert(first, last);
			};

			map (const map& x) {
				insert(x.begin(), x.end());
			};

			map& operator= (const map& x) {
				clear();
				insert(x.begin(), x.end());
				return (*this);
			}

			~map () {
				clear();
			}

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
		
			mapped_type &operator[] (const key_type& k) {
				return (_rbt.find_node(k)->_pair.second);
			};

		/*---     MODIFIERS    ---*/
			pair<iterator,bool>	insert (const value_type& val) {
				if (_rbt.find_node(val.first))
					return (pair<iterator, bool> (_rbt.insert(val), true));
				else
					return (pair<iterator, bool> (_rbt.find_node_i(val.first), false));
			};

			// iterator 			insert (iterator position, const value_type& val) {};

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last) {
				while (first != last) {
					_rbt.insert(*first);
					first ++;
				}
			};

			void erase( iterator pos ) {
				_rbt.del(*pos._current->_key);
			};

			size_type erase( const Key& key ) {
				if (_rbt.del(key))
					return (1);
				return (0);
			};

			void clear() {
				_rbt.clear();
			};

		/*---     OPERATIONS    ---*/
			iterator find (const key_type &k) {
				return (_rbt.find_node_i(k));
			};
			
			const_iterator find (const key_type& k) const {
				return (_rbt.find_node_i(k));
			};
			
			size_type count( const key_type &key ) const {
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


	};
}

#endif