/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:36:50 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/26 13:33:15 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &src) { *this = src; }

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (this->_materia[i] != NULL)
			delete this->_materia[i];
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++) {
			delete this->_materia[i];
			this->_materia[i] = NULL;
			if (rhs._materia[i] != NULL)
				this->_materia[i] = rhs._materia[i]->clone();
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* materia) {
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] == NULL)
		{
			this->_materia[i] = materia;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] != NULL && this->_materia[i]->getType() == type)
			return this->_materia[i]->clone();
	}
	return NULL;
}