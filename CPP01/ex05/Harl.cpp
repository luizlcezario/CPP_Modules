/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:58:25 by llima-ce          #+#    #+#             */
/*   Updated: 2022/08/01 22:25:07 by llima-ce         ###   ########.fr       */
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
	std::cout << "Warning: " << "I think I deserve to have some extra bacon"
		<< " for free. I’ve been coming for years whereas you started working "
		<< "here since last month." << std::endl;
}

void Harl::error(void) {
	std::cout << "Error: This is unacceptable! I want to speak to the "
		<< "manager now" << std::endl;
}

void Harl::info(void) {
	std::cout << "Info: "<< "I cannot believe adding extra bacon costs more"
		<< " money. You didn’t put enough bacon in my burger! If you did, "
		<< "I wouldn’t be asking for more!" << std::endl;
}

void Harl::debug(void) {
	std::cout << "Debug: " << "I love having extra bacon for my " 
		<< "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
		<< std::endl;
}

void Harl::complain(std::string level) {
	for (int i = 0; i < 4; i++) {
		if (level == levels[i]) {
			(this->*complaints[i])();
			return;
		}
	}
	(this->*complaints[4])();
}