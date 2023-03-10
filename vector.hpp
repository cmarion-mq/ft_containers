#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <sstream>
#include "utils/is_integral.hpp"
#include "utils/enable_if.hpp"
#include "utils/equal.hpp"
#include "utils/lexicographical_compare.hpp"
#include "iterators/iterators_traits.hpp"
#include "iterators/reverse_iterator.hpp"
# include "iterators/random_access_iterator.hpp"

namespace ft {
	template < class T, class Allocator = std::allocator<T> >
	class vector {
/* ####################   PUBLIC  #################### */
		public:
		/*-------- TYPES ---------*/
			typedef T										value_type;
			typedef Allocator								allocator_type;
			typedef typename Allocator::reference			reference;
			typedef typename Allocator::const_reference		const_reference;
			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;
			typedef random_access_iterator<pointer>			iterator;
			typedef random_access_iterator<const_pointer>	const_iterator;
			// typedef T*										iterator;
			// typedef const T*								const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef std::ptrdiff_t 							difference_type;
			typedef size_t									size_type; 

		/*--- CON/DE_STRUCTORS ---*/
			explicit vector(const allocator_type& alloc = allocator_type()): _alloc(alloc), _data(NULL), _n(0), _capacity(0)
			{};
			
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _alloc(alloc), _n(n), _capacity(n) {
				if (n > 0) {
					if (_n > _alloc.max_size())
						throw std::length_error("cannot create std::vector larger than max_size()");
					_data = _alloc.allocate(n);
					for (size_type i = 0; i < _n; i ++)
						_alloc.construct(_data + i, val);
				}
			};
			
			template <class InputIterator>
			vector (typename enable_if<!ft::is_integral< InputIterator >::value, InputIterator >::type first, InputIterator last, const allocator_type& alloc = allocator_type()): _alloc(alloc), _data(NULL), _n(0), _capacity(0) {
				insert_helper(begin(), first, last, typename iterator_traits<InputIterator>::iterator_category());
			};
			
			vector (const vector& x) {
				_n = 0;
				_data = NULL;
				_capacity = 0;
				*this = x;
			};
	
			~vector(void) {
				clear();
				if (_capacity > 0)
					_alloc.deallocate(_data, _capacity);
				_capacity = 0;
			};

			vector &operator= (const vector &x) {
				if (this != &x) {
					_alloc = x._alloc;
					clear();
					reserve(x._n);
					_n = x._n;
					for (size_type i = 0; i < _n; i ++)
						_alloc.construct(_data + i, x._data[i]);
				}
				return (*this);
			};

		/*---     ITERATORS    ---*/
			iterator				begin()			{ return iterator(_data); };
			const_iterator			begin() const	{ return const_iterator(_data); };
			iterator 				end()			{ return iterator(_data + _n); };
			const_iterator			end() const		{ return const_iterator(_data + _n); };
			reverse_iterator		rbegin()		{ return reverse_iterator(end()); };
			const_reverse_iterator 	rbegin() const	{ return const_reverse_iterator(end()); };
			reverse_iterator		rend()			{ return reverse_iterator(begin()); };
			const_reverse_iterator	rend() const	{ return const_reverse_iterator(begin()); };

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

		/*---  ELEMENT ACCESS  ---*/
			reference		operator[] (size_type n)		{ return (_data[n]); };
			const_reference operator[] (size_type n) const	{ return (_data[n]); };
			reference		front()							{ return (*_data); };
			const_reference	front() const 					{ return (*_data); };
			reference		back() 							{ return (*(_data + _n - 1)); };
			const_reference	back() const 					{ return (*(_data + _n - 1)); };

			reference		at (size_type n) {

				if (n >= _n) {
					std::string			str;
					std::stringstream	stn, st_n;
					stn << n;
					st_n << _n;
					str = "vector::_M_range_check: __n (which is " + stn.str() + ") >= this->size() (which is " + st_n.str() + ")";
					throw std::out_of_range(str);
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
			template <class InputIterator>
			void assign(InputIterator first, typename enable_if<!ft::is_integral< InputIterator >::value, InputIterator >::type last) {
				clear();
				insert_helper(begin(), first, last, typename iterator_traits<InputIterator>::iterator_category());
			};
			
			void assign(size_type n, const value_type& val) {
				if (_n + n > _capacity)
					reserve(n);
				for (size_type i = 0; i < n; i ++) {
					if (i < _n)
						_alloc.destroy(_data + i);
					_alloc.construct(_data + i, val);
				}
				for (size_type i = n; i < _n; i ++)
					_alloc.destroy(_data + i);
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
						reserve(_n * 2);
					position = begin() + tot_between_begin_position;
				}
				for (size_type i = _n; i > tot_between_begin_position && i > 0; i --) {
					_alloc.construct(_data + i, _data[i - 1]);
					_alloc.destroy(_data + i - 1);
				}
				_alloc.construct(&(*position), val);
				_n ++;
				return(position);
			};

			void insert(iterator position, size_type n, const value_type& val) {
				size_type tot_between_begin_position = std::distance(begin(), position);
				if (n > 0) {
					if (_n + n > _capacity) {
						if (_capacity == 0)
							reserve(n);
						else if ( _n + n <= _n * 2)
							reserve(_n * 2);
						else
							reserve(_n + n);
					}
					if (_n > 0 && tot_between_begin_position < _n) {
						for (size_type i = _n + n - 1; i > _n - 1 && i > n + tot_between_begin_position - 1; i --) 
							_alloc.construct(_data + i, _data[i - n]);
						for (size_type i = _n - 1; i > tot_between_begin_position + n - 1; i --) {
							if (i < _n)
								_alloc.destroy(_data + i);
							_alloc.construct(_data + i, _data[i - n]);
						}
					}
					for (size_type i = tot_between_begin_position; i < tot_between_begin_position + n; i ++) {
						if (i < _n)
							_alloc.destroy(_data + i);
						_alloc.construct(_data + i, val);
					}
					_n += n;
				}
			};
			
			template <class InputIterator>
			void insert(iterator position, InputIterator first, typename enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last) {
				insert_helper(position, first, last, typename iterator_traits<InputIterator>::iterator_category());
			};

			iterator erase(iterator position) {
				if (position + 1 != end()) {
					size_type tot_between_begin_position = std::distance(begin(), position);
					for (size_type i = tot_between_begin_position; i < _n - 1; i ++) {
						_alloc.destroy(_data + i);
						_alloc.construct(_data + i, _data[i + 1]);
					}
				}
				_alloc.destroy(_data + _n - 1);
				_n --;
				return (position);			
			};
			
			iterator erase(iterator first, iterator last) {
				if (first != last) {
					size_type n = std::distance(first, last); //tot erase
					size_type tot_between_begin_position = std::distance(begin(), first);
					for (size_type i = tot_between_begin_position; i < _n - n; i ++) {
						_alloc.destroy(_data + i);
						_alloc.construct(_data + i, _data[i + n]);
					}
					for (size_type i = _n - n; i < _n; i ++)
						_alloc.destroy(_data + i);
					_n -= n;
				}
				return (first);
			};

			void swap(vector& x) {
				std::swap(_data, x._data);
				std::swap(_n, x._n);
				std::swap(_capacity, x._capacity);
				std::swap(_alloc, x._alloc);
			};

			void clear() {
				for (size_type i = 0; i < _n; i ++)
					_alloc.destroy(_data + i);
				_n = 0;
			};

		/*---     ALLOCATOR    ---*/
			allocator_type get_allocator() const { return _alloc; };

/* ####################   PRIVATE  #################### */
		private:
		/*---     MEMBER OBJECTS    ---*/
			allocator_type	_alloc;
		    pointer			_data;
		    size_type		_n;
		    size_type		_capacity;

		/*---     FONCTION HELPERS   ---*/
			template <class InputIterator>
			void insert_helper(iterator position, InputIterator first, InputIterator last, std::forward_iterator_tag) {
				size_type tot_between_begin_position = std::distance(begin(), position);
				size_type n = std::distance(first, last); //tot insert
				if (n > 0) { 
					if (_n + n > _capacity) {
						if (_capacity == 0)
							reserve(n);
						else if ( _n + n <= _n * 2)
							reserve(_n * 2);
						else
							reserve(_n + n);
					}
					if (_n > 0 && tot_between_begin_position < _n) {
						for (size_type i = _n + n - 1; i > _n - 1 && i > n + tot_between_begin_position - 1; i --) 
							_alloc.construct(_data + i, _data[i - n]);
						for (size_type i = _n - 1; i > tot_between_begin_position + n - 1; i --) {
							if (i < _n)
								_alloc.destroy(_data + i);
							_alloc.construct(_data + i, _data[i - n]);
						}
					}
					for (size_type i = tot_between_begin_position; i < tot_between_begin_position + n; i ++, first ++) {
						if (i < _n)
							_alloc.destroy(_data + i);
						_alloc.construct(_data + i, *first);
						// *(_data + i) = *first;
					}
					_n += n;
				}
			};

			template <class InputIterator>
			void insert_helper(iterator position, InputIterator first, InputIterator last, std::input_iterator_tag) {
			size_type tot_between_begin_position = std::distance(begin(), position);
				for (InputIterator it = first; it != last; ++ it, tot_between_begin_position ++)
					insert(iterator(begin() + tot_between_begin_position), *it);
			};
	};

/*---     NON MEMBER FONCTION    ---*/
	template <class T, class Alloc>
	inline bool operator == (const vector<T, Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return ( lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()) );
	};

	template <class T, class Alloc>
	inline bool operator != (const vector<T, Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return ( !(lhs == rhs) );
	};

	template <class T, class Alloc>
	bool operator < (const vector<T, Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return ( ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) );
	};

	template <class T, class Alloc>
	bool operator <= (const vector<T, Alloc>& lhs, const vector<T,Alloc>& rhs){
		return ( !(rhs < lhs) );
	};

	template <class T, class Alloc>
	bool operator >  (const vector<T, Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return ( rhs < lhs );
	};

	template <class T, class Alloc>
	bool operator >= (const vector<T, Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return ( !(lhs < rhs) );
	};

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
		x.swap(y);
	};
}

#endif