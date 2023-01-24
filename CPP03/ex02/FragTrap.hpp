/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:29:23 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/24 12:25:29 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		explicit FragTrap(std::string const name);
		FragTrap(FragTrap const & src);
		~FragTrap();
		
		FragTrap & operator=(FragTrap const & rhs);
		
		void highFivesGuys(void) const;
};

#endif