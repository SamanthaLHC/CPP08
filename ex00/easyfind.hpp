#ifndef _EASYFIND_HPP
#define _EASYFIND_HPP

#include <algorithm>
#include <iostream>

template<typename T>
typename T::iterator easyfind(T& container_type, unsigned int n)
{

	typename T::iterator ret = std::find(container_type.begin(), container_type.end(), n);
	if (ret == container_type.end())
	{
		std::cout << BRED << "No occurence found." << RES << std::endl; 
		return ret;
	}
	return ret;
}

#endif