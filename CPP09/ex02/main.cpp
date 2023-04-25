
# include "PmergeMe.hpp"
#include <sys/time.h>
int main(int argc, char **argv) {
	if (argc < 2 && argc > 3002) {
		std::cout << "Usage: ./ex02 2 3 4 6 5 .." << std::endl << "with maximum 3000 numbers" << std::endl;
		return 1;
	}
	try {
		PmergeMe pmergeMe(argv, argc);
		pmergeMe.print();
		clock_t start = clock();
		pmergeMe.sorted_vector();
		clock_t end = clock();
		pmergeMe.print();
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << (double)(end - start) << " us" << std::endl; 
		start = clock();
		pmergeMe.sorted_list();
		end = clock();
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::list : " << (double)(end - start) << " us" << std::endl; 
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
		return 1;
	}

	return 0;
}