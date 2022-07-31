/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:18:42 by llima-ce          #+#    #+#             */
/*   Updated: 2022/07/31 18:52:34 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string nType) : type(nType) {
	return ;
}

const std::string&	Weapon::getType() {
	return (this->type);
}

void				Weapon::setType(std::string type) {
	this->type = type;
}
