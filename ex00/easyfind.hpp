#ifndef _EASYFIND_HPP
#define _EASYFIND_HPP

#include <iostream>
#include <algorithm>

template<typename T>
void easyfind(T& container_type, unsigned int n)
{
	std::find(container_type.begin(), container_type.end(), n)
}

#endif