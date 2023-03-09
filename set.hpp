#ifndef SET_HPP
# define SET_HPP

#include <iostream>
#include <sstream>
#include "utils/RBT.hpp"

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
	
	
	};
}

#endif