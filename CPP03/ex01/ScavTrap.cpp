/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:33:33 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/24 14:58:44 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap Default constructor called" << std::endl;
	this->setName("ScavTrap");
	this->setHitP(100);
	this->setEnergyP(50);
	this->setAttackD(20);
	this->setType(SCAVTRAP);
	_isGateKeeper = false;
}

ScavTrap::ScavTrap(std::string name) {
	std::cout << "ScavTrap Name constructor called" << std::endl;
	this->setName(name);
	this->setHitP(100);
	this->setEnergyP(50);
	this->setAttackD(20);
	this->setType(SCAVTRAP);
	_isGateKeeper = false;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap() {
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & src) {
	std::cout << "ScavTrap Assignation operator called" << std::endl;
	if (this != &src) {
		this->setName(src.getName());
		this->setHitP(src.getHitP());
		this->setEnergyP(src.getEnergyP());
		this->setAttackD(src.getAttackD());
		this->setType(src.getType());
	}
	return *this;
}

void ScavTrap::guardGate() const {
	if (_isGateKeeper && this->getHitP() > 0) {
		std::cout << "ScavTrap is now entered in Gate keeper mode" << std::endl;
	}
	else if (!_isGateKeeper && this->getHitP() > 0) {
		std::cout << "ScavTrap is now exited from Gate keeper mode" << std::endl;
	}
	else {
		std::cout << "ScavTrap is dead!" << std::endl;
	}

}