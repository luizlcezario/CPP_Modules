/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:06:55 by llima-ce          #+#    #+#             */
/*   Updated: 2022/08/01 22:07:39 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void) {
	Harl harl;
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("INFO");
	harl.complain("DEBUG");
	harl.complain("unknown");
	return 0;
}