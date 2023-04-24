#ifndef DATA_HPP
#define DATA_HPP

# include <ctime>
# include <iostream>
# include <string>
# include <map>

class Data
{
private:
	std::map<std::string, double> data;
	void parse(std::string filename);
	static bool validate_date(std::string date);
public:
	Data(/* args */);
	~Data();
	Data(const Data &copy);
	Data &operator=(const Data &op);
	double get_value(std::string date);
	std::map<std::string, double> get_data();
	std::string get_date(double value);
};
#endif