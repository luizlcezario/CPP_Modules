

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>


template <typename T>
T const & max(T const & a, T const & b) {
	return (a > b ? a : b);
}

template <typename T>
T const & min(T const & a, T const & b) {
	return (a < b ? a : b);
}

template <typename T>
void swap(T & a, T & b) {
	T tmp = a;
	a = b;
	b = tmp;
}

#endif