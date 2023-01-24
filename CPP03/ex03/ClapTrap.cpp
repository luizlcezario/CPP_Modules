/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:47:05 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/24 12:11:55 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _type(CLAPTRAP), _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) :  _type(CLAPTRAP), _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src) {
	std::cout << "ClapTrap assignation operator called" << std::endl;
	if (this != &src) {
		const_cast<std::string &>(this->_name) = src.getName();
		this->_hitPoints = src.getHitP();
		this->_energyPoints = src.getEnergyP();
		this->_attackDamage = src.getAttackD();
		this->_type = src.getType();
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << std::endl;
}

std::string ClapTrap::getName() const {
	return _name;
}

int ClapTrap::getHitP() const {
	return _hitPoints;
}

int ClapTrap::getEnergyP() const {
	return _energyPoints;
}

int ClapTrap::getAttackD() const {
	return _attackDamage;
}

t_claptrap_types ClapTrap::getType() const {
	return _type;
}

void ClapTrap::setHitP(int amount) {
	this->_hitPoints = amount;
}

void ClapTrap::setEnergyP(int amount) {
	this->_energyPoints = amount;
}

void ClapTrap::setAttackD(int amount) {
	this->_attackDamage = amount;
}

void ClapTrap::setName(const std::string &name) {
	const_cast<std::string &>(this->_name) = name;
}

void ClapTrap::setType(t_claptrap_types type) {
	this->_type = type;
}

void ClapTrap::attack(const std::string &target) {
	if (_energyPoints > 0 && _hitPoints > 0) {
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	} else if (_energyPoints < 0) {
		std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
	} else {
		std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
		_hitPoints -= amount;
	}
	else {
		std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints > 0 && _energyPoints > 0) {
		std::cout << "ClapTrap " << _name << " is repaired by " << amount << " points!" << std::endl;
		_hitPoints += amount;
		_energyPoints--;
	} else if (_energyPoints < 0) {
		std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
	} else if (_hitPoints < 0) {
		std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const ClapTrap &clap) {
	out << "Name: " << clap.getName() << "\n";
	out << "HP: " << clap.getHitP() << "\n";
	out << "EP: " << clap.getEnergyP() << "\n";
	out << "AD: " << clap.getAttackD() << "\n";
	return out;
}
