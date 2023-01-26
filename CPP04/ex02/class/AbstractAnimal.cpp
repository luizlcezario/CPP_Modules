/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractAnimal.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:40:02 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/26 10:49:08 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractAnimal.hpp"

AbstractAnimal::AbstractAnimal()
{
	std::cout << "Animal constructor called" << std::endl;
	type = "Animal";
}

AbstractAnimal::AbstractAnimal(std::string type) : type(type)
{
	std::cout << "Animal constructor called" << std::endl;
}

AbstractAnimal::AbstractAnimal(AbstractAnimal const &src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

AbstractAnimal::~AbstractAnimal()
{
	std::cout << "Animal destructor called" << std::endl;
}

AbstractAnimal &AbstractAnimal::operator=(AbstractAnimal const &rhs)
{
	std::cout << "Animal assignation operator called" << std::endl;
	this->type = rhs.type;
	return *this;
}

std::string AbstractAnimal::getType() const
{
	return this->type;
}

std::ostream &operator<<(std::ostream &o, AbstractAnimal const &rhs)
{
	o << rhs.getType();
	return o;
}