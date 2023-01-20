/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:10:38 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/20 18:22:03 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main(void) {
	ClapTrap clap1;
	ClapTrap clap2("ClapTrap");
	ClapTrap clap3("ClapTrap2");

	clap1.attack("ClapTrap2");
	clap2.attack("ClapTrap");
	return 0;
}