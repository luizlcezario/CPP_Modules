/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 22:21:05 by llima-ce          #+#    #+#             */
/*   Updated: 2023/03/15 22:22:05 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data()
{
}

Data::Data(std::string name, int len, int height)
{
	this->_name = name;
	this->_len = len;
	this->_height = height;
}

Data::~Data()
{
}

Data::Data(Data const &src)
{
	*this = src;
}

Data &Data::operator=(Data const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_len = rhs._len;
		this->_height = rhs._height;
	}
	return (*this);
}

std::string Data::getName()
{
	return (this->_name);
}

int Data::getLen()
{
	return (this->_len);
}

int Data::getHeight()
{
	return (this->_height);
}

void Data::setLen(int len)
{
	this->_len = len;
}

void Data::setHeight(int height)
{
	this->_height = height;
}

void Data::setName(std::string name)
{
	this->_name = name;
}

double Data::calcIMC()
{
	return (this->_len / (this->_height * this->_height));
}
