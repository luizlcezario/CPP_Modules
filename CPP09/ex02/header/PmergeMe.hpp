#ifndef PMERGEME_HPP
# define PMERGEME_HPP


#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
# include <algorithm>

class PmergeMe
{
private:
	std::vector<int> _vector;
	std::list <int> _list;
	char **_expression;
	int _size;
public:
	PmergeMe();
	explicit PmergeMe(char **str, int size);
	~PmergeMe();
	PmergeMe(const PmergeMe &copy);
	PmergeMe &operator=(const PmergeMe &op);
	char **get_expression(void) const;
	void create_stacks(void);
	void validator(void);
	void print(void);
	void sorted_vector(void);
	void sorted_list(void);
};

void mergeInsertionSort(std::vector<int>& v, int left, int right);
void mergeInsertionSort(std::list<int>& lst, std::list<int>::iterator left, std::list<int>::iterator right);
int convert(std::string str) ;

#endif