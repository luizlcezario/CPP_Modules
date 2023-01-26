/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:23:07 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/26 10:37:35 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "AbstractAnimal.hpp"
#include "Brain.hpp"

class Cat : public AbstractAnimal
{
	public:
		Cat();
		Cat(Cat const &src);
		~Cat();
		Cat &operator=(Cat const &rhs);
		Brain *getBrain(void) const;
		void makeSound() const;
	private:
		Brain *_brain;
};

#endif