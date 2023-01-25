/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:23:32 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/25 14:15:32 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGNIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		explicit WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal const &src);
		virtual ~WrongAnimal();
		WrongAnimal &operator=(WrongAnimal const &rhs);
		std::string getType() const;
		virtual void makeSound() const;
};

std::ostream &operator<<(std::ostream &o, WrongAnimal const &i);

#endif