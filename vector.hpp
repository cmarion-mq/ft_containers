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
	
			~vector(void) {
			    for (size_type i = 0; i < _n; i ++) {
			        _alloc.destroy(_data + i);
					_n --;
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
						_alloc.construct(_data + i, x._data[i]);
				}
				return (*this);
			};
			
			reference operator[] (size_type n) { return (_data[n]); };
			const_reference operator[] (size_type n) const { return (_data[n]); };

			/*---    CAPACITY    ---*/
			size_type	size() const { return (_n); };
			size_type	max_size() const { return (_alloc.max_size()); };
			size_type	capacity() const { return (_capacity); };
			bool		empty() const { return (_n == 0); };

			// void 		resize (size_type n, value_type val = value_type()) {
			// 	if (n < _n) {
			// 		while (n != _n)
			// 			pop_back();
			// 	}
			// 	else if (n > _n) {
			// 		if (n > max_size())
			// 			throw std::length_error("cannot create std::vector larger than max_size()");
					//try to not push_back as many time as the delta is
			// 	}

			// };

			void 		reserve (size_type n) {
				if (n > _capacity) {
					if (n > max_size())
						throw std::length_error("cannot create std::vector larger than max_size()");
					pointer newp = _alloc.allocate(n);
					for (size_type i = 0; i < _n; i ++) {
						_alloc.construct(newp + i, _data[i]);
						_alloc.destroy(_data + i);
					}
					if (_capacity > 0)
						_alloc.deallocate(_data, _capacity);
					_data = newp;
					_capacity = n;
				}
			};

			/*---    MODIFIERS    ---*/
			// template <class InputIterator>
			// void assign(InputIterator first, InputIterator last);
			
			void assign (size_type n, const value_type& val) {
				if (_n + n > _capacity)
					reserve(_n + 1);
				size_type i = 
				if (n > _n)
			};

			void pop_back() {
				_alloc.destroy(_data + _n - 1);
				_n --;
			};

			void push_back (const value_type& val) {
				if (_n + 1 > _capacity)
					reserve(_n + 1);
				_alloc.construct(_data + _n + 1, val);
				_n ++;
			};

			// allocator_type get_allocator() const;

		private:
		    pointer			_data;
		    size_type		_n;
		    size_type		_capacity;
			allocator_type	_alloc;
	};
}

#endif
