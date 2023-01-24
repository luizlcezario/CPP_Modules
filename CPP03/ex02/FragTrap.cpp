/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:33:33 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/24 15:03:34 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap Default constructor called" << std::endl;
	this->setName("FragTrap");
	this->setHitP(100);
	this->setEnergyP(50);
	this->setAttackD(20);
	this->setType(FRAGTRAP);
}

FragTrap::FragTrap(std::string name) {
	std::cout << "FragTrap " << name << " constructor called" << std::endl;
	this->setName(name);
	this->setHitP(100);
	this->setEnergyP(50);
	this->setAttackD(20);
	this->setType(FRAGTRAP);
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap() {
  std::cout << "FragTrap copy constructor called\n";
  *this = src;
  return;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->getName() << " Destructor called" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & src) {
	std::cout << "FragTrap " << src.getName() <<" Assignation to "<< this->getName() << std::endl;
	if (this != &src) {
		this->setName(src.getName());
		this->setHitP(src.getHitP());
		this->setEnergyP(src.getEnergyP());
		this->setAttackD(src.getAttackD());
		this->setType(src.getType());
	}
	return *this;
}

void FragTrap::highFivesGuys() const {
	if (this->getHitP() > 0) {
		std::cout << "FragTrap " << this->getName() << " says HighFive!!"
			<< std::endl;
	}
	else {
		std::cout << "FragTrap " << this->getName() << " is dead!" << std::endl;
	}

}