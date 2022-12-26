#include "colors.h"
#include "Span.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <map>

int main()
{
	std::cout << BCYN << "=================MAIN DU SUJET====================" << RES << std::endl;
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << BBLU << "expected result is 2: " << RES << std::endl;
		std::cout << BGRN << "shortest span: " << sp.shortestSpan() << RES << std::endl;
		std::cout << BBLU << "expected result is 14: " << RES << std::endl;
		std::cout << BGRN << "longest span: " << sp.longestSpan() << RES << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << BRED << e.what() << RES << std::endl;
	}
	std::cout << BCYN << "=========== TEST ARRAY FULL EXCEPTION ============" << RES << std::endl;
	try
	{
		Span sp = Span(3);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
	}
	catch (const std::exception &e)
	{
		std::cout << BYEL << "Exception caught:" << RES << std::endl;
		std::cout << BRED << e.what() << RES << std::endl;
	}
	std::cout << BCYN << "TEST NO SPAN POSSIBLE EXCEPTION IN SHORTESTSPAN " << RES << std::endl;
	try
	{
		Span sp = Span(1);
		sp.addNumber(6);
		sp.shortestSpan();
	}
	catch (const std::exception &e)
	{
		std::cout << BYEL << "Exception caught:" << RES << std::endl;
		std::cout << BRED << e.what() << RES << std::endl;
	}
	std::cout << BCYN << "TEST NO SPAN POSSIBLE EXCEPTION IN LONGESTSPAN " << RES << std::endl;
	try
	{
		Span sp = Span(1);
		sp.addNumber(6);
		sp.longestSpan();
	}
	catch (const std::exception &e)
	{
		std::cout << BYEL << "Exception caught:" << RES << std::endl;
		std::cout << BRED << e.what() << RES << std::endl;
	}
}