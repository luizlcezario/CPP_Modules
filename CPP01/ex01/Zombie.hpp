/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:49:15 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/18 14:35:13 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# define nullptr 0
# include <iostream>

using std::string;
using std::cout;
using std::endl;

class Zombie{
	private:
		string	name;
	public:
		Zombie( void );
		Zombie(string name);
		~Zombie();
		void	announce( void );
		void	setName( string name );
};

Zombie*	zombieHorde( int N, string name );

#endif