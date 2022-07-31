/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:20:13 by llima-ce          #+#    #+#             */
/*   Updated: 2022/07/31 18:53:59 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {
	return ;
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}

void	HumanB::attack() {
	std::cout << this->name << " attacks with their " 
		<< this->weapon->getType() << std::endl;
}
