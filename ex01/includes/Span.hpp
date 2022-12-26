#ifndef _SPAN_HPP
#define _SPAN_HPP

#include <algorithm>
#include <iostream>
#include <vector>


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
		int shortestSpan();
		int longestSpan();
		// multiple call to addNumber with a range of iterators
		// void fillSpan(la quantité de cases à remplir, le nombre);

	private:

		Span(void);
		unsigned int		_max;
		std::vector<int>	_span;
};

#endif