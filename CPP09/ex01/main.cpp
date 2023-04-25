
#include <iostream>
#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: ./ex01 \"expression in Reverse Polish Notation \"" << std::endl;
		return 1;
	}
	try {
		RPN rpn(argv[1]);
		std::cout << rpn.calculate() << std::endl;
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
		return 1;
	}

	return 0;
}