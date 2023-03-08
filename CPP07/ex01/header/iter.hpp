

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>


template <typename T>
void iter(T *array, size_t length, void (*f)(T const &)) {
	for (size_t i = 0; i < length; i++) {
		f(array[i]);
	}
}

template <typename T>
void	print(T const & x) {
	std::cout << x << std::endl;
}
template <typename T>
void	even(T & x) {
	if (x % 2 == 0) {
		std::cout << "even" << std::endl;
	} else {
		std::cout << "odd" << std::endl;
	}
}

#endif