#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace ft {
	template <class Iterator>
	class reverse_iterator : public iterator <	typename iterator_traits<Iterator>::iterator_category,
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
			reverse_iterator (const reverse_iterator<Iter>& rev_it) _current(rev_it.base()) {};

/*---       BASE       ---*/
			iterator_type base() const;

/*---     OPERATORS    ---*/
			reference operator*() const {
				iterator_type	temp = -- _current;
				return *temp; 
			};

			reverse_iterator operator+ (difference_type n) const {
				iterator_type	temp = _current - n - 1;
				return temp;
			};

			pointer
			operator->() const;
			reverse_iterator&
			reverse_iterator
			reverse_iterator&
			reverse_iterator
			operator++();
			operator++(int);
			operator--();
			operator--(int);
			reverse_iterator& operator+=(difference_type n);
			reverse_iterator operator- (difference_type n) const;
			reverse_iterator& operator-=(difference_type n);
			reference operator[](difference_type n) const;
		
		protected:
			Iterator _current;
    };
}

#endif