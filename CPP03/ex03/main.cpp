/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:10:38 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/24 19:15:34 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

int main(void) {
	DiamondTrap clap1;
	DiamondTrap clap2("Test 1");
	DiamondTrap clap3(clap2);

	clap1.attack("Test 1");
	clap2 = clap1;
	clap2.whoAmI();
	clap2.highFivesGuys();
	return 0;
}