/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractAnimal.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:23:32 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/26 10:49:15 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTANIMAL_HPP
# define ABSTRACTANIMAL_HPP

#include <iostream>
#include <string>

class AbstractAnimal
{
	protected:
		std::string type;
	public:
		AbstractAnimal();
		explicit AbstractAnimal(std::string type);
		AbstractAnimal(AbstractAnimal const &src);
		virtual ~AbstractAnimal();
		AbstractAnimal &operator=(AbstractAnimal const &rhs);
		std::string getType() const;
		virtual void makeSound() const = 0;
};

std::ostream &operator<<(std::ostream &o, AbstractAnimal const &i);

#endif