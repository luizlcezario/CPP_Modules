/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:17:10 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/26 14:16:17 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : _type("") {}
AMateria::AMateria(std::string const &type) : _type(type) {}
AMateria::AMateria(AMateria const &src) { *this = src; }
AMateria::~AMateria(void) {}

AMateria &AMateria::operator=(AMateria const &rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return *this;
}

std::string const &AMateria::getType() const { 
	return this->_type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "* default materia cannot be use at " << target.getName() << " *" << std::endl;
}
