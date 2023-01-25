/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:23:32 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/25 14:11:02 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		explicit Animal(std::string type);
		Animal(Animal const &src);
		virtual ~Animal();
		Animal &operator=(Animal const &rhs);
		std::string getType() const;
		virtual void makeSound() const;
};

std::ostream &operator<<(std::ostream &o, Animal const &i);

#endif