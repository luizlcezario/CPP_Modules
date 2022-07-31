/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:04:59 by llima-ce          #+#    #+#             */
/*   Updated: 2022/07/31 16:47:55 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, string name ) {
	Zombie	*horde = new Zombie[N];
	if (horde == nullptr)
		cout << "Error: memory could not be allocated";
	for(int i = 0; i < N; i++) {
		horde[i].setName(name);
	}
	return (horde);
}