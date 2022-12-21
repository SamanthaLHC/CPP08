#include "colors.h"
#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <map>


template<typename T>
void test()
{
	T cont;
	cont.push_back(3);
	cont.push_back(16);
	cont.push_back(8);
	cont.push_back(8);
	std::cout << BBLU << "should be a success" << RES << std::endl;
	if (easyfind(cont, 8) != cont.end())
		std::cout << BGRN << "success" << RES << std::endl;
	if (&(*easyfind(cont, 8)) != &(*std::find(cont.rbegin(), cont.rend(), 8)))
		std::cout << BGRN << "Easyfind and reversed find found != iterators" << RES << std::endl;
	std::cout << BBLU << "should be failed" << RES << std::endl;
	easyfind(cont, 15);
}

int main()
{

	std::cout << BCYN << "__________CHECK WITH VECTOR_______" << RES << std::endl;
	test<std::vector<int> >();

	std::cout << BCYN << "__________CHECK WITH LIST_______" << RES << std::endl;
	test<std::list<int> >();
}