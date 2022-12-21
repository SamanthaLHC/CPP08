#ifndef _SPAN_HPP
#define _SPAN_HPP

#include <algorithm>
#include <iostream>


class Span
{
	public:
//______________Constructors an destructor_________________________________
		
		Span(unsigned int const max);
		Span(Span const &cpy);
		~Span(void);

//______________Operator overload___________________________________________

		Span &operator=(Span const &rhs);

//______________Accessors__________________________________________________

		unsigned int get_max() const;

//______________Exceptions__________________________________________________

		class FullArray: public std::exception
		{
			const char *what () const throw ();
		};

		class NoSpanPossible: public std::exception
		{
			const char *what () const throw ();
		}; 

//______________Members functions___________________________________________

		void addNumber(unsigned int n);
		unsigned int const shortestSpan();
		unsigned int const longestSpan();

	private:

		Span(void);
		unsigned int const	_max;

};

#endif