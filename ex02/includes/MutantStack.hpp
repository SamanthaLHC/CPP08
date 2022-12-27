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
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin()
		{
			return this->c.begin();
		}

		iterator end()
		{
			return this->c.end();
		}

		const_iterator begin() const
		{
			return this->c.begin();
		}

		const_iterator end() const
		{
			return this->c.end();
		}

		reverse_iterator rbegin()
		{
			return this->c.rbegin();
		}

		reverse_iterator rend()
		{
			return this->c.rend();
		}

		const_reverse_iterator rbegin() const
		{
			return this->c.rbegin();
		}

		const_reverse_iterator rend() const
		{
			return this->c.rend();
		}

	private:
};

#endif