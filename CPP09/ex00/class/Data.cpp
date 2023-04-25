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
	(void )op;
	return (*this);
}


bool Data::validate_date(std::string date) {
	if (date.size() != 10)
		return (false);
	else {
		std::tm d = Data::create_date(date);
		std::time_t t = std::mktime(&d);
		if (t == -1)
			return (false);
		return (true);
	}
}

std::tm Data::create_date(std::string date) {
	std::tm d;
	int year; 
	Data::convert(date.substr(0, 4).c_str(), year);
	int month;
	Data::convert(date.substr(5, 2).c_str(), month);
	int day;
	Data::convert(date.substr(8, 2).c_str(), day);
	d.tm_year = year - 1900;
	d.tm_mon = month - 1;
	d.tm_mday = day;
	return (d);
}

void Data::parse(std::string fd) {
	std::string		line;
	std::ifstream	file(fd.c_str());

	if (!file.is_open()) {
		throw std::runtime_error("Could not open file");
	}
	std::getline(file, line);
	if(line != "date,exchange_rate")
		throw std::runtime_error("Invalid file format");
	while (std::getline(file, line)) {
		std::string date = line.substr(0, line.find(','));
		std::string rate = line.substr(line.find(',') + 1);
		if (date.empty() || rate.empty())
			throw std::runtime_error("Invalid file format");
		if (validate_date(date) == false)
			throw std::runtime_error("Invalid date format");
		float r;
		this->data.insert(std::make_pair(date, Data::convert(rate, r)));
	}
}

float Data::get_value(std::string date) {
	if (this->data.find(date) == this->data.end())
		throw std::runtime_error("Date not found");
	return (this->data[date]);
}

std::map<std::string, float> Data::get_data(void){
	return (this->data);
}