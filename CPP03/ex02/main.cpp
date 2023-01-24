/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:10:38 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/24 12:25:51 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	FragTrap clap1;
	FragTrap clap2("Test 1");
	FragTrap clap3(clap2);

	return 0;
}