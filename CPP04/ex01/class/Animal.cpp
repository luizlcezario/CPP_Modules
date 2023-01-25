/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:40:02 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/25 14:18:44 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor called" << std::endl;
	type = "Animal";
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(Animal const &src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &rhs)
{
	std::cout << "Animal assignation operator called" << std::endl;
	this->type = rhs.type;
	return *this;
}

std::string Animal::getType() const
{
	return this->type;
}

void Animal::makeSound() const {
	std::cout << "rowrdddd!\n";
	return ;
}

std::ostream &operator<<(std::ostream &o, Animal const &rhs)
{
	o << rhs.getType();
	return o;
}