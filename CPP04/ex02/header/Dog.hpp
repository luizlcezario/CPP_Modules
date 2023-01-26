/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:24:15 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/26 10:37:56 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "AbstractAnimal.hpp"
#include "Brain.hpp"

class Dog : public AbstractAnimal
{
	public:
		Dog();
		Dog(Dog const &src);
		~Dog();
		Dog &operator=(Dog const &rhs);
		Brain *getBrain(void) const;
		void makeSound() const;
	private:
		Brain *_brain;
};


#endif