#ifndef _MUTANTSTACK_HPP
#define _MUTANTSTACK_HPP

#include <stack>
#include <iostream>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
//______________Constructors an destructor_________________________________
		
		MutantStack<T>(): std::stack<T>() {}
		MutantStack<T>(MutantStack<T> const &cpy) : std::stack<T>(cpy) {}
		~MutantStack<T>(void) {}

//______________Operator overload___________________________________________

		MutantStack<T> &operator=(MutantStack<T> const &rhs)
		{
			this->std::stack<T>::operator=(rhs);
			return *this;
		}

//______________Members functions___________________________________________

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin()
		{
			return this->c.begin();
		}

		iterator end()
		{
			return this->c.end();
		}

	private:
};

#endif