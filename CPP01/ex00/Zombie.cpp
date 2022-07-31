/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:49:10 by llima-ce          #+#    #+#             */
/*   Updated: 2022/07/31 16:10:23 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(string name) {
	this->name = name;
}

Zombie::~Zombie() {
	cout << name << endl;
}

void	Zombie::announce( void ) {
	cout << name << ": BraiiiiiiinnnzzzZ..." << endl;
}
