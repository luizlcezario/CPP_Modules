/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:42:28 by llima-ce          #+#    #+#             */
/*   Updated: 2022/07/31 16:14:01 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char **argv) {
	Zombie	*zombie = newZombie((string) "llima-ce");
	zombie->announce();
	randomChump("van");
	delete zombie;
	return (0);
}