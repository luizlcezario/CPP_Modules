/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:13:20 by llima-ce          #+#    #+#             */
/*   Updated: 2022/07/31 18:48:46 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"
#include <iostream>

class HumanB{
	public:
		explicit	HumanB(std::string name);
		void		setWeapon(Weapon &weapon);
		void		attack();

	private:
		std::string		name;
		Weapon			*weapon;
};

#endif