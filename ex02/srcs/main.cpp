#include "colors.h"
#include "MutantStack.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <map>

int main()
{
	{
		std::cout << BCYN << "MAIN DU SUJET" << RES << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.pop();
		std::cout << BWHT << "top: " << mstack.top() << std::endl;
		std::cout << BWHT << "stack size before push: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		std::cout << BWHT << "stack size AFTER push: " << mstack.size() << std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		std::cout << BWHT << "begin: " << *it << std::endl;
		MutantStack<int>::iterator ite = mstack.end();
		std::cout << BWHT << "last: " << *(--mstack.end()) << std::endl;
		++it;
		if (it == mstack.begin())
			std::cout << BRED << "Iterator should no longer be equal to begin after ++: "
					  << *it << RES << std::endl;
		--it;
		if (it != mstack.begin())
			std::cout << BRED << "Iterator should be equal to begin after --: "
					  << *it << RES << std::endl;
		std::cout << BWHT << "iterator iterate : " << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::cout << BWHT << "stack's copy constructor with mstack: " << RES << std::endl;
		std::stack<int> s(mstack);
		std::cout << BWHT "copy stack size: " << s.size() << std::endl
				  << "copy stack top: "
				  << s.top() << RES << std::endl;
		std::cout << BWHT << "poping until s is empty in order to compare with mstack: " << std::endl;
		while (!s.empty())
		{
			std::cout << BWHT << s.top() << RES << std::endl;
			s.pop();
		}
		std::cout << BWHT << "testing reverse (rbegin): " << RES << std::endl;
		for (MutantStack<int>::reverse_iterator i = mstack.rbegin(); i != mstack.rend(); i++)
		{
			std::cout << BWHT << *i << RES << std::endl;
		}
	}
	{
		std::cout << BCYN << "SAME TEST BUT WITH LIST" << RES << std::endl;
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		mstack.pop_back();
		std::cout << BWHT << "back: " << mstack.back() << std::endl;
		std::cout << BWHT << "list size before push_back: " << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);
		std::cout << BWHT << "list size AFTER push_back: " << mstack.size() << std::endl;
		std::list<int>::iterator it = mstack.begin();
		std::cout << BWHT << "begin: " << *it << std::endl;
		std::list<int>::iterator ite = mstack.end();
		std::cout << BWHT << "last: " << *(--mstack.end()) << std::endl;
		++it;
		--it;
		std::cout << BWHT << "iterator iterate : " << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << BWHT << "testing reverse (rbegin): " << RES << std::endl;
		for (std::list<int>::reverse_iterator i = mstack.rbegin(); i != mstack.rend(); i++)
		{
			std::cout << BWHT << *i << RES << std::endl;
		}
	}
}