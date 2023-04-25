#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include "Data.hpp"
# include <cstdlib> 
# include <stdlib.h> 

class BitcoinExchange
{
private:
	Data			data;
	std::ifstream	file;
public:
	BitcoinExchange(/* args */);
	explicit BitcoinExchange(std::string filename);
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange &operator=(const BitcoinExchange &op);

	double convert(std::string date, double value);
	void print_all_conversions(void);
};



#endif