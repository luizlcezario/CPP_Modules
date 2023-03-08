
#include "iter.hpp"

int main( void ) {
	int a[9] = {50, 56, 80, 90, 103, 110, 120, 130, 14};

	::iter(a, 9, print);
	::iter(a, 9, even);
	::iter(a, 9, print);
	return 0;
}