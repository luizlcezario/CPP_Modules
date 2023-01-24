/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:29:23 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/24 11:53:57 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		explicit ScavTrap(std::string const name);
		ScavTrap(ScavTrap const & src);
		~ScavTrap();
		
		ScavTrap & operator=(ScavTrap const & rhs);
		
		void guardGate() const;
	private:
		bool _isGateKeeper;
};

#endif