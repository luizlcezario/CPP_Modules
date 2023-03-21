#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <stdexcept>

class Span
{
private:
	unsigned int _N;
	unsigned int _size;
	std::vector<int> *_array;
public:
	Span();
	explicit Span(unsigned int N);
	~Span();
	Span(const Span &copy);
	Span &operator=(const Span &copy);

	std::vector<int> *getArray() const;
	int size()	const;

	int shortestSpan();
	int longestSpan();
	void addNumber(int n);
	template <typename Titer>
	void addNumber(Titer begin, Titer end) {
		 if (std::distance(begin, end) > _N - _size) {
			throw std::runtime_error("Not enough space in Span to add all numbers");
		}
		_array->insert(_array->end(), begin, end);
		_size = _array->size();
	};
};

#endif