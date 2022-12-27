#include "colors.h"
#include "Span.hpp"
#include <algorithm>
#include <iterator>

#define MAX_ELEM std::max_element(this->_span.begin(), this->_span.end())
#define MIN_ELEM std::min_element(this->_span.begin(), this->_span.end())

// constructs ans destruct======================================================
//=============================================================================

// Default construct in private field
Span::Span(void) : _max(0) {}

Span::Span(unsigned int max) : _max(max)
{
	std::cout << BWHT << " Constructor overload called." << RES << std::endl;
	return;
}

Span::Span(Span const &cpy) : _max(cpy._max), _span(cpy._span)
{
	std::cout << BWHT << " Copy constructor called." << RES << std::endl;
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
	if (this != &rhs)
	{
		this->_span = rhs._span;
		this->_max = rhs._max;
	}
	return (*this);
}

// accessors ==================================================================
//=============================================================================

unsigned int Span::get_max() const
{
	return this->_max;
}

unsigned int Span::get_size() const
{
	return this->_span.size();
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
	if (this->_span.size() < this->_max)
		this->_span.push_back(n);
	else
		throw FullArray();
}

int Span::shortestSpan()
{
	if (this->_span.size() <= 1)
		throw NoSpanPossible();
	else
	{
		std::sort(this->_span.begin(), this->_span.end());
		std::vector<int>::iterator i = this->_span.begin();
		std::vector<int>::iterator j = this->_span.begin() + 1;
		int result = this->longestSpan();
		int test = 0;
		while (j != this->_span.end())
		{
			test = *j - *i;
			if (result > test)
				result = test;
			i++;
			j++;
		}
		return result;
	}
}

int Span::longestSpan()
{
	if (this->_span.size() > 1)
		return *MAX_ELEM - *MIN_ELEM;
	else
		throw NoSpanPossible();
}

void Span::fillSpan(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (this->_span.size() + std::distance(begin, end) > this->_max)
		throw FullArray();
	this->_span.insert(this->_span.begin(), begin, end);
}

void Span::printSpan()
{
	for (long unsigned int i = 0; i < this->_span.size(); i++)
		std::cout << BWHT << this->_span[i] << RES << std::endl;
}