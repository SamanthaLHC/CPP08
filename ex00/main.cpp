#include "colors.h"
#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <map>

int main()
{

	std::cout << BCYN << "__________CHECK WITH VECTOR_______" << RES << std::endl;
	std::vector<int> v_arr;
	v_arr.push_back(3);
	v_arr.push_back(16);
	v_arr.push_back(8);
	v_arr.push_back(8);
	std::cout << BBLU << "should be a success" << RES << std::endl;
	if (easyfind(v_arr, 8) != v_arr.end())
		std::cout << BGRN << "success" << RES << std::endl;
	if (&(*easyfind(v_arr, 8)) != &(*std::find(v_arr.rbegin(), v_arr.rend(), 8)))
		std::cout << BGRN << "Easyfind and reversed find found != iterators" << RES << std::endl;
	std::cout << BBLU << "should be failed" << RES << std::endl;
	easyfind(v_arr, 15);

	std::cout << BCYN << "__________CHECK WITH LIST_______" << RES << std::endl;
	std::list<int> list_arr;
	list_arr.push_back(3);
	list_arr.push_back(17);
	list_arr.push_back(3);
	list_arr.push_back(8);
	std::cout << BBLU << "should be a success" << RES << std::endl;
	if (easyfind(list_arr, 3) != list_arr.end())
		std::cout << BGRN << "success" << RES << std::endl;
	if (&(*easyfind(list_arr, 3)) != &(*std::find(list_arr.rbegin(), list_arr.rend(), 3)))
		std::cout << BGRN << "Easyfind and reversed find found != iterators" << RES << std::endl;
	std::cout << BBLU << "should be failed" << RES << std::endl;
	easyfind(list_arr, 15);

	std::cout << BCYN << "__________CHECK WITH MAP_______" << RES << std::endl;
	std::map<int, int> m_arr;
	m_arr.insert(8, 9);
	m_arr.insert(4, 3);
	if (easyfind(m_arr, 3) != m_arr.end())
		std::cout << BGRN << "success" << RES << std::endl;
	std::cout << BBLU << "should be failed" << RES << std::endl;
	easyfind(m_arr, 15);

}