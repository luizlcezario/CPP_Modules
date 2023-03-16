/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:20:00 by llima-ce          #+#    #+#             */
/*   Updated: 2023/03/12 13:57:43 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap(), ScavTrap(), FragTrap(), _name("DiamondTrap") {
	std::cout << "DiamondTrap Default constructor called" << std::endl;
	this->setName("DiamondTrap_clap_name");
	this->setHitP(100);
	this->setEnergyP(50);
	this->setAttackD(30);
	this->setType(DIAMONDTRAP);
	return ;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(), ScavTrap(), FragTrap() , _name(name) {
	std::cout << "DiamondTrap " << name << " constructor called" << std::endl;
	this->setName(name + "_clap_name");
	this->setHitP(100);
	this->setEnergyP(50);
	this->setAttackD(30);
	this->setType(DIAMONDTRAP);
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap(), ScavTrap(), FragTrap() {
	std::cout << "DiamondTrap copy constructor called\n";
	*this = src;
	return;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->getName() << " Destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const & src) {
	std::cout << "DiamondTrap " << src.getName() <<" Assignation to "<< this->getName() << std::endl;
	if (this != &src) {
		const_cast<std::string &> (this->_name) = src.getPreName();
		this->setName(src.getName());
		this->setHitP(src.getHitP());
		this->setEnergyP(src.getEnergyP());
		this->setAttackD(src.getAttackD());
		this->setType(src.getType());
	}
	return *this;
}

std::string DiamondTrap::getPreName(void) const {
	return this->_name;
}

void DiamondTrap::attack(std::string const & target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
	std::cout << "DiamondTrap " << this->getName() << " is " << this->getPreName() << std::endl;
}
