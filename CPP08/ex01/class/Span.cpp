# include "Span.hpp"

Span::Span() : _N(0), _size(0), _array(NULL) {}

Span::Span(unsigned int N) : _N(N), _size(0) {
	_array = new std::vector<int>();
}

Span::~Span() {
	delete _array;
}

Span::Span(const Span &copy) {
	*this = copy;
}

Span &Span::operator=(const Span &copy) {
	if (this != &copy) {
		delete _array;
		_N = copy._N;
		_size = copy._size;
		_array = new std::vector<int>(*copy.getArray());
	}
	return *this;
}

int Span::size() const {
	return (int)_size;
}

std::vector<int> *Span::getArray() const {
	return _array;
}

void Span::addNumber(int n) {
	if (_size == _N) {
		throw std::runtime_error("Span is full");
	}
	_array->push_back(n);
	_size++;
}

int Span::shortestSpan() {
	if (_size < 2) {
		throw std::runtime_error("Span is too small");
	}
	int shortest = 2147483647;
	std::vector<int> sorted(*this->_array);
	std::sort(sorted.begin(), sorted.end());
	 for (unsigned int i = 1; i < sorted.size(); ++i) {
            int span = std::abs(sorted[i] - sorted[i-1]);
            if (span < shortest) {
                shortest = span;
            }
	}
	return shortest;
}

int Span::longestSpan() {
	if (_array->size() < 2) {
	    throw std::runtime_error("Span is too small to find longest span");
	}
	int min_num = *std::min_element(_array->begin(), _array->end());
	int max_num = *std::max_element(_array->begin(), _array->end());
	return max_num - min_num;
}
