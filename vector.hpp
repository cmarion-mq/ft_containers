#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include "utils/is_integral.hpp"
#include "utils/enable_if.hpp"

namespace ft {
	template < class T, class Allocator = std::allocator<T>>
	class vector
	{
		public:
			/*--- TYPES ---*/
			typedef T									value_type;
			typedef Allocator							allocator_type;
			typedef typename Allocator::reference		reference;
			typedef typename Allocator::const_reference	const_reference;
			typedef typename Allocator::pointer			pointer;
			typedef typename Allocator::const_pointer	const_pointer;
			typedef size_t								size_type; 

			/*--- CON/DE_STRUCTORS ---*/
			explicit vector(const allocator_type& alloc = allocator_type()): _alloc(alloc), _data(NULL), _n(0), _capacity(0) {};
			
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _alloc(alloc), _n(n), _capacity(n) {
				std::cout << _alloc.max_size() << std::endl;
				if (_n > _alloc.max_size())
					throw std::length_error("cannot create std::vector larger than max_size()");
				_data = _alloc.allocate(_n);
				for (size_type i = 0; i < _n; i ++)
					_alloc.construct(_data + i, val);
			};
			
			// template <class InputIterator>
			// vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename enable_if<!is_integral< InputIterator >::value, void* >::type* = NULL): _alloc(alloc) {
				

			// 	for (InputIterator it = first; it != last; ++it)
			// 		_alloc.construct(_data + _size, *it);
			// 	_size ++;
			// };
			
			vector (const vector& x) {
				*this = x;
			};
			

			// template <class InputIterator>
			// void assign(InputIterator first, InputIterator last);
			
			// void assign(size_type n, const T& u);
			// allocator_type get_allocator() const;

	
			~vector(void) {
				std::cout << "in destructor" << std::endl;
			    for (size_type i = 0; i < _n; i ++) {
			        _alloc.destroy(_data + i);
					_n --;
					_capacity --;
				}
				if (_capacity > 0)
					_alloc.deallocate(_data, _capacity);
				_capacity = 0;
			};

			/*---    OPERATORS    ---*/
			vector &operator= (const vector &x) {
				if (this != &x) {
					_n = x._n;
					_capacity = x._capacity;
					_alloc = x._alloc;
					_data = _alloc.allocate(_n);
					for (size_type i = 0; i < _n; i ++)
						_alloc.construct(&_data[i], x._data[i]);
				}
				return (*this);
			};
			
			reference operator[] (size_type n) { return (_data[n]); };
			const_reference operator[] (size_type n) const { return (_data[n]); };

			/*---    CAPACITY    ---*/
			size_type size() const { return (_n); };
			size_type capacity() const { return (_capacity); };

		private:
		    pointer			_data;
		    size_type		_n;
		    size_type		_capacity;
			allocator_type	_alloc;
	};
}

#endif
