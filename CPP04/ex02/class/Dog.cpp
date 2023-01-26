/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:01:30 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/26 10:39:26 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AbstractAnimal("Dog"){
	std::cout << "Dog constructor called" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(Dog const &src) : AbstractAnimal("Dog") {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

Dog &Dog::operator=(Dog const &rhs) {
	std::cout << "Dog assignation operator called" << std::endl;
	this->_brain = new Brain(*rhs._brain);
	this->type = rhs.type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Au Au!" << std::endl;
}

Brain *Dog::getBrain() const {
	return this->_brain;
}
