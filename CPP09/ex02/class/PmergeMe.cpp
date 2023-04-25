
#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(char **str, int size) {
	_expression = str;
	_size = size;
	create_stacks();
	validator();
}

PmergeMe::~PmergeMe() {
}

PmergeMe::PmergeMe(const PmergeMe &copy) {
	*this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &op) {
	if (this == &op)
		return (*this);
	_expression = op.get_expression();
	create_stacks();
	validator();
	return (*this);
}

char **PmergeMe::get_expression(void) const {
	return (_expression);
}

void PmergeMe::create_stacks(void) {

	for (int i = 1; i < _size; i++) {
		_vector.push_back(convert(_expression[i]));
		_list.push_back(convert(_expression[i]));
	}
}

void PmergeMe::validator (void){
	if (_list.size() < 1)
		throw std::runtime_error("Not enough values");
	std::list<int> tmp(_list);
	tmp.sort();
	tmp.unique();
	if (tmp.end() != std::unique(tmp.begin(), tmp.end())) {
		throw std::runtime_error("List contains duplicate elements.");
	}
}

void PmergeMe::print() {
	std::vector<int> tempVector(_vector);
	for (size_t i = 0; i < tempVector.size(); i++) { 
		std::cout << tempVector[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::sorted_list(void) {
	mergeInsertionSort(_list, _list.begin(), --_list.end());
}

void PmergeMe::sorted_vector(void) {
	mergeInsertionSort(_vector, 0, _vector.size() - 1);
}


int convert(std::string str) {
	int value;

	std::istringstream ss(str);
	ss >> value;
	if (ss.fail()){
		std::cout << str << std::endl;
		throw std::runtime_error("Invalid conversion");
	}
	if (value < 0)
		throw std::runtime_error("Negative value");
	return (value);
}
