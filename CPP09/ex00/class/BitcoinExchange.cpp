
#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(std::string filename) 
{
	this->file.open(filename.c_str());
	if (!this->file.is_open())
		throw std::runtime_error("Could not open file");
}

BitcoinExchange::~BitcoinExchange()
{
	if (this->file.is_open())
		this->file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &op)
{
	(void )op;
	return (*this);
}

void BitcoinExchange::print_all_conversions(void) {
	std::string	line;
	float		value;

	std::getline(this->file, line);
	if (line != "date | value")
		throw std::runtime_error("Invalid header format.");
	while (std::getline(this->file, line)) {
		try {
			std::string date = line.substr(0, line.find(" | "));
			std::string rate = line.substr(line.find(" | ") + 3);
			value = Data::convert(rate, value);
			if (date.empty() || rate.empty() || line.find(" | ") == (size_t)-1)
				throw std::runtime_error("bad input => " + line);
			else if (Data::validate_date(date) == false)
				throw std::runtime_error("bad input => " + line);
			else if (value < 0)
				throw std::runtime_error("not a positive number.");
			else if (value > 1000)
				throw std::runtime_error("too large a number.");
			value = this->convert(date, value);
			std::cout << date << " => " << rate << " = " << value << std::endl;
		} catch (std::exception &e) {
			std::cout << "Error: "<< e.what() << std::endl;
		}
		
	}
}


double BitcoinExchange::convert(std::string date, double value)
{
	float final_value = 0;

	try {
		final_value = this->data.get_value(date);
	} catch (std::exception &e) {
		if (date < this->data.get_data().begin()->first)
			throw std::runtime_error("Date is too early.");
		std::map<std::string, float>::iterator it = this->data.get_data().upper_bound(date);
		it--;
		final_value = it->second;
	}
	return (value * final_value);
}