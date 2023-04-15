# include "MutantStack.hpp"
# include <list>
int main()
{
	std::cout << "MutantStack<int> mstack;" << std::endl;
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
	std::cout << "MutantStack<int>::iterator it = mstack.begin();" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "list<int> mstack;" << std::endl;
	std::list<int> listt;
	listt.push_back(5);
	listt.push_back(17);
	std::cout << listt.front() << std::endl;
	listt.pop_front();
	std::cout << listt.size() << std::endl;
	listt.push_back(3);
	listt.push_back(5);
	listt.push_back(737);
	listt.push_back(0);
	std::list<int>::iterator it2 = listt.begin();
	std::list<int>::iterator ite2 = listt.end();
	++it2;
	--it2;
	std::cout << "MutantStack<int>::iterator it = mstack.begin();" << std::endl;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	std::list<int> s2(listt);
	return 0;
}
