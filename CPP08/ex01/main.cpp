# include "Span.hpp"
#include <cassert>

#define assertm(exp, msg) assert(((void)msg, exp))
int main( void ) {

	std::cout << "Test simple" << std::endl;

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std:: cout << sp.shortestSpan() << std::endl;
	assertm(sp.shortestSpan() == 2, "error shortestSpan need to be 2" );
	std:: cout << sp.longestSpan() << std::endl;
	assertm(sp.longestSpan() == 14, "error longestSpan need to be 14" );
	std::cout << "Test small try/catch" << std::endl;
	try {
		sp.addNumber(1);
		assertm(false , "error need to throw an exception" );
	} catch (std::exception &e) {
		assert (true);
	}

	std::cout << "Test bigger" << std::endl;
	Span span(10000);
    std::vector<int> numbers;
    for (int i = 0; i < 10000; ++i) {
        numbers.push_back(i);
    }
	span.addNumber(numbers.begin(), numbers.end());
	std:: cout << span.shortestSpan() << std::endl;
	assertm(span.shortestSpan() == 1, "error shortestSpan need to be 1" );
	std:: cout << span.longestSpan() << std::endl;
	assertm(span.longestSpan() == 9999, "error longestSpan need to be 9999" );
	std::cout << "Test bigger try/catch" << std::endl;
	try {
		span.addNumber(numbers.begin(), numbers.end());
		assertm(false , "error need to throw an exception" );
	} catch (std::exception &e) {
		assert (true);
	}
	return 0;
}