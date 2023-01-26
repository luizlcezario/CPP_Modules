/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:10:31 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/26 11:22:36 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP


# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(MateriaSource const &src);
	
	MateriaSource &operator=(MateriaSource const &rhs);
	
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
protected:
	AMateria* _materia[4];
};



#endif