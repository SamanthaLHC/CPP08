#include "colors.h"
#include "span.hpp"

// constructs ans destruct======================================================
//=============================================================================

Span::Span(void) :
{
	std::cout << BWHT << " Default constructor." << RES << std::endl;
	return;
}

Span::Span(unsigned int const max) : _max(max)
{

	std::cout << BWHT << " Constructor overload called." << RES << std::endl;
	return;
}

Span::Span(Span const &cpy) : _max(cpy._max)
{
	std::cout << BWHT << " Copy constructor called." << RES << std::endl;
	*this = cpy;
}

Span::~Span(void)
{
	std::cout << BWHT << " Destructor called" << RES << std::endl;
	return;
}

// operator overload===========================================================
//=============================================================================

Span &Span::operator=(Span const &rhs)
{
	return (*this);
}

// accessors ==================================================================
//=============================================================================

unsigned int Span::get_max() const
{
	return this->_max;
}

// Exceptions handler =========================================================
//=============================================================================

const char *Span::FullArray::what() const throw()
{
	return "Out of range. Array full";
}

const char *Span::NoSpanPossible::what() const throw()
{
	return "No span possible.";
}

// members functions ==========================================================
//=============================================================================

void Span::addNumber(unsigned int n)
{

}

unsigned int const Span::shortestSpan()
{

}

unsigned int const Span::longestSpan()
{

}