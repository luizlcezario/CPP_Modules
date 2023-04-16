# include "MutantStack.hpp"
# include <list>
int main()
{
	std::cout << "MutantStack" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "List Stack" << std::endl;
	std::list<int> tstack;
	tstack.push_back(5);
	tstack.push_back(17);
	std::cout << tstack.back() << std::endl;
	tstack.pop_back();
	std::cout << tstack.size() << std::endl;
	tstack.push_back(3);
	tstack.push_back(5);
	tstack.push_back(737);
	tstack.push_back(0);
	std::list<int>::iterator it1 = tstack.begin();
	std::list<int>::iterator ite2 = tstack.end();
	++it1;
	--it1;
	while (it1 != ite2)
	{
		std::cout << *it1 << std::endl;
		++it1;
	}
	std::list<int> l(tstack);
	return 0;
}
