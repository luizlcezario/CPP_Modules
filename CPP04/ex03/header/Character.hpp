/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:02:46 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/26 13:27:53 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP

# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria;

class Character : public ICharacter
{
	public:
		Character();
		explicit Character(std::string const name);
		Character(Character const &src);
		virtual ~Character();
		
		Character &operator=(Character const &rhs);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

	private:
		std::string _name;
		AMateria *_inventory[4];
};

#endif