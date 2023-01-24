/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:52:16 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/24 18:45:22 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

typedef enum e_claptrap_types{
	SCAVTRAP = 2,
	CLAPTRAP = 1,
	FRAGTRAP = 3,
	DIAMONDTRAP = 4
}	t_claptrap_types;

class ClapTrap {
public:
	ClapTrap();
	explicit ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &src);
	~ClapTrap();
	ClapTrap	&operator=(const ClapTrap &src);

	t_claptrap_types	getType() const;
	std::string			getName() const;
	int					getHitP() const;
	int					getEnergyP() const;
	int					getAttackD() const;
	void 				setType(t_claptrap_types type);
	void				setName(const std::string &name);
	void				setHitP(int amount);
	void				setEnergyP(int amount);
	void				setAttackD(int amount);
	void	attack(const std::string&target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

private:
	t_claptrap_types	_type;
	std::string const	_name;
	int					_hitPoints;
	int					_energyPoints;
	int					_attackDamage;
};


std::ostream &operator<<(std::ostream &o, ClapTrap const &i);

#endif