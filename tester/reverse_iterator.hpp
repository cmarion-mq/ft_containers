#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterators_traits.hpp"

namespace ft {
	template <class Iterator>
	class reverse_iterator : public std::iterator <	typename iterator_traits<Iterator>::iterator_category,
													typename iterator_traits<Iterator>::value_type,
													typename iterator_traits<Iterator>::difference_type,
													typename iterator_traits<Iterator>::pointer,
													typename iterator_traits<Iterator>::reference >
	{
		public:
/*-------- TYPES ---------*/
			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::difference_type 	difference_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;
			
/*--- CON/DE_STRUCTORS ---*/
			reverse_iterator(): _current(NULL) {};
			
			explicit reverse_iterator (iterator_type it): _current(it) {};
			
			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it): _current(rev_it.base()) {};

/*---       BASE       ---*/
			iterator_type 		base() const 							{ return _current; };

/*---     OPERATORS    ---*/
			reverse_iterator	operator+ (difference_type n) const 	{ return reverse_iterator(_current - n); };
			reverse_iterator	operator- (difference_type n) const 	{ return reverse_iterator(_current + n); };
			reference 			operator[] (difference_type n) const 	{ return *(_current - n - 1); };
			pointer 			operator->() const 						{ return &(operator*()); }

			reference			operator*() const {
				iterator_type	temp = base() - 1;
				return *temp; 
			};
			
			reverse_iterator&	operator++() { 
				-- _current;
				return *this;
			};

			reverse_iterator 	operator++(int) {
				reverse_iterator temp = *this;
				++(*this);
  				return temp;
			};

			reverse_iterator&	operator+= (difference_type n){ 
				_current -= n;
				return *this;
			};

			reverse_iterator&	operator--(){
				++ _current;
  				return (*this);
			};

			reverse_iterator	operator--(int) {
  				reverse_iterator temp = *this;
  				--(*this);
  				return temp;
			}

			reverse_iterator&	operator-= (difference_type n) {
				_current += n;
				return *this;
			};

		protected:
			Iterator _current;
    };

	template <class Iterator1, class Iterator2>
	bool operator== (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
		return ( lhs.base() == rhs.base());
	};

	template <class Iterator1, class Iterator2>
	bool operator!= (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
		return ( lhs.base() != rhs.base());
	};

	template <class Iterator1, class Iterator2>
	bool operator<  (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
		return ( lhs.base() > rhs.base());
	};

	template <class Iterator1, class Iterator2>
	bool operator<= (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
		return ( lhs.base() >= rhs.base());
	};

	template <class Iterator1, class Iterator2>
	bool operator>  (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
		return ( lhs.base() < rhs.base());
	};

	template <class Iterator1, class Iterator2>
	bool operator>= (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
		return ( lhs.base() <= rhs.base());
	};

	/*template <class Iterator>
	bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return ( lhs.base() == rhs.base());
	};

	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return ( lhs.base() != rhs.base());
	};

	template <class Iterator>
	bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return ( lhs.base() < rhs.base());
	};

	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return ( lhs.base() <= rhs.base());
	};

	template <class Iterator>
	bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return ( lhs.base() > rhs.base());
	};

	template <class Iterator>
	bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return ( lhs.base() >= rhs.base());
	};*/

	template <class Iterator>
	reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it) {
		return ( reverse_iterator<Iterator>(rev_it.base() - n));
	};

	template <class Iterator1, class Iterator2>
	typename reverse_iterator<Iterator1>::difference_type operator- (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs){
		return ( rhs.base() - lhs.base());
	};

	/*template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
		return ( lhs.base() - rhs.base());
	};*/

}

#endif