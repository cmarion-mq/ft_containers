#ifndef PAIR_HPP
# define PAIR_HPP

#include <iostream>

namespace ft {
	template <class T1, class T2>
	struct pair{
		typedef	T1	first_type;
		typedef	T2	second_type;

/*--- CON/DE_STRUCTORS ---*/	
		pair(): first(first_type()), second(second_type())
		{};

		pair (const first_type &a, const second_type &b): first(a), second(b)
		{};

/*---   MEMBER FONCTION  ---*/
		pair &operator =(const pair& pr) {
			if (this != &x) {
				first = pr.first;
				second = pr.second;
			}
			return (*this);
		}

/*---   MEMBER OBJECTS  ---*/
		first_type	first;
		second_type	second:
	};


/*############ NON MEMBER FONCTION ############*/
/*---   MAKE_PAIR   ---*/
	template <class T1, class T2>
	pair<T1,T2> make_pair(T1 x, T2 y){
		return ( pair<T1,T2>(x,y) );
	};

/*---   OPERATORS   ---*/
	template< class T1, class T2 >
	bool operator ==(const std::pair<T1, T2>& lhs, const std::pair<T1, T2>& rhs) {
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	};

	template< class T1, class T2 >
	bool operator !=( const std::pair<T1, T2>& lhs, const std::pair<T1, T2>& rhs ) {
		return !(lhs == rhs);
	};

	template< class T1, class T2 >
	bool operator <( const std::pair<T1, T2>& lhs, const std::pair<T1, T2>& rhs ) {
		if (lhs.first == rhs.first)
			return (lhs.second < rhs.second);
		else 
			return (lhs.first < rhs.first);
	};

	template< class T1, class T2 >
	bool operator <=( const std::pair<T1, T2>& lhs, const std::pair<T1, T2>& rhs ) {
		if (lhs.first == rhs.first)
			return (lhs.second <= rhs.second);
		else 
			return (lhs.first <= rhs.first);
	};

	template< class T1, class T2 >
	bool operator >( const std::pair<T1, T2>& lhs, const std::pair<T1, T2>& rhs ) {
		if (lhs.first == rhs.first)
			return (lhs.second > rhs.second);
		else 
			return (lhs.first > rhs.first);
	};

	template< class T1, class T2 >
	bool operator >=( const std::pair<T1, T2>& lhs, const std::pair<T1, T2>& rhs ) {
		if (lhs.first == rhs.first)
			return (lhs.second >= rhs.second);
		else 
			return (lhs.first >= rhs.first);
	};
}

#endif