#include "Data.hpp"


Data::Data(/* args */)
{
	Data::parse("data.csv");
}

Data::~Data()
{
}

Data::Data(const Data &copy)
{
	*this = copy;
}

Data &Data::operator=(const Data &op)
{
	if (this != &op)
	{
		this->data = op.data;
	}
	return (*this);
}

bool Data::validate_date(std::string date) {
	year = std::stoi(date.substr(0, 4));
	month = std::stoi(date.substr(5, 2));
	day = std::stoi(date.substr(8, 2));
	if (date.size() != 10)
		return (false);
	else {
		std::tm date;
		std::time_t t = std::mktime(&date);
		if (t == -1)
			return (false);
		return (true);
	}
}

void Data::parse(std::string file) {
	std::string		line;
	std::ifstream	file(file);
	if (!file.is_open()) {
		throw std::runtime_error("Could not open file");
    }
	std::string line;
	std::getline(file, line);
	if(!line.equal("date,exchange_rate"))
		throw std::runtime_error("Invalid file format");
	while (std::getline(file, line)) {
		std::string date = line.substr(0, line.find(','));
		std::string rate = line.substr(line.find(',') + 1);
		if (date.empty() || rate.empty())
			throw std::runtime_error("Invalid file format");
		if (validate_date(date) == false)
			throw std::runtime_error("Invalid date format");
		this->data.inset(date, std::stod(rate));
	}
}