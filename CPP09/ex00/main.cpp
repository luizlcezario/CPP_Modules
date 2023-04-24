# include "Data.hpp"
int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: ./ex00 [filename]" << std::endl;
		return 1;
	}
	try {
		Data data;
		(void ) argv;
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
		return 1;
	}
}