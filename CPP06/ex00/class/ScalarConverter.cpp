/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:30:24 by llima-ce          #+#    #+#             */
/*   Updated: 2023/03/15 18:48:00 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string ScalarConverter::_literals = "";
e_type ScalarConverter::_type = INV;

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(ScalarConverter const &src) {
	*this = src;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs) {
	(void) rhs;
	return *this;
}

e_type	ScalarConverter::findType(std::string literals) {
	bool isNumeric[3] = {true, true, true};
	bool wasPoint = false;
	bool wasF = false;

	if (literals.length() == 0)
		return INV;
	if (!literals.compare("nan") || !literals.compare("+inf") || !literals.compare("-inf") || !literals.compare("inf"))
		return DOUBLE;
	if (!literals.compare("nanf") || !literals.compare("+inff") || !literals.compare("-inff") || !literals.compare("inff"))
		return FLOAT;
	else if (literals.length() == 3 && literals[0] == '\'' && literals[2] == '\'')
		return CHAR;
	else if (literals.length() == 1 && !isdigit(literals.c_str()[0]))
		return CHAR;
	for (int a = 0; a < (int )literals.length(); a++) {
		
		if (!isdigit(literals[a]) && !(a == 0 && (literals[a] == '-' || literals[a] == '+')))
		{
			isNumeric[0] = false;
			if ((literals[a] == '.'|| literals[a] == 'f' ))
			{
				if (literals[a] == '.' && wasPoint == false) 
					wasPoint = true;
				else if (literals[a] == 'f' && wasPoint == true && literals[a - 1] != '.'  && wasF == false) {
					isNumeric[1] = false;
					wasF = true;
				}
				else {
					isNumeric[1] = false;
					isNumeric[2] = false;
					break ;
				}
			}
			else {
				isNumeric[1] = false;
				isNumeric[2] = false;
				break;
			}
		}
	}
	return (isNumeric[0] ? INT : (isNumeric[1] ? DOUBLE : (isNumeric[2] ? FLOAT : INV)));
}

 void ScalarConverter::_print_c(char c) {
	std::cout << "char: ";
	if (_literals == "-inf" || _literals == "+inf" || _literals == "nan"
	|| _literals == "-inff" || _literals == "+inff" || _literals == "nanf")
		std::cout << "impossible" << std::endl; 
	else {
		if (isprint(c))
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
}

 void ScalarConverter::_print_i(int i) {
	std::cout << "int: ";
	if (_literals == "-inf" || _literals == "+inf" || _literals == "nan" 
	|| _literals == "-inff" || _literals == "+inff" || _literals == "nanf")
		std::cout << "impossible" << std::endl; 
	else
		std::cout << i << std::endl;
}

 void ScalarConverter::_print_d(double d) {
	std::cout.precision(2);
	std::cout << "double: ";
	std::cout << std::fixed << d << std::endl;
}

 void ScalarConverter::_print_f(float d) {
	std::cout.precision(2);
	std::cout << "float: ";
	std::cout <<std::fixed << d << "f" << std::endl;
}

 void ScalarConverter::convert(std::string literals) {
	_type = findType(literals);
	_literals = literals;
	if (_type == CHAR) {
		char	c = _literals.c_str()[0];
		if (_literals.length() == 3 && _literals.c_str()[0] == '\'' && _literals.c_str()[2] == '\'')
			c = _literals.c_str()[1];
		_print_c(c);
		_print_i(static_cast<int>(c));
		_print_f(static_cast<float>(c));
		_print_d(static_cast<double>(c));
	}
	else if (_type == INT) {
		int i = atoi(_literals.c_str());
		_print_c(static_cast<char>(i));
		_print_i(i);
		_print_f(static_cast<float>(i));
		_print_d(static_cast<double>(i));
	}
	else if (_type == FLOAT) {
		float f = strtof(_literals.c_str(), NULL);
		_print_c(static_cast<char>(f));
		_print_i(static_cast<int>(f));
		_print_f(f);
		_print_d(static_cast<double>(f));
	}
	else if (_type == DOUBLE) {
		double d = strtod(_literals.c_str(), NULL);
		_print_c(static_cast<char>(d));
		_print_i(static_cast<int>(d));
		_print_f(static_cast<float>(d));
		_print_d(d);
	}
	// else {
	// 	_c = 0;
	// 	_i = 0;
	// 	_f = 0;
	// 	_d = 0;
	// }
}