/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:30:24 by llima-ce          #+#    #+#             */
/*   Updated: 2023/03/08 15:57:39 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : _literals(""), _type(CHAR), _c(0), _i(0), _f(0), _d(0) {}

Data::Data(string literals) : _literals(literals) {
	_type = findType(literals);
	_convertType();
}

Data::Data(Data const &src) {
	*this = src;
}

Data::~Data() {}

Data &Data::operator=(Data const &rhs) {
	if (this != &rhs) {
		this->_literals = rhs.getLiterals();
		this->_type = rhs.getType();
		this->_c = char(rhs);
		this->_i = int(rhs);
		this->_f = float(rhs);
		this->_d = double(rhs);
	}
	return *this;
}

string Data::getLiterals() const {
	return this->_literals;
}

e_type Data::getType() const {
	return this->_type;
}


void Data::setLiterals(string literals) {
	this->_literals = literals;
	this->_type = findType(literals);
	_convertType();
}

e_type	Data::findType(string literals) {
	bool isNumeric[3] = {true, true, true};
	bool wasPoint = false;
	bool wasF = false;

	if (literals.length() == 0)
		return INV;
	if (!literals.compare("nan") || !literals.compare("+inf") || !literals.compare("-inf"))
		return DOUBLE;
	if (!literals.compare("nanf") || !literals.compare("+inff") || !literals.compare("-inff"))
		return FLOAT;
	else if (literals.length() == 3 && literals[0] == '\'' && literals[2] == '\'')
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

operator Data::char()  {
	if (this->_type == INT)
		return static_cast<char>(this->_i);
	else if (this->_type == FLOAT)
		return static_cast<char>(this->_f);
	else if (this->_type == DOUBLE)
		return static_cast<char>(this->_d);
	else
		return this->_c;
}

operator Data::int() {
	if (this->_type == CHAR)
		return static_cast<int>(this->_c);
	else if (this->_type == FLOAT)
		return static_cast<int>(this->_f);
	else if (this->_type == DOUBLE)
		return static_cast<int>(this->_d);
	else
		return this->_i;
}

operator Data::float() {
	if (this->_type == CHAR)
		return static_cast<float>(this->_c);
	else if (this->_type == INT)
		return static_cast<float>(this->_i);
	else if (this->_type == DOUBLE)
		return static_cast<float>(this->_d);
	else
		return this->_f;
}

operator Data::double() const {
	if (this->_type == CHAR)
		return static_cast<double>(this->_c);
	else if (this->_type == FLOAT)
		return static_cast<double>(this->_f);
	else if (this->_type == Int)
		return static_cast<double>(this->_i);
	else
		return this->_d;
}

void Data::printData() {
	
}

std::ostream &operator<<(std::ostream &o, Data const &rhs) {
	char c = char(rhs);
	o << "char: " << (std::isprint(c) ? &c : "Non displayable") << std::endl;
	// o << "int: " << rhs.getI() << std::endl;
	// o << "float: " << rhs.getF() << std::endl;
	// o << "double: " << rhs.getD() << std::endl;
	return o;
}