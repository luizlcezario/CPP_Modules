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

void parse(std::string file) {
	std::ifstream file(file);
	if (!file.is_open()) {
		throw std::runtime_error("Could not open file");
    }
	std::string line;
	std::getline(file, line);
	if(!line.equal("date,exchange_rate"))
}