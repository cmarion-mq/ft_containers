#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft {
	template <class T, class Container = vector<T> >
	class stack
	{
		public:
/*-------- TYPES ---------*/
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

/*--- CON/DE_STRUCTORS ---*/
			explicit stack (const container_type& ctnr = container_type()): _c(ctnr)
			{};

			~stack() {};

/*---     CAPACITY     ---*/
			bool 		empty()	const 	{ return (_c.empty()); };
			size_type 	size()	const	{ return (_c.size()); };

/*---  ELEMENT ACCESS  ---*/
			value_type			&top()			{ return (_c.back()); };
			const value_type	&top() const	{ return (_c.back()); };
			
/*---     MODIFIERS    ---*/
			void push (const value_type& val)		{ _c.push_back(val); };
			void pop()								{ _c.pop_back(); };

/*---     FRIENDS    ---*/
			template <class _T, class _Container>
			friend bool operator == (const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs);

			template <class _T, class _Container>
			friend bool operator < (const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs);
		
		protected:
			container_type	_c;
	};

	template <class T, class Container>
	bool operator == (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._c == rhs._c);
	};

	template <class T, class Container>
	bool operator != (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return !(lhs == rhs);
	};

	template <class T, class Container>
	bool operator <  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._c < rhs._c);
	};

	template <class T, class Container>
	bool operator <= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return !(rhs < lhs);
	};

	template <class T, class Container>
	bool operator >  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (rhs < lhs);
	};

	template <class T, class Container>
	bool operator >= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return !(lhs < rhs);
	};
}

#endif