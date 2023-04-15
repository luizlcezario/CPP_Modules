#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main( void ) {
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);
	vec.push_back(60);
	vec.push_back(70);
	 std::vector<int>::iterator it;
	try {
		it = easyfind(vec, 10);
		std::cout << "search the first:" << *it << std::endl;
		it = easyfind(vec, 70);
		std::cout << "search the lasts:" << *it << std::endl;
		it = easyfind(vec, 40);
		std::cout << "search the other:" << *it << std::endl;
		it = easyfind(vec, 45);
		std::cout << "search the error:" << *it << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
    return 0;
}