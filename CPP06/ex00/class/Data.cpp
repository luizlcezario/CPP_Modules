/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:30:24 by llima-ce          #+#    #+#             */
/*   Updated: 2023/02/27 18:08:19 by llima-ce         ###   ########.fr       */
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
		this->_c = rhs.getC();
		this->_i = rhs.getI();
		this->_f = rhs.getF();
		this->_d = rhs.getD();
	}
	return *this;
}

string Data::getLiterals() const {
	return this->_literals;
}

e_type Data::getType() const {
	return this->_type;
}

char Data::getC() const {
	return this->_c;
}

int Data::getI() const {
	return this->_i;
}

float Data::getF() const {
	return this->_f;
}

double Data::getD() const {
	return this->_d;
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
	if (literals.length() == 3 && literals[0] == '\'' && literals[2] == '\'')
		return CHAR;
	for (string::iterator it=literals.begin(); it != literals.end(); ++it) {
		if (!isdigit(*it))
		{
			isNumeric[0] = false;
			if ((*it == '.'|| *it == 'f' ))
			{
				if (*it == '.' && wasPoint == false) 
					wasPoint = true;
				else if (*it == 'f' && wasPoint == true && wasF == false) {
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

void	Data::_convertType() {
	if (this->_type == CHAR)
		this->_c = this->_literals[1];
	// else if (this->_type == INT)
	// 	this->_i = std::stoi(this->_literals);
	// else if (this->_type == FLOAT)
	// 	this->_f = std::stof(this->_literals);
	// else if (this->_type == DOUBLE)
	// 	this->_d = std::stod(this->_literals);
	
}

std::ostream &operator<<(std::ostream &o, Data const &rhs) {
	char c = rhs.getC();
	o << "char: " << (std::isprint(c) ? &c : "Non displayable") << std::endl;
	o << "int: " << rhs.getI() << std::endl;
	o << "float: " << rhs.getF() << std::endl;
	o << "double: " << rhs.getD() << std::endl;
	return o;
}