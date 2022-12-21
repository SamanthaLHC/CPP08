#include "colors.h"
#include "span.hpp"

// constructs ans destruct======================================================
//=============================================================================

Span::Span(void) :
{
	std::cout << BWHT << this->_name << " Default constructor." << RES << std::endl;
	return;
}

Span::Span(unsigned int const max) : _max(max)
{

	std::cout << BWHT << this->_name << " Constructor overload called." << RES << std::endl;
	return;
}

Span::Span(Span const &cpy) : _name(cpy._name)
{
	std::cout << BWHT << this->_name << " Copy constructor called." << RES << std::endl;
	*this = cpy;
}

Span::~Span(void)
{
	std::cout << BWHT << this->_name << " Destructor called" << RES << std::endl;
	return;
}

// operator overload===========================================================
//=============================================================================

Span &Span::operator=(Span const &rhs)
{
	if (this != &rhs)
		this->_grade = rhs._grade;
	return (*this);
}

std::ostream &operator<<(std::ostream &out_stream, Span const &input)
{
	out_stream << BMAG << input.get_name() << ", Spane grade "
			   << input.get_grade() << RES;
	return out_stream;
}

// accessors ==================================================================
//=============================================================================

std::string Span::get_name() const
{
	return this->_name;
}

unsigned int Span::get_grade() const
{
	return this->_grade;
}

// Exceptions handler =========================================================
//=============================================================================

const char *Span::GradeTooHighException::what() const throw()
{
	return "Grade range error: way too high.";
}

const char *Span::GradeTooLowException::what() const throw()
{
	return "Grade range error: way too low.";
}

// members functions ==========================================================
//=============================================================================

// promotion_grade() and demotion_grade() should be use in try/ catch scope in order
// to avoid crash (because of the throw here)

void Span::promotion_grade(void)
{
	if (this->_grade <= 1 || ((this->_grade -= 1) <= 1))
		throw GradeTooHighException();
}

void Span::demotion_grade(void)
{
	if (this->_grade >= 150 || ((this->_grade += 1) >= 150))
		throw GradeTooLowException();
}

void Span::sign_form(AForm &form_to_sign)
{
	try
	{
		form_to_sign.be_signed(*this);
		std::cout << BYEL << this->_name << " signed " << form_to_sign.get_name()
				  << RES << std::endl;
	}
	catch (const std::exception &err)
	{
		std::cerr << BRED << this->_name << " couldn't sign " << form_to_sign.get_name()
				  << " because: " << err.what() << std::endl;
	}
}

void Span::execute_form(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << BYEL << this->_name << " executed " << form.get_name()
				  << RES << std::endl;
	}
	catch (const std::exception &err)
	{
		std::cerr << BRED << this->_name << " couldn't execute " << form.get_name()
				  << " because: " << err.what() << std::endl;
	}
}