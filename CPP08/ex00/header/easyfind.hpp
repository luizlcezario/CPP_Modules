
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <vector>
# include <algorithm>
# include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& a, int b) {
	typename T::iterator it = std::find(a.begin(), a.end(), b);
	if (it == a.end() && *it != b) {
		throw std::runtime_error("Value not found in container");
	}
	return it;
}

#endif