/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:23:47 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/26 14:27:54 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("Guts") {
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string const name) : _name(name) {
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(Character const &src) { *this = src; }

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
}

Character &Character::operator=(Character const &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++) {
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
			if (rhs._inventory[i] != NULL)
				this->_inventory[i] = rhs._inventory[i]->clone();
		}
		this->_name = rhs.getName();
	}
	return *this;
}

std::string const &Character::getName() const { return this->_name; }

void Character::equip(AMateria *m)
{
	int i;

	for (i = 0;i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			std::cout << "Materia of " << m->getType() << " was equipped on slot " << i << std::endl;
			break;
		}
	}
	if (i == 4)
		std::cout << "Inventory is full" << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
		std::cout << "Invalid slot" << std::endl;
	else if (this->_inventory[idx] == NULL)
		std::cout << "Slot is empty" << std::endl;
	else
	{
		std::cout << "Materia of "<< this->_inventory[idx]->getType() <<" unequipped from slot " << idx << std::endl;
		this->_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3)
		std::cout << "Invalid slot" << std::endl;
	else if (this->_inventory[idx] == NULL) {
		std::cout << "nothing to use in this slot on" << target.getName() << std::endl;
	}
	else
		this->_inventory[idx]->use(target);
}
