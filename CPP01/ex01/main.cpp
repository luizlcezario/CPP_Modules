/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:42:28 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/18 14:35:22 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	Zombie	*horde = zombieHorde(10, (string) "van");
	for (int i = 0; i < 10; i++) {
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}