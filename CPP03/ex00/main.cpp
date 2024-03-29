/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:10:38 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/24 14:51:32 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main(void) {
	ClapTrap clap1;
	ClapTrap clap2("ClapTrap");
	ClapTrap clap3("ClapTrap2");
	ClapTrap clap4(clap2);

	clap2.attack("ClapTrap");
	clap1.attack("ClapTrap2");
	clap3 = clap4;
	clap3.attack("ClapTrap");
	return 0;
}