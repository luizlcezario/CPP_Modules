/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:42:28 by llima-ce          #+#    #+#             */
/*   Updated: 2022/07/31 16:49:51 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char **argv) {
	Zombie	*horde = zombieHorde(10, (string) "van");
	for (int i = 0; i < 10; i++) {
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}