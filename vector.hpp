#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include "utils/is_integral.hpp"
#include "utils/enable_if.hpp"
#include "iterators/iterators_traits.hpp"

namespace ft {
	template < class T, class Allocator = std::allocator<T>>
	class vector
	{
		public:
			/*--- TYPES ---*/
			typedef T										value_type;
			typedef Allocator								allocator_type;
			typedef typename Allocator::reference			reference;
			typedef typename Allocator::const_reference		const_reference;
			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;
			typedef T*										iterator;
			typedef const T*								const_iterator;
			typedef std::reverse_iterator<iterator>			reverse_iterator;
			typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef size_t									size_type; 

			/*--- CON/DE_STRUCTORS ---*/
			explicit vector(const allocator_type& alloc = allocator_type()): _alloc(alloc), _data(NULL), _n(0), _capacity(0) {};
			
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _alloc(alloc), _n(n), _capacity(n) {
				if (_n > _alloc.max_size())
					throw std::length_error("cannot create std::vector larger than max_size()");
				_data = _alloc.allocate(_n);
				for (size_type i = 0; i < _n; i ++)
					_alloc.construct(_data + i, val);
			};
			
			template <class InputIterator>
			vector (typename enable_if<!ft::is_integral< InputIterator >::value, InputIterator >::type first, InputIterator last, const allocator_type& alloc = allocator_type()): _alloc(alloc) {
				_n = std::distance(first,last);
				_capacity = _n;
				_data = _alloc.allocate(_n);
				int i = 0;
				for (InputIterator it = first; it != last; ++ it, i ++)
					_alloc.construct(_data + i, *it);
			};
			
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

			/*---     ITERATORS    ---*/
			iterator				begin()			{ return _data; };
			const_iterator			begin() const	{ return _data; };
			iterator 				end()			{ return _data + _n; };
			const_iterator			end() const		{ return _data + _n; };
			reverse_iterator		rbegin()		{ return reverse_iterator(_data + _n); };
			const_reverse_iterator 	rbegin() const	{ return const_reverse_iterator(_data + _n); };
			reverse_iterator		rend()			{ return reverse_iterator(_data);};
			const_reverse_iterator	rend() const	{ return const_reverse_iterator(_data);};

			/*---     CAPACITY     ---*/
			size_type	size() const		{ return (_n); };
			size_type	max_size() const	{ return (_alloc.max_size()); };
			size_type	capacity() const	{ return (_capacity); };
			bool		empty() const		{ return (_n == 0); };

			void 		resize (size_type n, value_type val = value_type()) {
				if (n < _n) {
					while (n != _n)
						pop_back();
				}
				else if (n > _n)
					insert(end(), n - _n, val);
			};

			void 		reserve (size_type n) {
				if (n > _capacity) {
					if (n > max_size())
						throw std::length_error("vector::reserve");
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

			/*---  ELEMENT ACCESS  ---*/
			
			reference		operator[] (size_type n)		{ return (_data[n]); };
			const_reference operator[] (size_type n) const	{ return (_data[n]); };
			reference		front()							{ return (*_data); };
			const_reference	front() const 					{ return (*_data); };
			reference		back() 							{ return (*(_data + _n - 1)); };
			const_reference	back() const 					{ return (*(_data + _n - 1)); };
			
			reference		at (size_type n) {
				if (n >= _n) {
					throw std::out_of_range("vector::at");
				}
				return (_data[n]);
			};

			const_reference	at (size_type n) const {
				if (n >= _n) {
					throw std::out_of_range("vector::at");
				}
				return (_data[n]);
			};
			
			/*---     MODIFIERS    ---*/
			// template <class InputIterator>
			// void assign(InputIterator first, InputIterator last);
			
			void assign(size_type n, const value_type& val) {
				if (_n + n > _capacity)
					reserve(_n + 1);
				for (size_type i = 0; i < n; i ++) {
					if (i < _n)
						_alloc.destroy(_data + i);
					_alloc.construct(_data + i, val);
				}
				_n = n;
			};

			void push_back(const value_type& val) {
				if (_capacity == 0)
					reserve(1);
				if (_n + 1 > _capacity)
					reserve(_capacity * 2);
				_alloc.construct(_data + _n, val);
				_n ++;
			};

			void pop_back(){
				_alloc.destroy(_data + _n - 1);
				_n --;
			};

			iterator insert(iterator position, const value_type& val) {
				size_type tot_between_begin_position = std::distance(begin(), position);
				if (_n + 1 > _capacity) {
					if (_capacity == 0)
						reserve(1);
					else
						reserve(_capacity * 2);
					position = begin() + tot_between_begin_position;
				}
				for (size_type i = _n + 1; i > tot_between_begin_position; i --) {
					_alloc.construct(_data + i, _data[i - 1]);
					_alloc.destroy(_data + i - 1);
				}
				_alloc.construct(position, val);
				_n ++;
				return(position);
			};

			void insert(iterator position, size_type n, const value_type& val) {
				size_type tot_between_begin_position = std::distance(begin(), position);
				if (_n + n > _capacity) {
					if (_capacity == 0)
						reserve(1);
					else if ( _n + n <= _capacity * 2)
						reserve(_capacity * 2);
					else
						reserve(_n + n);
					position = begin() + tot_between_begin_position;
				}
				size_type i = _n + 1;
				for (; i > tot_between_begin_position + n; i --) {
					_alloc.construct(_data + i, _data[i - 1]);
					_alloc.destroy(_data + i - 1);
				}
				_alloc.construct(_data + i - 1, val);
				for (size_type i = tot_between_begin_position; i < tot_between_begin_position + n; i ++) {
					_alloc.destroy(_data + i);
					_alloc.construct(_data + i, val);
				}
				_n += n;
			};
			
			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last) {
				size_type tot_between_begin_position = std::distance(begin(), position);
				size_type n = std::distance(first, last); //tot insert
				if (_n + n > _capacity) {
					if (_capacity == 0)
						reserve(1);
					else if ( _n + n <= _capacity * 2)
						reserve(_capacity * 2);
					else
						reserve(_n + n);
					position = begin() + tot_between_begin_position;
				}
				size_type i = _n + 1;
				for (; i > tot_between_begin_position + n; i --) {
					_alloc.construct(_data + i, _data[i - 1]);
					_alloc.destroy(_data + i - 1);
				}
				_alloc.construct(_data + i - 1, *last);
				i = tot_between_begin_position;
				for (iterator it = first; it != last - 1; ++ it, i ++) {
					_alloc.construct(_data + i, _data[i - 1]);
					_alloc.destroy(_data + i - 1);
				}
				_n += n;
			};

			iterator erase(iterator position) {
				size_type tot_between_begin_position = std::distance(begin(), position);
				for (size_type i = tot_between_begin_position; i < _n; i ++) {
					_alloc.destroy(_data + i);
					_alloc.construct(_data + i, _data[i + 1]);
				}
				_alloc.destroy(_data + _n);
				_n --;
				return (position);
			};
			
			iterator erase(iterator first, iterator last) {
				size_type n = std::distance(first, last); //tot erase
				size_type tot_between_begin_position = std::distance(begin(), first);
				for (size_type i = tot_between_begin_position; i < _n - 1; i ++) {
					_alloc.destroy(_data + i);
					_alloc.construct(_data + i, _data[i + n]);
					_alloc.destroy(_data + i + n);
				}
				_n -= n;
				return (first);
			};

			void swap(vector& x) {

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
