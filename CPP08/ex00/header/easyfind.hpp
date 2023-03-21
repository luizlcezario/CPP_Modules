
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <list>
# include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& a, int b) {
	typename T::iterator it = std::find(a.begin(), a.end(), b);
	if (it == a.end()) {
		throw std::runtime_error("Value not found in container");
	}
	return it;
}

#endif