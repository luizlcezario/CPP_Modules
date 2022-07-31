/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:10:34 by llima-ce          #+#    #+#             */
/*   Updated: 2022/07/31 18:23:29 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP 
#define WEAPON_HPP

#include <string>

class Weapon {
	private:
		std::string			type;
	public:
		Weapon(std::string type);
		const std::string&	getType();
		void				setType(std::string type);
};

#endif