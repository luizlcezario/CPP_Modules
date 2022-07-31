/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:49:10 by llima-ce          #+#    #+#             */
/*   Updated: 2022/07/31 16:46:51 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(string name) {
	this->name = name;
}

Zombie::Zombie( void ) {
	this->name = "zombie";
}

Zombie::~Zombie() {
	cout << name << endl;
}

void	Zombie::announce( void ) {
	cout << name << ": BraiiiiiiinnnzzzZ..." << endl;
}

void	Zombie::setName( string name ) {
	this->name = name;
}
