/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:10:38 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/24 14:54:15 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

int main(void) {
	ScavTrap clap;
	ScavTrap clap1("Test 1");
	ScavTrap clap3("Test 2");
	ScavTrap clap2(clap3);

	clap3 = clap1;
	clap3.guardGate();
	clap1.guardGate();
	return 0;
}