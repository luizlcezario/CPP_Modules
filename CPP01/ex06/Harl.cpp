/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:58:25 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/18 14:26:53 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

const std::string Harl::levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR"};

void (Harl::*Harl::complaints[5])(void) = {
	&Harl::debug,
	&Harl::info,
	&Harl::warning,
	&Harl::error,
	&Harl::unknown
};

void Harl::unknown(void) {
	std::cout << "UNKNOWN" << std::endl;
}

void Harl::warning(void) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon"
		<< " for free. I’ve been coming for years whereas you started working "
		<< "here since last month." << std::endl;
}

void Harl::error(void) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the "
		<< "manager now" << std::endl;
}

void Harl::info(void) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more"
		<< " money. You didn’t put enough bacon in my burger! If you did, "
		<< "I wouldn’t be asking for more!" << std::endl;
}

void Harl::debug(void) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my " 
		<< "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
		<< std::endl;
}

void Harl::complain(std::string level) {
	int i;

	i = 0;
	for (; i < 4; i++) {
		if (level.compare(levels[i])) {
			break;
		}
	}
	switch (i) {
		case 0:
			(this->*complaints[0])();
			std::cout << std::endl;
			break;
		case 1:
			(this->*complaints[1])();
			std::cout << std::endl;
			break;
		case 2:
			(this->*complaints[2])();
			std::cout << std::endl;
			break;
		case 3:
			(this->*complaints[3])();
			std::cout << std::endl;
			break;
		default:
			break;
	}
}