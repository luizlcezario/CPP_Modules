#ifndef DATA_HPP
#define DATA_HPP

# include <ctime>
# include <fstream>
# include <iostream>
# include <string>
# include <map>
#include <sstream>

class Data
{
private:
	std::map<std::string, float> data;
	void parse(std::string filename);
public:
	Data(/* args */);
	~Data();
	Data(const Data &copy);
	Data &operator=(const Data &op);
	float get_value(std::string date);
	std::map<std::string, float> get_data(void);
	static bool validate_date(std::string date);
	static std::tm create_date(std::string date);
	template <typename T>
	static T convert(std::string str, T &value) {
		std::istringstream ss(str);
		ss >> value;
		if (ss.fail())
			throw std::runtime_error("Invalid conversion");
		return (value);
	}
};
#endif