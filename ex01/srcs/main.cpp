#include "colors.h"
#include "Span.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <map>

std::vector<int> generate_vector_src()
{
	std::vector<int> v;
	srand(time(NULL));
	for (int i = 0; i < 15000; i++)
	{
		v.push_back(rand() % 100000);
	}
	return v;
}

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
	std::cout << BCYN << "TEST SUCCESS FILLSPAN " << RES << std::endl;
	std::vector<int> v = generate_vector_src();
	Span sp = Span(150);
	try
	{
		__attribute__((unused)) int unused = sp.shortestSpan();
		std::cout << BRED << "ERROR: No exception on empty Span"
				  << RES << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << BYEL << "EXPECTED: Exception caught:" << RES << std::endl;
		std::cout << BYEL << e.what() << RES << std::endl;
	}
	sp.fillSpan((v.begin() + 12), (v.begin() + 34));
	std::cout << BGRN << "AFTER filling, shortest:" << sp.shortestSpan()
			  << RES << std::endl;
	std::cout << BGRN << "AFTER filling, longest:" << sp.longestSpan()
			  << RES << std::endl;
	std::cout << BBLU << "expected size 22 : " << sp.get_size() << RES << std::endl;
	Span sp1 = Span(15000);
	sp1.fillSpan(v.begin(), v.end());
	std::cout << BGRN << "AFTER filling, shortest:" << sp1.shortestSpan()
			  << RES << std::endl;
	std::cout << BGRN << "AFTER filling, longest:" << sp1.longestSpan()
			  << RES << std::endl;
	std::cout << BBLU << "expected size 15000 : " << sp1.get_size() << RES << std::endl;
	std::cout << BCYN << "TEST FULL ARRAY EXCEPTION IN FILLSPAN " << RES << std::endl;
	Span sp2(200);
	try
	{
		sp2.fillSpan(v.begin(), v.end());
	}
	catch (const std::exception &e)
	{
		std::cout << BYEL << "EXPECTED: Exception caught:" << RES << std::endl;
		std::cout << BRED << e.what() << RES << std::endl;
	}
}